// #include "../include/rate.h"

// template<int N>
// Rate<N>::Rate<N>(Freq<N> freq)
//     : _start(Clock::now()),
//       _expected_cycle_time(1.0 / freq.value()),
//       _actual_cycle_time(0.0) {}

// void Rate::sleep() {
//     auto expected_end = _start + _expected_cycle_time;

//     auto actual_end = Time::now();

//     // detect backward jumps in time
//     if (actual_end < _start) 
//       expected_end = actual_end + _expected_cycle_time;

//     // calculate the time we'll sleep for
//     auto sleep_time = expected_end - actual_end;

//     _actual_cycle_time = actual_end - _start;

//     _start = expected_end;

//     // if we've taken too much time we won't sleep
//     if (sleep_time < Duration(0.0)) {
//       // if we've jumped forward in time, or the loop has taken more than a full
//       // extra
//       // cycle, reset our cycle
//       if (actual_end > expected_end + _expected_cycle_time) {
//         _start = actual_end;
//       }
//       return;
//     }

//     std::this_thread::sleep_for(expected_end);
// }