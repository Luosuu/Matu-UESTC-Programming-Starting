#include <Shape.h>
#define pi 3.14
class Rectangle:public Shape
{
public:
    double length;
    double width;
    Rectangle(double l,double w)
    {
        length =l;
        width = w;
    }
    virtual double GetArea()override
    {
        return length*width;
    }
    virtual double GetPerimeter()override{
        return 2*length+2*width;
    }

};
class Circle:public Shape
{
public:
    double r;
    Circle(double r)
    {
        this->r = r;
    }
    virtual double GetArea()override{
        return pi*r*r;
    }
    virtual double GetPerimeter()override{
        return 2*pi*r;
    }

};
Shape * Shape::createRectangle(double l,double w){return new Rectangle(l,w);}
Shape * Shape::createCircle(double r){return new Circle(r);}