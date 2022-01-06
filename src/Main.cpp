#include <iostream>
#include "Apartment.cpp"
#include <memory>

using namespace std;
House* CreateHouseInstance(){
    return (new House(3,2,"yellow","Timisoara","baroc"));
}

void lock(House &h){
    std::cout<<"Locking resource"<<std::endl;
    h.setIsLocked(true);
}
void unlock(House &h){
    std::cout<<"Unlocking resource"<<std::endl;
    h.setIsLocked(false);
}

class LockResource{
    private:
    House &lockPtr;

    public:
    LockResource(House &ptr):
    lockPtr(ptr){
        lock(lockPtr);
    }
    ~LockResource(){
        unlock(lockPtr);
    }
};


int main()
{   

    Villa v1("1200mp",3,2,"green","Arad","Modern");
    std::cout<<std::endl;

    Villa v2("120mp",4,1,"blue","Cluj","Moderna");
    std::cout<<std::endl;

    Villa v3("120mp",4,5,"blue","Cluj","Moderna");
    std::cout<<std::endl;

    Apartment a2("Scara B","100mp",3,3,"Gray","Timisoara","Modern2");
    std::cout<<std::endl;

    Apartment a3("Scara B","100mp",3,3,"Gray","Timisoara","Modern2");
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
    vv1->getFloors();
    *vv1+=v1;
    vv1->getFloors();
    std::cout<<std::endl;

    v1.getFloors();
    v1=v1;
    v1.getFloors();
    v2.getFloors();
    a2.getFloors();
    v1=v2=v3;
    v1.getFloors();
    v2.getFloors();
    v3.getFloors();
    //v1.getFloors();
    v1.getColor();
    v1+=v2+=v3;
    v1.getFloors();
    v1.getColor();

    v2=v3;
    v2.getFloors();
    v2.getColor();


    /*vv1->inspect();
    std::cout<<std::endl;

    a1->getLocation();
    std::cout<<std::endl;

    v1.lightOn();
    std::cout<<std::endl;

    a1->lightOn();
    std::cout<<std::endl;

    a1->inspect();
    std::cout<<std::endl;*/

    delete vv1;
    std::cout<<std::endl;
    delete a1;
    std::cout<<std::endl;

    std::cout<<"auto_ptr "<<std::endl;
    {
        auto_ptr<House> house(CreateHouseInstance());
        house->getColor();
        auto_ptr<House> house2(house);
        house2->getColor();

        //house->getColor();
    }
    std::cout<<std::endl;
    std::cout<<"unique_ptr "<<std::endl;
    {
        unique_ptr<House> uniqueHouse(CreateHouseInstance());
        uniqueHouse->getFloors();
        unique_ptr<House> uniqueHouse2 = move(uniqueHouse);

    }
    std::cout<<std::endl;
    std::cout<<"shared_ptr "<<std::endl;
    {
        shared_ptr<House> sharedHouse(CreateHouseInstance());
        sharedHouse->getFloors();
        std::cout<<"sharedHouse count = "<<sharedHouse.use_count()<<std::endl;
        shared_ptr<House> sharedHouse2(sharedHouse);
        std::cout<<"sharedHouse count = "<<sharedHouse.use_count()<<std::endl;
        sharedHouse2->getColor();
        sharedHouse2->setColor("brown");
        sharedHouse->getColor();

        shared_ptr<House> sharedHouse3=move(sharedHouse); //sharedHouse devine null, transfer de ownership
        std::cout<<"sharedHouse count = "<<sharedHouse.use_count()<<std::endl;
        std::cout<<"sharedHouse3 count = "<<sharedHouse3.use_count()<<std::endl;
        sharedHouse3->setColor("blue");
        sharedHouse3->getColor();

        sharedHouse2->getColor();
        std::cout<<std::endl;
        std::cout<<"weak_ptr"<<std::endl;
        weak_ptr<House> weakHouse(sharedHouse3);
        std::cout<<"sharedHouse3 count = "<<sharedHouse3.use_count()<<std::endl;
        
    }
    std::cout<<std::endl;
    House house1(4,2,"orange","Brasov","stil2");
    LockResource *locked = new LockResource(house1);
    house1.askResource();
    delete locked;
    house1.askResource();
    std::cout<<"Merge"<<std::endl;
    return 0;
}