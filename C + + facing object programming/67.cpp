#include <ShapeFactory.h>
class Triangle:public ShapeFactory
{
public:
    int a,b,c;
    Triangle(float a,float b,float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    float Circumstance()
    {
        return a+b+c;
    };
};
class Quadrilateral:public ShapeFactory
{
public:
    float a,b,c,d;
    Quadrilateral(float a,float b,float c,float d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    float Circumstance()
    {
        return a+b+c+d;
    }
};
class Circle:public ShapeFactory
{
public:
    float radius;
    Circle(float radius)
    {
        this->radius = radius;
    };
    float Circumstance()
    {
        return 2*3.14*radius;
    }

};
ShapeFactory * ShapeFactory::Create(float a,float b,float c)
{

    ShapeFactory *p=new Triangle(a,b,c);
    return p;
}
ShapeFactory * ShapeFactory::Create(float a,float b,float c,float d)
{
    ShapeFactory *p=new Quadrilateral(a,b,c,d);
    return p;
}
ShapeFactory *ShapeFactory::Create(float r) {
    ShapeFactory*p = new Circle(r);
    return p;
}