#ifndef DURATION_HHH
#define DURATION_HHH

#include <stdint.h>

class Duration {
public:
    Duration() {}
    explicit Duration(uint64_t nanoseconds);
    explicit Duration(int nanoseconds);
    explicit Duration(double seconds);
    explicit Duration(uint32_t seconds, uint32_t nanoseconds);
    Duration(const Duration &other);
    Duration &operator=(const Duration &other);
    ~Duration() {}

    double ToSecond() const;
    uint64_t ToNanosecond() const;
    bool isZero() const;
    void sleep() const;

    Duration operator+(const Duration &rhs) const;
    Duration operator-(const Duration &rhs) const;
    Duration operator-() const;
    Duration operator*(double scale) const;
    Duration &operator+=(const Duration &rhs);
    Duration &operator-=(const Duration &rhs);
    Duration &operator*=(double scale);
    bool operator==(const Duration &rhs) const;
    bool operator!=(const Duration &rhs) const;
    bool operator>(const Duration &rhs) const;
    bool operator<(const Duration &rhs) const;
    bool operator>=(const Duration &rhs) const;
    bool operator<=(const Duration &rhs) const;

private:
    uint64_t _nano_sec = 0;
};

#endif  // DURATION_HHH
