#pragma once
/**
 * @brief 
 * klasa bazowa dotyczaca hierarachi nr 2
 */
 class Op1{
public:
    Op1()
    {

    }
    /**
     * @brief 
     * metoda :-) dzięki ktorej wiemy  z jakiej funcji liczyc pochodna
     * @param el 
     * @return Op1* 
     */
    Op1* z(Fun* el)
    {
        ptr = el;
        return this;
    }
    /**
     * @brief 
     * wirtuALNa ponieważ używamy tej samej w klasach pochodnych
     oraz dlatego że jest wywoływana z poziomu tej klasy dla klasy pochodnej
     
     * @param x 
     * @return double 
     */
    virtual double w(double x)const
    {
        return ptr->wartosc(x);
    }

    ~Op1()
    {
        
    }
protected:
    Fun* ptr;
 };
 