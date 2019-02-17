#ifndef RATIO_HHH
#define RATIO_HHH

#include <stdio.h>

template<int N, int D = 1>
class Ratio {
public:
    Ratio () {}

    void get() {
        return ratio;
    }

private:
    constexpr double ratio{double(N / D)};
}

template<int N>
using Freq<N> = Ratio<N, 1>;

#endif //RATIO_HHH
