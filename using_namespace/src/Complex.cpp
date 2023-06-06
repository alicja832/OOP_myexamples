    #include <iostream>
    #include <utility>
    #include <string>
    #include "Complex.h"
    #include "Vector.h"
    using namespace std;
    using namespace complex;

        Complex::Complex():_re(0.),_im(0.){}
        Complex::Complex(double re, double im):_re(re),_im(im){}
        Complex::Complex(double x):Complex(x,0.){}
        //konsturktor konwertujący
        Complex::Complex(vector::Vector x):_re(x.GetX()),_im(x.GetY()){}
        //konsturktor przenoszący
        Complex::Complex(Complex &&other):
        _re(exchange(other._re,0.)),
        _im(exchange(other._im,0.))
        {
            
        }
        //konsturktor kopiujący
        Complex::Complex(const Complex &other):
        Complex(other._re,other._im)
        {
            cout<<"Używamy konstruktora kopiującego"<<endl;
        }
        
        //funkcja konwerturjca
        Complex::operator vector::Vector()const{
            vector::Vector tmp(_re,_im);
            return tmp;
        }
        //f.drukująca
        void Complex::print(const string& name){
            //lepiej chyba operatorem ? a:b
            if(_im!=0)
            cout<<name<<" = "<<_re<<" + "<<_im<<"i"<<endl;
            else
             cout<<name<<" = "<<_re<<endl;

        }
        //suma i to jest właś nie zagadka, że musisz 
        //napisać że to jest też z tej przestrzeni, dziwne bo ona, ta funckcja nie jest z klasy
        Complex complex::sum(const Complex& a,const Complex& b){
            //double x=a.GetRe();
            Complex tmp((a.GetRe()+b.GetRe()),(b.GetIm()+a.GetIm()));
            return tmp;
        }