#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>
template<int n,typename T>class Array
{
    public:
    Array(){
        tab=new T[n];
    }
    T& operator[](unsigned int i);
    ~Array()
    {
        delete []tab;
    }
    T *tab;
};
template<int n,typename T>class Array<n,T*>
{
    public:
    Array(){
        tab=new T*[n];
    }
    T*& operator[](unsigned int i);
    ~Array()
    {
        for(int i=0;i<n;i++)
            delete tab[i];
    }
    T **tab;
};
template<int n,typename T> std::ostream& operator<<(std::ostream& o,const Array<n,T>& A);
template<int n,typename T>T& Array<n,T>::operator[](unsigned int i)
{
    return tab[i];
}
template<int n,typename T>T*& Array<n,T*>::operator[](unsigned int i)
{
    return tab[i];
}
template<int n,typename T> std::ostream& operator<<(std::ostream& o,const Array<n,T>& A)
{
    for(int i=0;i<n;i++)
    {
        o<<A.tab[i]<<" ";
    }
    return o;
}
template<int n,typename T> std::ostream& operator<<(std::ostream& o,const Array<n,T*>& A)
{
    for(int i=0;i<n;i++)
    {
        o<<*(A.tab[i])<<" ";
    }
    return o;
}

#endif