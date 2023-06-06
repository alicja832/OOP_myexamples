#pragma once
class Sin{

public:
    Sin(double x, double y):_x{x},_y{y}
    {

    }
    double operator()(double x)const;
private:
    double _x,_y;

};
class Linear{
public:
    Linear(double x,double y):_x{x},_y{y}
    {

    }
    double operator()(double x)const;

private:
    double _x,_y;
};