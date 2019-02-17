#ifndef RATE_HHH
#define RATE_HHH

#include <chrono>
#include "duration.h"
#include "ratio.h"

using Duration = std::chrono::nanoseconds;
using Time = std::chrono::time_point;
using Clock = std::chrono::high_resolution_clock;
class Freq;

class Rate {
public:
    explicit Rate(Freq freq);

    void sleep();
    void reset() {_start = Time::now();}
    Duration cycleTime() const {return _actual_cycle_time;}
    Duration expectedCycleTime() const { return _expected_cycle_time; }

private:
    Time _start;
    Duration _expected_cycle_time;
    Duration _actual_cycle_time;
};

#endif  // CYBER_TIME_RATE_H_
