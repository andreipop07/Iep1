#include<iostream>
#include "House.cpp"

class Villa:public House{

    protected:
    std::string courtYard;

    public:
    Villa(const std::string &court, const int &entr, const  int &fl, const std::string &clr, const std::string &loc , const std::string &st)
    :House(entr, fl, clr, loc, st),
    courtYard(court){
        std::cout<<"Villa constructor"<<std::endl;
    }

    //Villa(const Villa &v);

    Villa& operator=(const Villa& v){
        if(this==&v){
            std::cout<<"Self Villa"<<std::endl;

            return *this;
        }
        std::cout<<"Copy assignment operator Villa"<<std::endl;

        House::operator=(v);
        courtYard = v.courtYard;
        return *this;
    }

    Villa& operator+=(const Villa& v){
        std::cout<<"Add operator Villa"<<std::endl;
        House::operator+=(v);
        courtYard += v.courtYard;
        return *this;
    }

    void getFloors(){
        std::cout<<"Villa number of floors: "<<this->floors<<std::endl;
    }

    void inspect(){
        House::inspect();
        std::cout<<"Has a large courtyard"<<std::endl;
    }

    void lightOn(){
        House::lightOn();
        std::cout<<"Nice Villa!"<<std::endl;
    }

    virtual ~Villa(){
        std::cout<<"Destructor Villa"<<std::endl;
    }
};