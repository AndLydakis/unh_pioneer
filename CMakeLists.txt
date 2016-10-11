cmake_minimum_required(VERSION 2.8.3)
project(unh_pioneer)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED
  roscpp
  sensor_msgs
  tf
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES lms5xx_publisher
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)

## Declare a cpp library
# add_library(lms5xx_publisher
#   src/${PROJECT_NAME}/lms5xx_publisher.cpp
# )
add_library(Aria_OLD
  src/lms5xx_publisher/Aria/ArActionAvoidFront.cpp
  src/lms5xx_publisher/Aria/ArActionAvoidSide.cpp
  src/lms5xx_publisher/Aria/ArActionBumpers.cpp
  src/lms5xx_publisher/Aria/ArActionColorFollow.cpp
  src/lms5xx_publisher/Aria/ArActionConstantVelocity.cpp
  src/lms5xx_publisher/Aria/ArAction.cpp
  src/lms5xx_publisher/Aria/ArActionDeceleratingLimiter.cpp
  src/lms5xx_publisher/Aria/ArActionDesired.cpp
  src/lms5xx_publisher/Aria/ArActionDriveDistance.cpp
  src/lms5xx_publisher/Aria/ArActionGoto.cpp
  src/lms5xx_publisher/Aria/ArActionGotoStraight.cpp
  src/lms5xx_publisher/Aria/ArActionGroup.cpp
  src/lms5xx_publisher/Aria/ArActionGroups.cpp
  src/lms5xx_publisher/Aria/ArActionInput.cpp
  src/lms5xx_publisher/Aria/ArActionIRs.cpp
  src/lms5xx_publisher/Aria/ArActionJoydrive.cpp
  src/lms5xx_publisher/Aria/ArActionKeydrive.cpp
  src/lms5xx_publisher/Aria/ArActionLimiterBackwards.cpp
  src/lms5xx_publisher/Aria/ArActionLimiterForwards.cpp
  src/lms5xx_publisher/Aria/ArActionLimiterTableSensor.cpp
  src/lms5xx_publisher/Aria/ArActionMovementParameters.cpp
  src/lms5xx_publisher/Aria/ArActionRatioInput.cpp
  src/lms5xx_publisher/Aria/ArActionRobotJoydrive.cpp
  src/lms5xx_publisher/Aria/ArActionStallRecover.cpp
  src/lms5xx_publisher/Aria/ArActionStop.cpp
  src/lms5xx_publisher/Aria/ArActionTriangleDriveTo.cpp
  src/lms5xx_publisher/Aria/ArActionTurn.cpp
  src/lms5xx_publisher/Aria/ArACTS.cpp
  src/lms5xx_publisher/Aria/ArAMPTU.cpp
  src/lms5xx_publisher/Aria/ArAnalogGyro.cpp
  src/lms5xx_publisher/Aria/ArArg.cpp
  src/lms5xx_publisher/Aria/ArArgumentBuilder.cpp
  src/lms5xx_publisher/Aria/ArArgumentParser.cpp
  src/lms5xx_publisher/Aria/ArASyncTask.cpp
  src/lms5xx_publisher/Aria/ArBasePacket.cpp
  src/lms5xx_publisher/Aria/ArBumpers.cpp
  src/lms5xx_publisher/Aria/ArCameraCollection.cpp
  src/lms5xx_publisher/Aria/ArCameraCommands.cpp
  src/lms5xx_publisher/Aria/ArCondition_LIN.cpp
  src/lms5xx_publisher/Aria/ArConfigArg.cpp
  src/lms5xx_publisher/Aria/ArConfig.cpp
  src/lms5xx_publisher/Aria/ArConfigGroup.cpp
  src/lms5xx_publisher/Aria/ArDataLogger.cpp
  src/lms5xx_publisher/Aria/ArDeviceConnection.cpp
  src/lms5xx_publisher/Aria/ArDPPTU.cpp
  src/lms5xx_publisher/Aria/ArFileParser.cpp
  src/lms5xx_publisher/Aria/ArForbiddenRangeDevice.cpp
  src/lms5xx_publisher/Aria/ArFunctorASyncTask.cpp
  src/lms5xx_publisher/Aria/ArGPSConnector.cpp
  src/lms5xx_publisher/Aria/ArGPSCoords.cpp
  src/lms5xx_publisher/Aria/ArGPS.cpp
  src/lms5xx_publisher/Aria/ArGripper.cpp
  src/lms5xx_publisher/Aria/Aria.cpp
  src/lms5xx_publisher/Aria/ariaUtil.cpp
  src/lms5xx_publisher/Aria/ArInterpolation.cpp
  src/lms5xx_publisher/Aria/ArIrrfDevice.cpp
  src/lms5xx_publisher/Aria/ArIRs.cpp
  src/lms5xx_publisher/Aria/ArJoyHandler.cpp
  src/lms5xx_publisher/Aria/ArJoyHandler_LIN.cpp
  src/lms5xx_publisher/Aria/ArKeyHandler.cpp
  src/lms5xx_publisher/Aria/ArLaserConnector.cpp
  src/lms5xx_publisher/Aria/ArLaser.cpp
  src/lms5xx_publisher/Aria/ArLaserFilter.cpp
  src/lms5xx_publisher/Aria/ArLaserLogger.cpp
  src/lms5xx_publisher/Aria/ArLaserReflectorDevice.cpp
  src/lms5xx_publisher/Aria/ArLineFinder.cpp
  src/lms5xx_publisher/Aria/ArLMS1XX.cpp
  src/lms5xx_publisher/Aria/ArLMS2xx.cpp
  src/lms5xx_publisher/Aria/ArLMS2xxPacket.cpp
  src/lms5xx_publisher/Aria/ArLMS2xxPacketReceiver.cpp
  src/lms5xx_publisher/Aria/ArLog.cpp
  src/lms5xx_publisher/Aria/ArLogFileConnection.cpp
  src/lms5xx_publisher/Aria/ArMapComponents.cpp
  src/lms5xx_publisher/Aria/ArMap.cpp
  src/lms5xx_publisher/Aria/ArMapInterface.cpp
  src/lms5xx_publisher/Aria/ArMapObject.cpp
  src/lms5xx_publisher/Aria/ArMapUtils.cpp
  src/lms5xx_publisher/Aria/ArMD5Calculator.cpp
  src/lms5xx_publisher/Aria/ArMode.cpp
  src/lms5xx_publisher/Aria/ArModes.cpp
  src/lms5xx_publisher/Aria/ArModule.cpp
  src/lms5xx_publisher/Aria/ArModuleLoader.cpp
  src/lms5xx_publisher/Aria/ArMutex.cpp
  src/lms5xx_publisher/Aria/ArMutex_LIN.cpp
  src/lms5xx_publisher/Aria/ArNetServer.cpp
  src/lms5xx_publisher/Aria/ArNMEAParser.cpp
  src/lms5xx_publisher/Aria/ArNovatelGPS.cpp
  src/lms5xx_publisher/Aria/ArP2Arm.cpp
  src/lms5xx_publisher/Aria/ArPriorityResolver.cpp
  src/lms5xx_publisher/Aria/ArPTZ.cpp
  src/lms5xx_publisher/Aria/ArRangeBuffer.cpp
  src/lms5xx_publisher/Aria/ArRangeDevice.cpp
  src/lms5xx_publisher/Aria/ArRangeDeviceThreaded.cpp
  src/lms5xx_publisher/Aria/ArRatioInputJoydrive.cpp
  src/lms5xx_publisher/Aria/ArRatioInputKeydrive.cpp
  src/lms5xx_publisher/Aria/ArRatioInputRobotJoydrive.cpp
  src/lms5xx_publisher/Aria/ArRecurrentTask.cpp
  src/lms5xx_publisher/Aria/ArRobotConfig.cpp
  src/lms5xx_publisher/Aria/ArRobotConfigPacketReader.cpp
  src/lms5xx_publisher/Aria/ArRobotConnector.cpp
  src/lms5xx_publisher/Aria/ArRobot.cpp
  src/lms5xx_publisher/Aria/ArRobotJoyHandler.cpp
  src/lms5xx_publisher/Aria/ArRobotPacket.cpp
  src/lms5xx_publisher/Aria/ArRobotPacketReceiver.cpp
  src/lms5xx_publisher/Aria/ArRobotPacketSender.cpp
  src/lms5xx_publisher/Aria/ArRobotParams.cpp
  src/lms5xx_publisher/Aria/ArRobotTypes.cpp
  src/lms5xx_publisher/Aria/ArRVisionPTZ.cpp
  src/lms5xx_publisher/Aria/ArS3Series.cpp
  src/lms5xx_publisher/Aria/ArSensorReading.cpp
  src/lms5xx_publisher/Aria/ArSerialConnection_LIN.cpp
  src/lms5xx_publisher/Aria/ArSick.cpp
  src/lms5xx_publisher/Aria/ArSignalHandler_LIN.cpp
  src/lms5xx_publisher/Aria/ArSimpleConnector.cpp
  src/lms5xx_publisher/Aria/ArSimulatedLaser.cpp
  src/lms5xx_publisher/Aria/ArSocket.cpp
  src/lms5xx_publisher/Aria/ArSocket_LIN.cpp
  src/lms5xx_publisher/Aria/ArSonarAutoDisabler.cpp
  src/lms5xx_publisher/Aria/ArSonarDevice.cpp
  src/lms5xx_publisher/Aria/ArSonyPTZ.cpp
  src/lms5xx_publisher/Aria/ArSoundPlayer.cpp
  src/lms5xx_publisher/Aria/ArSoundsQueue.cpp
  src/lms5xx_publisher/Aria/ArSpeech.cpp
  src/lms5xx_publisher/Aria/ArStringInfoGroup.cpp
  src/lms5xx_publisher/Aria/ArSyncLoop.cpp
  src/lms5xx_publisher/Aria/ArSyncTask.cpp
  src/lms5xx_publisher/Aria/ArSystemStatus.cpp
  src/lms5xx_publisher/Aria/ArSZSeries.cpp
  src/lms5xx_publisher/Aria/ArTCM2.cpp
  src/lms5xx_publisher/Aria/ArTCMCompassDirect.cpp
  src/lms5xx_publisher/Aria/ArTCMCompassRobot.cpp
  src/lms5xx_publisher/Aria/ArTcpConnection.cpp
  src/lms5xx_publisher/Aria/ArThread.cpp
  src/lms5xx_publisher/Aria/ArThread_LIN.cpp
  src/lms5xx_publisher/Aria/ArTransform.cpp
  src/lms5xx_publisher/Aria/ArTrimbleGPS.cpp
  src/lms5xx_publisher/Aria/ArUrg_2_0.cpp
  src/lms5xx_publisher/Aria/ArUrg.cpp
  src/lms5xx_publisher/Aria/ArVCC4.cpp
  src/lms5xx_publisher/Aria/ArVersalogicIO.cpp
  src/lms5xx_publisher/Aria/md5.cpp
  )


## Declare a cpp executable
add_executable(lms5xx_publisher_node src/lms5xx_publisher/lms5xx_publisher_node.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(lms5xx_publisher_node lms5xx_publisher_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(lms5xx_publisher_node
   ${catkin_LIBRARIES}
   Aria_OLD
)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS lms5xx_publisher lms5xx_publisher_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_lms5xx_publisher.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
