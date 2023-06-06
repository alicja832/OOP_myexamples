#pragma once
#include <cmath>

class Sinus:public Fun{
public:
    Sinus()
    {

    }
    double wartosc(double x)
    {
        return sin(x);
    }
};
