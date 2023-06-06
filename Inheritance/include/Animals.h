#pragma once
#include "Meadow.h"
#include <string>

class Sheep:public GeneralAnimal
{
    public:
    Sheep(const Sheep& other):Sheep(other.name()){}
    Sheep(const std::string& name):GeneralAnimal(name){}
    void print()const
    {
        std::cout<<"Owca ";
        std::cout<<name()<<std::endl;
    }
    ~Sheep(){}
};
class Cow:public GeneralAnimal
{
    public:
    Cow(const std::string& name):GeneralAnimal(name){}
    void print()const
    {
         std::cout<<"Krowa ";
        std::cout<<name()<<std::endl;
    }
    ~Cow(){}
};
class Horse:public GeneralAnimal
{
    public:
    Horse(const std::string& name):GeneralAnimal(name){}
    void print()const
    {
         std::cout<<"Koń ";
        std::cout<<name()<<std::endl;
    }
    ~Horse(){}
};