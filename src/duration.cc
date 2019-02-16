#include "../include/duration.h"
#include "../include/common.h"

#include <chrono>
#include <thread>

Duration::Duration(uint64_t nanoseconds) { _nano_sec = nanoseconds; }

Duration::Duration(int nanoseconds) {
    _nano_sec = static_cast<uint64_t>(nanoseconds);
}

Duration::Duration(double seconds) {
  _nano_sec = static_cast<uint64_t>(seconds * Mega);
}

Duration::Duration(uint32_t seconds, uint32_t nanoseconds) {
  _nano_sec = static_cast<uint64_t>(seconds) * Mega + nanoseconds;
}

Duration::Duration(const Duration &other) { _nano_sec = other._nano_sec; }

Duration &Duration::operator=(const Duration &other) {
    this->_nano_sec = other._nano_sec;
    return *this;
}

double Duration::ToSecond() const {
    return static_cast<double>(_nano_sec) / Mega;
}

uint64_t Duration::ToNanosecond() const { return _nano_sec; }

bool Duration::isZero() const { return _nano_sec == 0; }

void Duration::sleep() const {
    auto sleep_time = std::chrono::nanoseconds(_nano_sec);
    std::this_thread::sleep_for(sleep_time);
}

Duration Duration::operator+(const Duration &rhs) const {
    return Duration(_nano_sec + rhs._nano_sec);
}

Duration Duration::operator-(const Duration &rhs) const {
    return Duration(_nano_sec - rhs._nano_sec);
}

Duration Duration::operator-() const { return Duration(-_nano_sec); }

Duration Duration::operator*(double scale) const {
    return Duration(uint64_t(static_cast<double>
        (_nano_sec) * scale));
}

Duration &Duration::operator+=(const Duration &rhs) {
    *this = *this + rhs;
    return *this;
}

Duration &Duration::operator-=(const Duration &rhs) {
  *this = *this - rhs;
  return *this;
}

Duration &Duration::operator*=(double scale) {
  *this = Duration(uint64_t(static_cast<double>
        (_nano_sec) * scale));
  return *this;
}

bool Duration::operator==(const Duration &rhs) const {
    return _nano_sec == rhs._nano_sec;
}

bool Duration::operator!=(const Duration &rhs) const {
    return _nano_sec != rhs._nano_sec;
}

bool Duration::operator>(const Duration &rhs) const {
    return _nano_sec > rhs._nano_sec;
}

bool Duration::operator<(const Duration &rhs) const {
    return _nano_sec < rhs._nano_sec;
}

bool Duration::operator>=(const Duration &rhs) const {
    return _nano_sec >= rhs._nano_sec;
}

bool Duration::operator<=(const Duration &rhs) const {
    return _nano_sec <= rhs._nano_sec;
}