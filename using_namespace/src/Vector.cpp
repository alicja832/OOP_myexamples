#include "Vector.h"
#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
using namespace vector;
    double& Vector::vec(int ind){
        return _varray[ind];
    }
    Vector::Vector(Vector&& other):
    _varray(std::exchange(other._varray,nullptr)),
    _n(std::exchange(other._n,0)){}

    void Vector::print()const
    {   
        int i;
        if(!_varray)
            return;
        cout<<"[";
        for(i=0;i<_n-1;i++)
            cout<<_varray[i]<<",";
        cout<<_varray[i]<<"]"<<endl;
    }
void Vector:: print(const char* tekst)const
{
    cout<<tekst;
    this->print();
}

Vector Vector ::extended(int x){
    Vector ext(x);
    for(int i=0;i<_n;i++){
        ext._varray[i]=_varray[i];
    }


    return ext;
}
double vector::dot(const Vector& a,const Vector& b){
    int rzm,i;
    double wynik=0;
    (a._n>b._n)?rzm=a._n:rzm=b._n;

    for(i=0;i<rzm;i++)
        wynik+=a._varray[i]*b._varray[i];
    return wynik;
}
Vector vector::sum(const Vector& a,const Vector& b){
    int rzm,i;
    (a._n>b._n)?rzm=a._n:rzm=b._n;
    Vector tmp(rzm);
    for(i=0;i<rzm;i++)
        tmp._varray[i]=a._varray[i]+b._varray[i];
    return tmp;
}
double Vector::norm()const{
    double wynik=static_cast<double>(*this);
    return wynik;
}
Vector::operator double()const
    {
        double kw=0;
        for(int i=0;i<_n;i++)
            kw+=_varray[i]*_varray[i];

        return sqrt(kw);
    }
