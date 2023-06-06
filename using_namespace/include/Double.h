#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;
class Double{
    public:
    Double(vector::Vector x):
    Double(static_cast<double>(x))
    {

    }
    Double(double x):_x(x)
    {

    }
    void setconstx(double x)const{
        _x=x;
    }
    void setx(const Double& x){
        _x=x._x;
    }
    void print()const;
    static void count(){
        nr++;
    }
    static int nr;
    mutable double _x;
};

inline void print(const Double& x){
    x.print();
}
inline double sum(const Double &x,const Double &y){
    return x._x+y._x;
}