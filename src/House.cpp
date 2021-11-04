#include<iostream>

class House{

    protected:

    int entries;
    int floors;
    std::string color;
    std::string location;
    std::string style;

    public:
    House(const int &entr, const  int &fl, const std::string &clr, const std::string &loc , const std::string &st)
    :entries(entr),
    floors(fl),
    color(clr),
    location(loc),
    style(st){
        std::cout<<"House constructor"<<std::endl;
    }
    
    House(const House &h)=delete;
        
    House& operator=(const House& h)=delete;
    
    void setColor(const std::string &clr){
        this->color = clr;
    }

    virtual void lightOn(){
        std::cout<<"The light was on."<<std::endl;
    } 

    void getLocation(){
        std::cout<<"House location: "<<this->location<<std::endl;
    }

    void getColor(){
        std::cout<<"House color: "<<this->color<<std::endl;
    }

    void getStyle(){
        std::cout<<"House style: "<<this->style<<std::endl;
    }

    void getFloors(){
        std::cout<<"Number of floors: "<<this->floors<<std::endl;
    }

    virtual void inspect(){
        std::cout<<"Take a look at this house"<<std::endl;
    }

    ~House(){
        std::cout<<"Desctructor House"<<std::endl;
    }

};