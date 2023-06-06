#pragma once
#include <iostream>
int HP(int hp)
{
    return hp;
}

class GameObj
{
    public:
    virtual std::string id()const=0;
    virtual int hp()const=0;
    friend std::ostream& operator<<(std::ostream& o,const 
    GameObj& Obj)
    {
        Obj.out(o);
        return o;
    }
    virtual void out(std::ostream& o)const=0;
    virtual ~GameObj()
    {} 
   
};

class Character:public virtual GameObj
{   
    public:
    Character(){}
     Character(int hp,std::string name, std::string id):_hp{hp},_name{name},_id{id}
        {}
        ~Character()
        {}
        int hp()const
        {
           return _hp;
        }
        std::string id()const
        {
            return _id;
        }
        void out(std::ostream& o)const
        {
            o<<std::string("Bad Guy: ");
        }
        void hop()
        {}
        protected:
        std::string _name,_id;
        int _hp;
        
};

class Player:public Character
{
    public:
        Player(int hp,std::string name, std::string id):_hp{hp},_name{name},_id{id}
        {}
        ~Player()
        {}
        int hp()const
        {
            return _hp;
        }
        std::string id()const
        {
            return _id;
        }
        void out(std::ostream& o)const
        {
            o<<std::string("Player ")<<_name<<std::string(" ma [")<<_hp<<std::string(" HP]");

        }
        virtual void hop()
        {}
    protected:
        std::string _name,_id;
        int _hp;
};
class Hurting:public virtual GameObj
{
    public:
    Hurting(){}
     Hurting(int hp, std::string id):_hp{hp},_id{id}
        {}
    ~Hurting(){}
        int hp()const
        {
            return _hp;
        }
        std::string id()const
        {
            return _id;
        }
        void out(std::ostream& o)const
        {
            o<<std::string("Jego uderzenie odbiera: ");
            o<<std::string("[")<<_hp<<std::string(" HP]");
        }
        protected:
        std::string _id;
        int _hp;
   

};

class Bomb:public Hurting
{
     public:
     Bomb(int hp, std::string id):Hurting(hp,id)
        {}
        ~Bomb(){}
       int hp()const
        {
            return Hurting::hp();
        }
        std::string id()const
        {
            return Hurting::id();
        }
        void out(std::ostream& o)const
        {
            o<<std::string("Jego uderzenie odbiera: ");
            o<<std::string("[")<<Hurting::hp()<<std::string(" HP]");
        }
        
};


class Boss:public Hurting,public Character
{
     public:
     Boss()
     {}
     Boss(int hp,std::string name,int hp_2,std::string id):Hurting(hp,name,hp_2,id)
        {}
        ~Boss()
        {}
        int hp()const
        {
            return Hurting::hp();
        }
         std::string id()const
        {
            return Hurting::id();
        }
        void out(std::ostream& o)const
        {
            Hurting::out(o)
        }
        private:
        int _hp;
        int _hp_2;
        std::string _id;
        std::string _name;
        
};
