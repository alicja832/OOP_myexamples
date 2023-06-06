#include "Functions.h"
#include <cmath>

double Linear::operator()(double x)const
{
    return _x*x+_y;
}
double Sin::operator()(double x)const
{
    return sin(_x*x+_y);
}
