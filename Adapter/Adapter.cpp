#include <iostream>
class Czasopismo
{
public:
    std::string czytaj()const
    {
        return "Czytam czasopismo";
    }  
};
class Ksiazka
{
public:
    std::string czytaj()const
    {
        return "Czytam ksiązkę";
    } 

};
void Client(Ksiazka* object)
{
    std::cout<<object->czytaj()<<std::endl;
}
class Adapter:public Ksiazka
{
    private:
        Czasopismo* gosc;
    public:
        Adapter(Czasopismo *jakies):gosc{jakies}{}
        std::string czytaj()const
        {
            if(gosc)
                return gosc->czytaj();
            else
                return "cos nie gra";
        }

};
int main()
{
    Czasopismo *Bravo=new Czasopismo;
    Adapter *adapter=new Adapter(Bravo);
    Client(adapter);

    delete Bravo;
}