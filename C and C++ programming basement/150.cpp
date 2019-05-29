#include <iostream>
using namespace std;
const float pi=3.14;
class Point{
public:
	Point(float xx, float yy){
		x = xx;
		y =yy;
	}
private:
	float x;
	float y;
};

class Rectangle :public Point{
public:
	Rectangle(float xx,float yy,float w,float h);
	float Area();
private:
	float width;
	float high;
};

class Circle:public Point{
public:
	Circle(float xx,float yy,float r);
	float Area();
private:
	float radius;
};

Rectangle::Rectangle(float xx,float yy,float w,float h):Point(xx,yy)
{
	width=w,high=h;
}
Circle::Circle(float xx,float yy,float r):Point(xx,yy)
{
	radius=r;
}
float Rectangle::Area()
{
	return width*high;
}
float Circle::Area()
{
	return radius*radius*pi;
}