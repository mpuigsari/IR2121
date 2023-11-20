#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/posestamped.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::PoseStamped>("topic", 10);
  geometry_msgs::msg::PoseStamped message;
  auto publish_count = 0;
  rclcpp::WallRate loop_rate(500ms);
  int px1=1, py1=1, pz1=1, qx1=1, qy1=1, qz1=1, qw1=1;
  while (rclcpp::ok()) {
    message.pose.point.x = px1;
    message.pose.point.y = py1;
    message.pose.point.z = pz1;
    message.pose.quaternion.x = qx1;
    message.pose.quaternion.y = qy1;
    message.pose.quaternion.z = qz1;
    message.pose.quaternion.z = qw1;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}

