#pragma once
#include <vector>
#include <functional>

class FunctionSeries
{
public:
    FunctionSeries():_zmienna{0.0},_ster{0}
    {

    }
    void insert(std::function <double(double)> f);
    double calculate(double x);
    double step(int i);
private:
    std::vector <std::function<double(double)>> v;
    double _zmienna;
    int _ster;

};