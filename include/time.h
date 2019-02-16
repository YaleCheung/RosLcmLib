#ifndef TIME_HHH
#define TIME_HHH

#include <limits>
#include <string>

#include "duration.h"


class Time {
 public:
  Time() {}
  explicit Time(uint64_t nanoseconds);
  explicit Time(int nanoseconds);
  explicit Time(double seconds);
  Time(uint32_t seconds, uint32_t nanoseconds);
  Time(const Time& other);
  Time& operator=(const Time& other);
  ~Time() {}

  static Time now();
  static Time monoTime();
  static void sleepUntil(const Time& time);

  double toSecond() const;
  uint64_t toNanosecond() const;
  std::string toString() const;
  bool IsZero() const;

  Duration operator-(const Time& rhs) const;
  Time operator+(const Duration& rhs) const;
  Time operator-(const Duration& rhs) const;
  Time& operator+=(const Duration& rhs);
  Time& operator-=(const Duration& rhs);
  bool operator==(const Time& rhs) const;
  bool operator!=(const Time& rhs) const;
  bool operator>(const Time& rhs) const;
  bool operator<(const Time& rhs) const;
  bool operator>=(const Time& rhs) const;
  bool operator<=(const Time& rhs) const;

 private:
  uint64_t _nano_sec = 0;
};

#endif  // CYBER_TIME_TIME_H_
