#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream> 
 
 
using Callback = FunctionPrototype::Callback;
int main(int argc, char** argv){
    init(argc, argv, "publisher_Node"); 
    auto node = IPCCommNode<std_msgs::String, Callback>();
    node.publish("topic_m", 1000);
    Rate loop_rate(Freq(0.1));
 
    while(ok()){
        std_msgs::String msg;
        msg.data = "Hello wanzew!";
        node.publish("topic_m", msg, 2);
        loop_rate.sleep();
        cout<<"print from cout: Hello wanzew..."<<endl;
    }
    return 0;
}
