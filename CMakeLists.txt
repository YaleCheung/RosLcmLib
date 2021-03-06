cmake_minimum_required(VERSION 2.8.3)
project(CommuFrameworkTest)

ADD_DEFINITIONS(-D_ROS)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -fsanitize=address")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fsanitize=address")
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rosbag
  std_msgs
  sensor_msgs
)

include_directories(
    include
      ${catkin_INCLUDE_DIRS}
      #${EIGEN3_INCLUDE_DIR}
      ${PCL_INCLUDE_DIRS}
      include/detail
      )

catkin_package(
            CATKIN_DEPENDS roscpp std_msgs sensor_msgs
            DEPENDS EIGEN3 PCL
            INCLUDE_DIRS include)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ros_publisher test/ros/publisher.cc)
target_link_libraries(ros_publisher ${catkin_LIBRARIES})
add_executable(ros_subscriber test/ros/subscriber.cc)
target_link_libraries(ros_subscriber ${catkin_LIBRARIES})

add_executable(sub_test test/ros/sub_test.cc)
target_link_libraries(sub_test ${catkin_LIBRARIES})
