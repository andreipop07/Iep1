#include<iostream>
#include"Villa.cpp"


class Apartment:public Villa{
    protected:
    std::string scale;

    public:
    Apartment(const std::string &scl, const std::string &court, const int &entr, const  int &fl, const std::string &clr, const std::string &loc , const std::string &st)
    :Villa(court, entr, fl, clr, loc, st),
    scale(scl){
        std::cout<<"Apartment constructor"<<std::endl;
    }

    //Apartment(const Apartment &a);
        
    Apartment& operator=(const Apartment& a){
        if(this==&a){
            std::cout<<"Self Apartment"<<std::endl;
        
            return *this;
        }
        std::cout<<"Copy assignment operator Apartment"<<std::endl;

        House::operator=(a);
        scale = a.scale;
        return *this;
    }

    Apartment& operator+=(const Apartment& a){
        std::cout<<"Add operator Apartment"<<std::endl;
        House::operator+=(a);
        scale += a.scale;
        return *this;
    }    

    void lightOn(){
        Villa::lightOn();
        std::cout<<"Welcome to apartment"<<std::endl;
    }

    void inspect(){
        House::inspect();
        std::cout<<"It is a spacious apartment"<<std::endl;
    }

    void getLocation(){

        std::cout<<"Location of apartment: "<<this->location<<std::endl;
    }

    void setScale(const std::string &newScale){
        this->scale = newScale;
    }

    void getScale(){
        std::cout<<"Apartment scale: "<<this->scale<<std::endl;
    }

    ~Apartment(){
        std::cout<<"Destructor Apartment"<<std::endl;
    }
};