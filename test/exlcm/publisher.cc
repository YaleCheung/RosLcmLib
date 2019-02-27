#include "example_t.hpp"
#include "../../include/ipc_comm_node.h"
#include <stdio.h>
#include "../../include/function_proto.h"


using example_t = exlcm::example_t;

using Callback = FunctionPrototype<exlcm::example_t>::Callback;

int main(int argc, char* argv[]) {
    auto comm = std::make_shared<IPCCommNode<example_t, Callback>>("string");
    example_t my_msg;

    int* pint = new int;
    *pint = 2;

    my_msg.timestamp = 0;
    my_msg.position[0] = 1;
    my_msg.position[1] = 2;
    my_msg.position[2] = 3;
   
    my_msg.orientation[0] = 1;
    my_msg.orientation[1] = 0;
    my_msg.orientation[2] = 0;
    my_msg.orientation[3] = 0;
   
    my_msg.num_ranges = 15;
    my_msg.ranges.resize(my_msg.num_ranges);
    for(int i = 0; i < my_msg.num_ranges; i++)
        my_msg.ranges[i] = i;
   
    my_msg.name = "example string";
    my_msg.enabled = true;
   
    printf("start publish\n");
    comm->publish("EXAMPLE", my_msg, 0);
    printf("end publish\n");
    return 0;
}
