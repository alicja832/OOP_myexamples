#pragma once
/**
 * @brief 
 * klasa opisujaca parametry wektora
 */
namespace vector{
class Vector{
    public:
    
    //ustala rozmiar wektora i uzupełnia go zerami
    Vector(int a):
    _n(a),
    _varray(new double[a])
    {}
    //tworzy jednowymiarowy wektor o wartosci double konwersja niejawna
    //konstruktor delegowany
    Vector(double x):Vector(1)
    {
        *(_varray)=x;

    }
    Vector(double a, double b):Vector(2)
    {
        _varray[0]=a;
        _varray[1]=b;

    }

    //kopiujący konstruktor
    Vector(const Vector& other):

    Vector(other._n)
    {   
        for(int i=0;i<_n;i++)
        _varray[i]=other._varray[i];
    }
    //konstruktor przenoszący
    Vector(Vector&& other);
    //teraz trzeba zrobić co innego czyli DESTROY
    ~Vector(){
        if(_varray)
        delete _varray;
    }
    //ustawia nam wektory
    double& vec(int);
    //wypisuje
    void print()const;
    void print(const char*)const;
    /**
     * @brief 
     * vecor z wym n staje się nagle wym x
     * @param x 
     * @return Vector 
     */
    Vector extended(int x);
    /**
     * @brief 
     * il skalarny
     * @return double 
     */
    //double dot(const Vector&,const Vector&);
    /**
     * @brief 
     * suma
     * @return Vector 
     */
    //Vector sum(const Vector&,const Vector&);
    /**
     * @brief 
     * konwersja jawna klasy vector na double czyli norma wektora
     * @return double 
     */
    explicit operator double()const;
    /**
     * @brief 
     * norma wektora
     * @return double 
     */
    double norm()const;
    double GetX()const{
        return _varray[0];
    }
    double GetY()const{
        return _varray[1];
    }



    int _n;
    double *_varray;

};

    double dot(const Vector&,const Vector&);
    /**
     * @brief 
     * suma
     * @return Vector 
     */
    Vector sum(const Vector&,const Vector&);

}