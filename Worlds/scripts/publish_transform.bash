#!/bin/bash
source /opt/ros/foxy/setup.bash
export ROS_LOCALHOST_ONLY=1
ros2 run tf2_ros static_transform_publisher 0.70 8.70 0 0 0 0 1 map odom
