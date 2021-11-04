#include <iostream>
#include "Apartment.cpp"


int main()
{   

    Villa v1("1200mp",3,2,"green","Arad","Modern");
    std::cout<<std::endl;

    Villa *vv1= new Villa("800mp",2,1,"yellow","Timisoara","Craftsman");
    std::cout<<std::endl;
    
    //Villa v3(v1);
    //std::cout<<std::endl;

    Apartment *a1= new Apartment("Scara A","0mp",2,1,"Gray","Timisoara","Modern");
    std::cout<<std::endl;
    //Apartment a3(*a1);
    //std::cout<<std::endl;

    vv1->getColor();
    vv1->setColor("blue");
    vv1->getColor();
    std::cout<<std::endl;

    vv1->inspect();
    std::cout<<std::endl;

    a1->getLocation();
    std::cout<<std::endl;

    v1.lightOn();
    std::cout<<std::endl;

    a1->lightOn();
    std::cout<<std::endl;

    a1->inspect();
    std::cout<<std::endl;

    delete vv1;
    std::cout<<std::endl;
    delete a1;
    std::cout<<std::endl;
    return 0;
}