#include <iostream>
#include <math.h>
using namespace std;
class Ctriangle{
public:
    double a,b,c;
    void display();

    Ctriangle(double x,double y,double z)
    {
        a = x;
        b = y;
        c = z;
    }
    double GetPerimeter();
    double GetArea();
};
void Ctriangle::display()
        {
    cout<<"Ctriangle:a="<<a<<",b="<<b<<",c="<<c<<endl;
        };
double Ctriangle::GetPerimeter() {
    return a+b+c;
};
double Ctriangle::GetArea() {
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
};

int main(){
    double a,b,c;
    cin>>a>>b>>c;
    Ctriangle T(a,b,c);
    T.display();
    cout<<"Perimeter:"<<T.GetPerimeter()<<endl;
    cout<<"Area:"<<T.GetArea()<<endl;
    return 0;
}