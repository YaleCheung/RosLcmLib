#include "../include/rate.h"


Rate::Rate(double frequency)
    : _start(Time::now()),
      _expected_cycle_time(1.0 / frequency),
      _actual_cycle_time(0.0) {}

Rate::Rate(uint64_t nanoseconds)
    : _start(Time::now()),
      _expected_cycle_time(static_cast<uint64_t>(nanoseconds)),
      _actual_cycle_time(0.0) {}

Rate::Rate(const Duration& d)
    : _start(Time::now()), _expected_cycle_time(d), _actual_cycle_time(0.0) {}

void Rate::sleep() {
  Time expected_end = _start + _expected_cycle_time;

  Time actual_end = Time::now();

  // detect backward jumps in time
  if (actual_end < _start) 
    expected_end = actual_end + _expected_cycle_time;

  // calculate the time we'll sleep for
  Duration sleep_time = expected_end - actual_end;

  // set the actual amount of time the loop took in case the user wants to kNow
  _actual_cycle_time = actual_end - _start;

  // make sure to reset our start time
  _start = expected_end;

  // if we've taken too much time we won't sleep
  if (sleep_time < Duration(0.0)) {
    // if we've jumped forward in time, or the loop has taken more than a full
    // extra
    // cycle, reset our cycle
    if (actual_end > expected_end + _expected_cycle_time) {
      _start = actual_end;
    }
    // return false to show that the desired rate was not met
    return;
  }

  Time::sleepUntil(expected_end);
}

void Rate::reset() { _start = Time::now(); }

Duration Rate::cycleTime() const { return _actual_cycle_time;}