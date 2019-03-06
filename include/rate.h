#ifndef RATE_HHH
#define RATE_HHH

#include <chrono>

#include <thread>
#include "ratio.h"

using Duration = std::chrono::nanoseconds;
using Clock = std::chrono::high_resolution_clock;
using Time = Clock::time_point;

class Rate {
public:
    Rate(Freq freq):
      _start(Clock::now()),
      _expected_cycle_time(int(1000000000ul / freq.value())),
      _actual_cycle_time(0) {}

    void sleep() {
        auto expected_end = _start + _expected_cycle_time;

        auto actual_end = Clock::now();

        // detect backward jumps in time
        if (actual_end < _start)
            expected_end = actual_end + _expected_cycle_time;

        // calculate the time we'll sleep for
        auto sleep_time = expected_end - actual_end;

        _actual_cycle_time = actual_end - _start;

        _start = expected_end;

        // if we've taken too much time we won't sleep
        if (sleep_time < Duration(0)) {
            if (actual_end > expected_end + _expected_cycle_time) 
                _start = actual_end;
            return;
        }

        std::this_thread::sleep_until(expected_end);
    }
    void reset() {_start = Clock::now();}
    Duration cycleTime() const {return _actual_cycle_time;}
    Duration expectedCycleTime() const { return _expected_cycle_time; }

private:
    Time _start;
    Duration _expected_cycle_time;
    Duration _actual_cycle_time;
};

#endif  // RATE_HHH
