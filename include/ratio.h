#ifndef RATIO_HHH
#define RATIO_HHH

class Ratio {
public:
    Ratio (double n, double d) :
      _ratio(n / d) {}

    double value() const {
        return _ratio;
    }
private:
    const double _ratio;
};

class Freq : public Ratio {
public:
    Freq (double n) :
        Ratio(n, 1) {}
};

#endif //RATIO_HHH
