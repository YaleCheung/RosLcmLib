#ifndef RATIO_HHH
#define RATIO_HHH

#include <stdio.h>

class Ratio {
public:
    Ratio (double n, double d) :
      ratio(n / d) {}

    double value() {
        return ratio;
    }
private:
    const double ratio;
};

class Freq : public Ratio {
public:
    Freq (double n) :
        Ratio(n, 1) {}
};

#endif //RATIO_HHH