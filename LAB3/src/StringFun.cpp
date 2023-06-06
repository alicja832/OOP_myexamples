#include "StringFun.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PrintNames(vector<MyString>& v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i].str() << " ";
    cout << endl;
    cout << endl;
}
bool Less::operator()(MyString& a, MyString& b)const
    {
        return a.str()<b.str();
    }
bool Greater::operator()(MyString& a, MyString& b)const
    {
        return a.str()>b.str();
    }
bool Length::operator()(MyString& a, MyString& b)const
    {
        return a.str().length()<b.str().length();
    }