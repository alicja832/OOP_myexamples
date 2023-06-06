#pragma once

class Liniowa:public Fun{
public:
    Liniowa()
    {

    }
    static Liniowa* utworz()
    {
        Liniowa *tmp = new Liniowa;
        return tmp;
    }
    /*Liniowa* a(double x)
    {
        _a = x;
        return this;
    }
    Liniowa* b(double x)
    {
        _b = x;
        return this;
    }*/

};

class Kwadratowa:public Fun{
public:
    Kwadratowa()
    {

    }
    static Kwadratowa* utworz()
    {
        Kwadratowa *tmp = new Kwadratowa;
        return tmp;
    }
    Kwadratowa* a(double x)
    {
        _a = x;
        return this;
    }
    Kwadratowa* b(double x)
    {
        _b = x;
        return this;
    }
    Kwadratowa* c(double x)
    {
        _c=x;
        return this;
    }
    double wartosc(double x)
    {
        return _a*x*x+_b*x+_c;
    }

private:
    double _c;

};
