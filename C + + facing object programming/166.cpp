#include <Vehicle.h>
class Car:public Vehicle
{
public:
    Car(){
        cout <<"Car constructor..."<<endl;
        x = 0;
    }
    ~Car(){
        cout<<"Car destructor..."<<endl;
    }
    void display()const{
        cout << "This is a car!"<<endl;
    }
    int x;

};
class Boat:public Vehicle
{
public:
    Boat(){
        cout << "Boat constructor..."<<endl;
    }
    ~Boat(){
        cout << "Boat destructor..."<<endl;
    }
    void display()const{
        cout << "This is a boat!"<<endl;
    }
};
class Truck:public Vehicle
{
public:
    Truck(){
        cout << "Truck constructor..."<<endl;
    }

    ~Truck(){
        cout<<"Truck destructor..."<<endl;
    }
    void display()const{
        cout << "This is a truck!"<<endl;
    }
};

Vehicle * Vehicle::createCar(){return new Car();}
Vehicle * Vehicle::createTruck(){return new Truck();}
Vehicle * Vehicle::createBoat(){return new Boat();}