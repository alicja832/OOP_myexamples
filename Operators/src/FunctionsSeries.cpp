#include <vector>
#include <functional>
#include "FunctionSeries.h"

void FunctionSeries::insert(std::function <double(double)> f)
{
    v.push_back(f);
    _ster = v.size();
}
double FunctionSeries::calculate(double x)
{
    int i=0;
    _zmienna = x;
    double rezult=0;
    while(i<_ster)
    {   
        rezult = v[i++](x);
        x = rezult;
    }

    return rezult;
}
double FunctionSeries::step(int i)
{
    _ster = i+1;
    return calculate(_zmienna);
}