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
        node -> publish("topic_m", msg, 2);
        loop_rate.sleep();
        //std::cout<<"print from cout: Hello wanzew...\n";
    }
    return 0;
}
