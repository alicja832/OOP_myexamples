#pragma once
/**
 * @brief 
 * liczymy wartosc funkcji od wartosci funkcji ktorą podamy 
 dla klasy bazowej Op1
 */
class FZlozona:public Op1{
public:
    FZlozona(Fun* ptr):_f{ptr}
    {

    }
    double w(double x)const
    {
        return _f->wartosc(ptr->wartosc(x));
    }
private:
    Fun* _f;//dodatkowa funkcja "najbardziej zewnetrzna"


};