#include <iostream>
#define pi 3.14
using namespace std;
class Table{
public:
    float hight;
    float GetHigh();
    Table(int high)
    {
        hight = high;
    }
};
float Table::GetHigh() {
    return hight;
}
class Circle
{
public:
    float radius;
    float GetArea();
    Circle(int radius)
    {
        this->radius = radius;
    }
};
float Circle::GetArea() {
    return pi*radius*radius;
};
class RoundTable:public Circle,public Table{
public:
    char color[20];
    char *GetColor();
    RoundTable(int radius,int high,char*color)
    :Table(high)
    ,Circle(radius)
    {
        strcpy(this->color,color);
    }
};
char* RoundTable::GetColor() {
    return color;
};
int main(){
    float radius,high;
    char color[20];
    cin>>radius>>high>>color;
    RoundTable RT(radius,high,color);
    cout<<"Area:"<<RT.GetArea()<<endl;
    cout<<"High:"<<RT.GetHigh()<<endl;
    cout<<"Color:"<<RT.GetColor()<<endl;
    return 0;
}