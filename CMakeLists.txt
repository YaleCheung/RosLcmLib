cmake_minimum_required(VERSION 2.8.3)
project(CommuFrameworkTest)

## Compile as C++11, supported in ROS Kinetic and newer
#add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
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
      ${PCL_INCLUDE_DIRS})

catkin_package(
            CATKIN_DEPENDS roscpp std_msgs sensor_msgs
            DEPENDS EIGEN3 PCL
            INCLUDE_DIRS include)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ros_publisher test/exlcm/publisher.cc)
target_link_libraries(ros_publisher ${catkin_LIBRARIES})
add_executable(ros_subscriber test/exlcm/subscriber.cc)
target_link_libraries(ros_subscriber ${catkin_LIBRARIES})
