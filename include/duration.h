#ifndef DURATION_HHH
#define DURATION_HHH

#include <stdint.h>

class Duration {
public:
    Duration() {}

    explicit Duration(uint64_t nano_sec);
    explicit Duration(int nano_sec);
    explicit Duration(double sec);
    explicit Duration(uint32_t sec, uint32_t nano_sec);
    
    Duration(const Duration& duration);
    
    ~Duration() {}

    double toSecond() const;
    uint64_t getNano() const;
    void sleep() const;

    Duration& operator = (const Duration &other);
    Duration operator + (const Duration &rhs) const;
    Duration operator - (const Duration &rhs) const;
    Duration operator - () const;
    Duration operator * (double scale) const;
    Duration& operator += (const Duration& rhs);
    Duration& operator -= (const Duration& rhs);
    Duration& operator *= (double scale);
    bool operator == (const Duration& rhs) const;
    bool operator != (const Duration& rhs) const;
    bool operator > (const Duration& rhs) const;
    bool operator < (const Duration& rhs) const;
    bool operator >= (const Duration& rhs) const;
    bool operator <= (const Duration& rhs) const;

private:
    uint64_t _nano_sec = 0;
};

#endif  // DURATION_HHH
