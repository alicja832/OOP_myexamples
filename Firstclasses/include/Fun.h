#pragma once
/**
 * @brief 
 * To jest nasza klasa bazowa
 */
class Fun{
public:
    Fun()
    {

    }
    Fun* a(double x)
    {
        _a = x;
        return this;
    }
    Fun* b(double x)
    {
        _b = x;
        return this;
    }
    /**
     * @brief 
     * zwraca wartosc danej funcji elementarnej
     * @param x 
     * @return double 
     */
    virtual double wartosc(double x)
    {
        return _a*x+_b;
    }

protected:
    double _a,_b;

};