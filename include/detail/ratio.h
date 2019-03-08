#ifndef RATIO_HHH
#define RATIO_HHH

#include <cassert>

class Ratio {
public:
    Ratio (double n, double d = 1.0) {
        assert(d > 0);
        _ratio = n / d;
    }

    double value() const {
        return _ratio;
    }
private:
    double _ratio;
};

class Freq : public Ratio {
public:
    Freq (double n) :
        Ratio(n, 1) {}
};

#endif //RATIO_HHH
