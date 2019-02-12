#include "example_t.hpp"
#include "../../include/lcm_node.h"
#include <stdio.h>
#include "../../include/function_proto.h"



using example_t = exlcm::example_t;

// typedef void(* Callback_t)(const lcm::ReceiveBuffer* rbuf, const std::string& channel, const example_t* msg, void* contex);
//
using Callback_t = FunctionPrototype<exlcm::example_t>::LCMCallback;
int main(int argc, char* argv[]) {
    auto comm = std::make_shared<LCMNode<example_t, Callback_t>>();
    example_t my_data;

    int* pint = new int;
    *pint = 2;

    my_data.timestamp = 0;
    my_data.position[0] = 1;
    my_data.position[1] = 2;
    my_data.position[2] = 3;
   
    my_data.orientation[0] = 1;
    my_data.orientation[1] = 0;
    my_data.orientation[2] = 0;
    my_data.orientation[3] = 0;
   
    my_data.num_ranges = 15;
    my_data.ranges.resize(my_data.num_ranges);
    for(int i = 0; i < my_data.num_ranges; i++)
        my_data.ranges[i] = i;
   
    my_data.name = "example string";
    my_data.enabled = true;
   
    printf("start publish\n");
    comm->publish("EXAMPLE", my_data);
    printf("end publish\n");
    return 0;
}
