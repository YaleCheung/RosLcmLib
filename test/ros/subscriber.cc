#include "function_proto.h"
#include "std_msgs/String.h"
#include "ipc_comm_node.h"

using Callback = FunctionPrototype<std_msgs::String>::Callback;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  auto node = std::make_shared<IPCCommNode<std_msgs::String, Callback>>("listener");
  node -> subscribe("chatter", chatterCallback, nullptr, 1);
  while(ros::ok()) 
     node->handle();
  return 0;
}
