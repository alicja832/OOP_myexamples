#include <iostream>
template<typename T>class One
{
    public:
    One(T value):_value{value}
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
    
    T _value;
};
template<typename T>One(T t)->One<T>;

template <typename T1>
class Two
{
     public:
    Two(T1 value):_value{value}
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }

    T1 _value;

};
template <typename T1>
class Two<T1*>:public One<T1>
{
     public:
    Two(T1* value):One<T1>(*value),_value{value}
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }

    T1 *_value;

};
//check the score
int main()
{
    Two two(new double(4.0));
    One one{1};
    std::cout<<one._value<<std::endl;

    return 0;

}
