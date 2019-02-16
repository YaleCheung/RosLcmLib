#ifndef RATE_HHH
#define RATE_HHH

#include "duration.h"
#include "time.h"


class Rate {
 public:
  explicit Rate(double frequency);
  explicit Rate(uint64_t nanoseconds);
  explicit Rate(const Duration&);
  void sleep();
  void reset();
  Duration cycleTime() const;
  Duration expectedCycleTime() const { return _expected_cycle_time; }

 private:
  Time _start;
  Duration _expected_cycle_time;
  Duration _actual_cycle_time;

};

#endif  // CYBER_TIME_RATE_H_