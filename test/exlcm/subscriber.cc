#include "example_t.hpp"
#include "../../include/ipc_comm_node.h"
#include <stdio.h>
#include "../../include/function_proto.h"



using example_t = exlcm::example_t;

using Callback = FunctionPrototype<exlcm::example_t>::LCMCallback;
int main(int argc, char* argv[]) {
    auto comm = std::make_shared<IPCCommNode<example_t, Callback>>();
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
   
     
    auto callback = [](const lcm::ReceiveBuffer* rbuf, const std::string& chan, const example_t* msg, void* context) {
        printf("%d\n", *(int*)context);
        int i;
        printf("Received message on channel \"%s\":\n", chan.c_str());
        printf("  timestamp   = %lld\n", (long long)msg->timestamp);
        printf("  position    = (%f, %f, %f)\n",
                msg->position[0], msg->position[1], msg->position[2]);
        printf("  orientation = (%f, %f, %f, %f)\n",
                msg->orientation[0], msg->orientation[1], 
                msg->orientation[2], msg->orientation[3]);
        printf("  ranges:");
        for(i = 0; i < msg->num_ranges; i++)
            printf(" %d", msg->ranges[i]);
        printf("\n");
        printf("  name        = '%s'\n", msg->name.c_str());
        printf("  enabled     = %d\n", msg->enabled);
    };
    printf("start sub\n");
    comm->subscribe("EXAMPLE", callback, (void*)pint);
    while(1)
        comm->handle();
    return 0;
}
