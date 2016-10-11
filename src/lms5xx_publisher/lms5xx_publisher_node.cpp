#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/LaserScan.h>
#include <tf/transform_listener.h>
#include "Aria/ArTcpConnection.h"
#include "Aria/ArLMS1XX.h"
#include "Aria/ArLaserFilter.h"

int main(int argc, char** argv) {

	ros::init(argc, argv, "SickLMS5xx_Laser");
	ros::NodeHandle node;
	ros::Publisher publisher = node.advertise<sensor_msgs::LaserScan>
		("lms5xx_scan", 1000);
	tf::TransformListener listener;

	/* Aria Setup */
	ArTcpConnection connection;
	connection.setPort("192.168.0.1", 2111);

	ArLMS1XX laser(1, "lms5xx", true);
	laser.setDeviceConnection(&connection);
	laser.setSensorPosition(21,0,0,0); //from p3dx.sh-lms500.p

	if(!laser.blockingConnect()) {
		printf("could not connect to laser\n");
		if(connection.getStatus() == ArDeviceConnection::STATUS_OPEN)
			connection.close();
		return 1;
	}

	sensor_msgs::LaserScan scan;
	scan.header.frame_id = "/base_laser";
	ArPose origin(0,0,0);

	scan.scan_time = 0;
	scan.angle_min = -(190./360.)*M_PI;
	scan.angle_max = -scan.angle_min;
	scan.angle_increment = (1./180.)*M_PI;
	scan.range_min = 0;
	laser.lockDevice();
	{
		scan.range_max = (float)laser.getAbsoluteMaxRange() / 1000.;
	}
	laser.unlockDevice();
	while(node.ok()) {
		scan.ranges.clear();
		scan.intensities.clear();
		laser.lockDevice();
		{
			ArRangeBuffer* buffer = laser.getCurrentRangeBuffer();
			buffer->beginInvalidationSweep();
			{
				std::list<ArPoseWithTime*>* bufList = buffer->getBuffer();
				std::list<ArPoseWithTime*>::iterator it = bufList->begin();
       				scan.header.stamp = ros::Time::now()-
					ros::Duration(((*it)->getTime().mSecTo() / 1000.));
//                    scan.header.stamp = ros::Time::now();

				scan.ranges.resize(bufList->size());
				for(int i = bufList->size()-1; it != bufList->end(); it++, i--) {
					ArPoseWithTime* pose = *it;

					scan.ranges[i] = pose->findDistanceTo(origin)/1000.;
//					scan.intensities.push_back(0);
					buffer->invalidateReading(it);
				}
			}
			buffer->endInvalidationSweep();
			laser.clearCumulativeReadings();
			laser.clearCurrentReadings();
		}
		laser.unlockDevice();

		if(scan.ranges.size() == 0) continue;
		try {
			listener.waitForTransform("/base_laser", "/base_link",
				scan.header.stamp, ros::Duration(0.05));
		}catch(int e){}
			publisher.publish(scan);

	}

	laser.disconnect();
	connection.close();
	return 0;
}
