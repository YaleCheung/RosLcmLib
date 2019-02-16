#include "../include/time.h"
#include "../include/common.h"
#include "../include/duration.h"

#include <time.h>
#include <chrono>
#include <limits>
#include <thread>
#include <sstream>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::high_resolution_clock;

Time::Time(uint64_t nanoseconds) { _nano_sec = nanoseconds; }

Time::Time(int nanoseconds) {
  _nano_sec = static_cast<uint64_t>(nanoseconds);
}

Time::Time(double seconds) {
  _nano_sec = static_cast<uint64_t>(seconds * Mega);
}

Time::Time(uint32_t seconds, uint32_t nanoseconds) {
  _nano_sec = static_cast<uint64_t>(seconds) * Mega + nanoseconds;
}

Time::Time(const Time& other) { _nano_sec = other._nano_sec; }

Time& Time::operator=(const Time& other) {
  this->_nano_sec = other._nano_sec;
  return *this;
}

Time Time::now() {
  auto now = high_resolution_clock::now();
  auto nano_time_point =
      std::chrono::time_point_cast<std::chrono::nanoseconds>(now);
  auto epoch = nano_time_point.time_since_epoch();
  uint64_t now_nano =
      std::chrono::duration_cast<std::chrono::nanoseconds>(epoch).count();
  return Time(now_nano);
}

Time Time::monoTime() {
  auto now = steady_clock::now();
  auto nano_time_point =
      std::chrono::time_point_cast<std::chrono::nanoseconds>(now);
  auto epoch = nano_time_point.time_since_epoch();
  uint64_t now_nano =
      std::chrono::duration_cast<std::chrono::nanoseconds>(epoch).count();
  return Time(now_nano);
}

double Time::toSecond() const {
  return static_cast<double>(_nano_sec) / Mega;
}

bool Time::IsZero() const { return _nano_sec == 0; }

uint64_t Time::toNanosecond() const { return _nano_sec; }

std::string Time::toString() const {
  auto nano = std::chrono::nanoseconds(_nano_sec);
  system_clock::time_point tp(nano);
  auto time = system_clock::to_time_t(tp);
  std::stringstream ss;

  char date_time[128];
  strftime(date_time, sizeof(date_time), "%F %T", std::localtime(&time));
  ss << std::string(date_time) << "." << _nano_sec % 1000000000UL;
  return ss.str();
}

void Time::sleepUntil(const Time& time) {
  auto nano = std::chrono::nanoseconds(time.toNanosecond());
  system_clock::time_point tp(nano);
  std::this_thread::sleep_until(tp);
}

Duration Time::operator-(const Time& rhs) const {
  return Duration(static_cast<int64_t>(_nano_sec - rhs._nano_sec));
}

Time Time::operator+(const Duration& rhs) const {
  return Time(_nano_sec + rhs.ToNanosecond());
}

Time Time::operator-(const Duration& rhs) const {
  return Time(_nano_sec - rhs.ToNanosecond());
}

Time& Time::operator+=(const Duration& rhs) {
  *this = *this + rhs;
  return *this;
}

Time& Time::operator-=(const Duration& rhs) {
  *this = *this - rhs;
  return *this;
}

bool Time::operator==(const Time& rhs) const {
  return _nano_sec == rhs._nano_sec;
}

bool Time::operator!=(const Time& rhs) const {
  return _nano_sec != rhs._nano_sec;
}

bool Time::operator>(const Time& rhs) const {
  return _nano_sec > rhs._nano_sec;
}

bool Time::operator<(const Time& rhs) const {
  return _nano_sec < rhs._nano_sec;
}

bool Time::operator>=(const Time& rhs) const {
  return _nano_sec >= rhs._nano_sec;
}

bool Time::operator<=(const Time& rhs) const {
  return _nano_sec <= rhs._nano_sec;
}
