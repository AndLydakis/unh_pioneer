/*
MobileRobots Advanced Robotics Interface for Applications (ARIA)
Copyright (C) 2004, 2005 ActivMedia Robotics LLC
Copyright (C) 2006, 2007, 2008, 2009, 2010 MobileRobots Inc.
Copyright (C) 2011, 2012 Adept Technology

     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program; if not, write to the Free Software
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

If you wish to redistribute ARIA under different terms, contact 
MobileRobots for information about a commercial version of ARIA at 
robots@mobilerobots.com or 
MobileRobots Inc, 10 Columbia Drive, Amherst, NH 03031; 800-639-9481
*/
#ifndef ARS3SERIES_H
#define ARS3SERIES_H

#include "ariaTypedefs.h"
#include "ariaOSDef.h"
#include "ArRobotPacket.h"
#include "ArLaser.h"   
#include "ArFunctor.h"

/** @internal */
class ArS3SeriesPacket : public ArBasePacket
{
public:
  /// Constructor
  AREXPORT ArS3SeriesPacket();
  /// Destructor
  AREXPORT virtual ~ArS3SeriesPacket();
  
  /// Gets the time the packet was received at
  AREXPORT ArTime getTimeReceived(void);
  /// Sets the time the packet was received at
  AREXPORT void setTimeReceived(ArTime timeReceived);

  AREXPORT virtual void duplicatePacket(ArS3SeriesPacket *packet);
  AREXPORT virtual void empty(void);
  

  void setDataLength(int x)
  { myDataLength = x; }
  ArTypes::UByte2 getDataLength()
  { return myDataLength; }
  void setNumReadings(int x)
  { myNumReadings = x; }
  int getNumReadings()
  { return myNumReadings; }
  void setStatusByte(unsigned char c)
  { myStatusByte = c; }
  unsigned char getStatusByte()
  { return myStatusByte; }
  void setTimeStampByte1(unsigned char c)
  { myTimeStampByte1 = c; }
  unsigned char getTimeStampByte1()
  { return myTimeStampByte1; }
  void setTimeStampByte2(unsigned char c)
  { myTimeStampByte2 = c; }
  unsigned char getTimeStampByte2()
  { return myTimeStampByte2; }
  void setTimeStampByte3(unsigned char c)
  { myTimeStampByte3 = c; }
  unsigned char getTimeStampByte3()
  { return myTimeStampByte3; }
  void setTimeStampByte4(unsigned char c)
  { myTimeStampByte4 = c; }
  unsigned char getTimeStampByte4()
  { return myTimeStampByte4; }
  unsigned char getTelegramNumByte1()
  { return myTelegramNumByte1; }
  unsigned char getTelegramNumByte2()
  { return myTelegramNumByte2; }
  void setTelegramNumByte2(unsigned char c)
  { myTelegramNumByte2 = c; }
  void setTelegramNumByte1(unsigned char c)
  { myTelegramNumByte1 = c; }
  unsigned char getCrcByte1()
  { return myCrcByte1; }
  void setCrcByte1(unsigned char c)
  { myCrcByte1 = c; }
  unsigned char getCrcByte2()
  { return myCrcByte2; }
  void setCrcByte2(unsigned char c)
  { myCrcByte2 = c; }

protected:

  ArTime myTimeReceived;

  // S3S specific
  int myDataLength;
  int myNumReadings;
  unsigned char myStatusByte;
  unsigned char myTimeStampByte1;
  unsigned char myTimeStampByte2;
  unsigned char myTimeStampByte3;
  unsigned char myTimeStampByte4;
  unsigned char myTelegramNumByte1;
  unsigned char myTelegramNumByte2;
  unsigned char myCrcByte1;
  unsigned char myCrcByte2;

};


/// Given a device connection it receives packets from the sick through it
/// @internal
class ArS3SeriesPacketReceiver
{
public:
  /// Constructor with assignment of a device connection
  AREXPORT ArS3SeriesPacketReceiver();
  /// Destructor
  AREXPORT virtual ~ArS3SeriesPacketReceiver();
  
  /// Receives a packet from the robot if there is one available
  AREXPORT ArS3SeriesPacket *receivePacket(unsigned int msWait = 0,
					 bool shortcut = false);

  /// Sets the device this instance receives packets from
  AREXPORT void setDeviceConnection(ArDeviceConnection *conn);
  /// Gets the device this instance receives packets from
  AREXPORT ArDeviceConnection *getDeviceConnection(void);
  unsigned short CRC16(unsigned char *, int);

  // PS - added to pass info to this class
  AREXPORT void	setmyInfoLogLevel(ArLog::LogLevel infoLogLevel)
  { myInfoLogLevel = infoLogLevel; }
  AREXPORT void setmyIsS300(bool isS300)
  { myIsS300 = isS300; }
  AREXPORT void setmyName(const char *name )
  { strcpy(myName, name); }

protected:
  ArDeviceConnection *myConn;
  ArS3SeriesPacket myPacket;
  
  char myName[1024];
  unsigned int myNameLength;
  unsigned char myReadBuf[100000];
  int myReadCount;
  bool myIsS300;
  ArLog::LogLevel myInfoLogLevel;



};

/**
  @since Aria 2.7.4
  @see ArLaserConnector
  Use ArLaserConnector to connect to a laser, determining type based on robot and program configuration  parameters.
*/
class ArS3Series : public ArLaser
{
public:
  /// Constructor
  AREXPORT ArS3Series(int laserNumber,
		 const char *name = "S3Series");
  /// Destructor
  AREXPORT ~ArS3Series();
  AREXPORT virtual bool blockingConnect(void);
  AREXPORT virtual bool asyncConnect(void);
  AREXPORT virtual bool disconnect(void);
  virtual bool isConnected(void) { return myIsConnected; }
  virtual bool isTryingToConnect(void) 
    { 
      if (myStartConnect)
	return true;
      else if (myTryingToConnect)
	return true; 
      else
	return false;
    }  

  /// Logs the information about the sensor
  AREXPORT void log(void);
protected:
  AREXPORT virtual void laserSetName(const char *name);
  AREXPORT virtual void * runThread(void *arg);
  AREXPORT virtual void setRobot(ArRobot *robot);
  void sensorInterp(void);
  void failedToConnect(void);
  void clear(void);
  bool myIsConnected;
  bool myTryingToConnect;
  bool myStartConnect;

  int myNumChans;


  ArLog::LogLevel myLogLevel;

  ArS3SeriesPacketReceiver myReceiver;

  ArMutex myPacketsMutex;
  ArMutex myDataMutex;

  std::list<ArS3SeriesPacket *> myPackets;

  ArFunctorC<ArS3Series> mySensorInterpTask;
  ArRetFunctorC<bool, ArS3Series> myAriaExitCB;
};

#endif 
