#pragma once
class ProstaRozniczka:public Op1{
public:
    ProstaRozniczka(double h):_h{h}
    {

    }
    /**
     * @brief 
     * poprostu rozniczka o zadanym kroku
     * @param x 
     * @return double 
     */
    double w(double x)const
    {
        double wynik = (ptr->wartosc(x+_h)-ptr->wartosc(x-_h))/(2*_h);
        return wynik;
    }
private:
    double _h;
};