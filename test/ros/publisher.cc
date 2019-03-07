// #include "ros/ros.h"
#include "function_proto.h"
#include "rate.h"
#include "std_msgs/String.h"
#include <iostream> 
#include "ipc_comm_node.h"


using Callback = FunctionPrototype<std_msgs::String>::Callback;
int main(int argc, char** argv) {
    //init(argc, argv, "publisher_Node");
    auto node = std::make_shared<IPCCommNode<std_msgs::String, Callback>>("autonode");
    auto loop_rate = Rate(Freq(0.1));
 
    while(ros::ok()){
        std_msgs::String msg;
        msg.data = "Hello wanzew!";
        node -> publish("chatter", msg, 1);
        loop_rate.sleep();
    }
    return 0;
}
