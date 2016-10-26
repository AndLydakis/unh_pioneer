# unh_pioneer

ROS stack for the lab's P3DXs.

Things to do before you use it:

    Install rosaria following these instructions
    http://wiki.ros.org/ROSARIA/Tutorials/How%20to%20use%20ROSARIA

    sudo apt-get install ros-indigo-navigation
    
    sudo apt-get install ros-indigo-joy*
    
    sudo apt-get install ros-indigo-turtlebot*
    
    download and install openni2 from https://github.com/ros-drivers/openni2_launch
    
    If you want to use AR tags download and istall
    https://github.com/sniekum/ar_track_alvar_msgs
    https://github.com/sniekum/ar_track_alvar
    
    
Launch files:

drive.launch

    Starts drives, remote conrol, laser and camera nodes.
    
mapping.launch

    same as drive.launch and also the mapping node
    
navigation-pioneer3dx.launch

     drive.launch plus navigation node
