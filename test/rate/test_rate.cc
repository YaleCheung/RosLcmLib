#define CATCH_CONFIG_MAIN

#include "single_include/catch2/catch.hpp"
#include <chrono>
#include "rate.h"



TEST_CASE( "Different Freq of Sleep", "rate" ) {
  SECTION( "case 0.1 " ) {
      auto rate = Rate(Freq(0.1));
      auto cur = Clock::now();

      for(auto i = 0; i < 5; ++ i) {
          rate.sleep();
          auto diff = std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - cur).count();
          REQUIRE(diff >= 9050000);
          REQUIRE(diff <= 10030000);
          cur = Clock::now();
      }
  }
  SECTION( "case 10" ) {
      auto rate2 = Rate(Freq(10));
      auto cur2 = Clock::now();
      for(auto i = 0; i < 5; ++ i) {
          rate2.sleep();
          auto diff2 = std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - cur2).count();
          REQUIRE(diff2 >= 85000);
          REQUIRE(diff2 <=  115002);
          cur2 = Clock::now();
      }
  }
}
