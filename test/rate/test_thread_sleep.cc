#include "../../include/rate.h"
#include <iostream>

int main(int argc, char* argv[]) {
    auto rate = Rate(Freq(10));
    auto cur = Clock::now();

    for(auto i = 0; i < 10; ++ i) {
        rate.sleep();
        std::cout << "sleeped " << std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - cur).count() << '\n'; 
        cur = Clock::now();
    }
		return 0;
}
