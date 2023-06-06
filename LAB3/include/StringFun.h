#pragma once
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
class MyString{
    public:
    MyString(const char *text):_text{text}
    {
        
    }
    const MyString& operator=(const MyString& other)
    {
        _text = other._text;
        return *this;
    }
    MyString(const MyString& other):_text{other._text}
    {

    }
    static void* operator new(size_t size)
    {
        void *tmp;
        std::cout<<"[MyString] Overloading new operator with size: "<<size<<std::endl;
        tmp = malloc(size);
            return tmp;
    }
    static void operator delete(void *tmp)
    {
       std::cout<<" [MyString] Overloading delete operator"<<std::endl; 

    }
    std::string& str()
    {
        return _text;
    }
    private:
    std::string _text;
};
class Less{
public:
    Less()
    {

    }
    bool operator()(MyString& a, MyString& b)const;
    
};
/**
 * @brief 
 * klasa pelniaca role funktora,wskazujaca, ktory element
 MySring jest alfabetycznie drugi
 */
class Greater{
public:
    Greater()
    {

    }
    bool operator()(MyString& a, MyString& b)const;
   
};
/**
 * @brief 
 * klasa pelniaca role funktora porownujaca dlugosci skladnikow
 MySring
 */
class Length{
public:
    Length()
    {

    }
    bool operator()(MyString& a, MyString& b)const;

};
/**
 * @brief 
 * funcja wypisujaca zawartosc wektora zawierajacego instancje
 klasy MyString
 * @param v 
 */
void PrintNames(std::vector<MyString>& v);



class MyStringContainer
{
    public:
    MyStringContainer()
    {
        Less a;
        Greater b;
        fun.push_back(a);
        fun.push_back(b);

    }
    MyStringContainer(const MyStringContainer& other)
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
        int i=0;
        while(i<other.vec.size())
        {
            MyString *tmp = new MyString(*(other.vec[i]));
            vec.push_back(tmp);
            i++;
        }
        vv=other.vv;
        fun = other.fun;
        
    }
    ~MyStringContainer()
    {
        int i=0;
        while(i<vec.size()){
            delete(vec[i]);
            i++;
        }
    }
    void AddMStr(MyString *tmp)
    {
        vec.push_back(tmp);
        vv.push_back(*tmp);
    }
    void AddMStr(const char *x)
    {
        MyString *t = new MyString(x);
        AddMStr(t);
    }
    std::vector<MyString>& GetSorted(const char *s)
    {
        if(s == "ASC")
        {
            std::sort(vv.begin(),vv.end(),fun[0]);
        }
        else if( s == "DESC")
        {
            std::sort(vv.begin(),vv.end(),fun[1]);
        }
        return vv;
    }
    std::vector<std::function<bool(MyString& ,MyString&)>> SortFunc()
    {
        return fun;
    }
    private:
    std::vector<MyString*> vec;
    std::vector<MyString> vv;
    std::vector<std::function<bool(MyString& ,MyString&)>> fun;
};
