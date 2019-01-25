#include "example_t.hpp"
#include "../../include/CommNode.h"



using example_t = exlcm::example_t;
int main(int argc, char* argv[]) {
    auto comm = std::make_shared<LcmNode<example_t>>();
    example_t my_data;

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
   
    comm->publish("EXAMPLE", my_data);
     
    LcmNode<example_t>::Callback_t callback = [](const lcm::ReceiveBuffer* rbuf, const std::string& chan, const example_t* msg, void* ptr) {
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
    comm->subscribe("EXAMPLE", callback);
    return 0;
}
