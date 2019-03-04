#include "function_proto.h"
#include "rate.h"
#include "std_msgs/String.h"
#include <iostream>
#include "ipc_comm_node.h"


using Callback = FunctionPrototype<std_msgs::String>::Callback;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  std::cout << "ok hearded" << '\n';
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  auto node = std::make_shared<IPCCommNode<std_msgs::String, Callback>>("secnode");

  node -> subscribe("topic_m", chatterCallback, nullptr, 2);
  ros::spin();
  return 0;
}
