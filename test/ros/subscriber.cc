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
  // ros::init(argc, argv, "listener");
  // ros::NodeHandle n;
  // Callback callback = chatterCallback;
  node -> subscribe("chatter", chatterCallback, nullptr, 1000);
  // auto sub =n.subscribe("chatter", 1000, callback);
  while(ros::ok()) {
     node->handle();
  }
  return 0;
}
