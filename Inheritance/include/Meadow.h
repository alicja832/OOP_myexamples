#pragma once
#include "GeneralAnimal.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <tuple>
#include <iterator>
class Meadow
{
    public:
    Meadow(){}
    void add(std::unique_ptr<GeneralAnimal> ptr)
    {
    
      vec.push_back(std::move(ptr));
    
    }
    void print(std::string title)
    {
        std::cout<<"__________"<<title<<std::endl;
        for(int i=0;i<vec.size();i++)
            vec[i]->print();
    }
    void countNames()const
    {
        std::vector <std::string> names;
        std::vector <std::string> sorted_names;
        std::vector<std::tuple <std::string,int>> list;
        for (int i=0;i<vec.size();i++)
        {
            names.push_back(vec[i]->name());
        }
        std::sort(names.begin(),names.end());
        auto it=names.begin();

        for(int i=0;i<vec.size();i++)
        {
            std::string found=names[i];
            int h=std::count(names.begin(),names.end(),found);
            std::advance(it,i+1);
            auto x=std::find(it,names.end(),found);
            if(x==names.end())
                std::cout<<names[i]<<h<<std::endl;
            it=names.begin();
        }
       /* for (int i=0;i<list.size();i++)
        {
            std::cout<<std::get<0>(list[i])<<std::get<1>(list[i])<<std::endl;
        */
    }
    ~Meadow(){
        vec.clear();
        }
    private:
    std::vector <std::unique_ptr<GeneralAnimal>>vec;
};