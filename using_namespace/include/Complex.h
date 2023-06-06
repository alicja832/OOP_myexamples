#pragma once
#include "Vector.h"
//ZESPOLONE
namespace complex{
    class Complex{
        public:
        Complex(double x);
        Complex();
        //zwykły konstruktor dwuargumentowy
        Complex(double re, double im);
        //konsturktor konwertujący
        Complex(vector::Vector x);
        //konsturktor przenoszący
        Complex(Complex &&other);
        //konsturktor kopiujący
        Complex(const Complex &other);

        //funkcja konwerturjca na Vector nie jest explicit!!! ponieważ zachodzi konwersja nie jawna
       operator vector::Vector()const;
        //f.drukująca
        void print(const std::string& name);
        //suma
        double GetRe()const{
            return _re;
        }
        double GetIm()const{
            return _im;
        }

        private:
        double _re,_im;    
    };
    Complex sum(const Complex& a,const Complex& b);
}