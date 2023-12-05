#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <iostream>
#include <cstdlib>

using namespace std::chrono_literals;

double pxs,pys;
void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
 pxs = msg->pose.pose.position.x +2.08156;
 pys = msg->pose.pose.position.y +0.4406;

}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::PoseStamped>("goal_pose", 10);
  auto subscription = node->create_subscription<nav_msgs::msg::Odometry>("odom", 10, topic_callback);
  geometry_msgs::msg::PoseStamped message;
  rclcpp::WallRate loop_rate(500ms);
  double px[3]={-1,8.5,7.5}, py[3]={3,5,-2},pxi,pyi;
  int i=0;
  

  while (rclcpp::ok() & (i<3)) {
    message.pose.position.x = px[i];
    message.pose.position.y = py[i];
    publisher->publish(message);
    pxi=std::abs(px[i]);
    pyi=std::abs(py[i]);
    pxs=std::abs(pxs);
    pys=std::abs(pys);
    
    if((std::abs(pxi-pxs)<0.25)&(std::abs(pyi-pys)<0.25)) 
      i=i+1;
    
    
    
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}
//-2.9437; 2.4422; 0.0085269
//-0.86214; 2.8828; 1.7168e-06


