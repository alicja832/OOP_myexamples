#pragma once
#include <iostream>
class X
{
    public:
    X(){}
    X(std::string n):napis{n}
    {}
    X& operator=(X& other)
    {
        
        napis=other.napis;
        return *this;
    }
    X& operator=(X&& other)
    {
        napis=other.napis;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& o,const X& x)
    {
        o<<x.napis;
        return o;
    }
    private:
    std::string napis;
};