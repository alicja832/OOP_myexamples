#pragma once
#include <functional>
#include <vector>
#include <utility>
#include <string.h>
#include <iostream>
#include <memory>
#include "Klasy.h"
template<typename T>void swap(T& a, T& b)
{
    T tmp;
    memcpy(&tmp,&a,sizeof(a));
    memcpy(&(a),&(b),sizeof(b));
    memcpy(&(b),&(tmp),sizeof(tmp));
}
template<>void swap(SkomplikowanaKlasa&  a, SkomplikowanaKlasa& b)
{
    
    SkomplikowanaKlasa tmp=a;
    a=b;
    b=tmp;
   
}
template<typename T>void bubble_sort(std::vector<T>& tablica, std::function<bool(const T&,const T&)> f)
{
    int i,j;
    for ( i = 0; i < tablica.size(); i++ )
       for (j = i+1; j < tablica.size(); ++j ) 
            if (f(tablica[i], tablica[j]))
              swap(tablica[j], tablica[i]);
}
template<typename T>void bubble_sort(std::vector<T>& tablica,bool(*f)(const T&,const T&) )
{
    int i,j;
    for ( i = 0; i < tablica.size(); i++ )
       for (j = i+1; j < tablica.size(); ++j ) 
            if (f(tablica[i], tablica[j]))
              swap(tablica[j], tablica[i]);
}