#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include <iostream>
#include <cstdlib>

using namespace std::chrono_literals;



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::PoseStamped>("goal_pose", 10);
  
  std::unique_ptr<tf2_ros::Buffer> buffer = std::make_unique<tf2_ros::Buffer>(node->get_clock());
  std::shared_ptr<tf2_ros::TransformListener> transform_listener_ = std::make_shared<tf2_ros::TransformListener>(*buffer);
  
  geometry_msgs::msg::TransformStamped map_baselink;
  geometry_msgs::msg::PoseStamped message, current;

  rclcpp::WallRate loop_rate(500ms);
  
  double px[3]={-1,8.5,7.5}, py[3]={3,5,-2},pxs,pys;
  int i=0;
  
  while (rclcpp::ok() & (i<3)) {
    message.pose.position.x = px[i];
    message.pose.position.y = py[i];
    publisher->publish(message);
    
    map_baselink = buffer->lookupTransform("base_link", "map", rclcpp::Time(0), rclcpp::Duration(2.0));
    tf2::doTransform(message, current, map_baselink);
    
    pxs=std::abs(current.pose.position.x);
    pys=std::abs(current.pose.position.y);
    
    if((pxs<0.25)&(pys<0.25)) 
      i=i+1;
    
    
    
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}
//-2.9437; 2.4422; 0.0085269
//-0.86214; 2.8828; 1.7168e-06


