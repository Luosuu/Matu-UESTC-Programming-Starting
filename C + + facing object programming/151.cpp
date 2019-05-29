#include <Building.h>
class TeachBuilding : public Building{
public:
    char function[20];
    TeachBuilding(char *name,int floor,int room,int area,char *function)
            :Building(name,floor,room,area)
    {
        strcpy(this->function,function);
    }
    void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"Floor:"<<floor<<endl;
        cout<<"Room:"<<room<<endl;
        cout<<"Area:"<<area<<endl;
        cout<<"Function:"<<function<<endl;
    }
};
class DormBuilding:public Building{
public:
    int peoples;
    DormBuilding(char *name,int floor,int room,int area,int peoples)
            :Building(name,floor,room,area)
    {

        this->peoples = peoples;
    }
    void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"Floor:"<<floor<<endl;
        cout<<"Room:"<<room<<endl;
        cout<<"Area:"<<area<<endl;
        cout << "Peoples:"<<peoples<<endl;
    }
};
Building* Building::createTeachBuilding(char *name,int floor,int room,int area,char *function){
    return  new TeachBuilding(name,floor,room,area,function);
}

Building * Building::creatDormBuilding(char *name,int floor,int room,int area,int peoples){
    return new DormBuilding(name,floor,room,area,peoples);
}
