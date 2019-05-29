#include <Location.h>
Location &Location::operator +(Location &offset)
{
    int x1 = this->x+offset.x;
    int y1 = this->y+offset.y;
    Location tt(x1,y1);
    return tt;
};


Location &Location::operator -(Location &offset)
{
    int x1 = this->x-offset.x;
    int y1 = this->y-offset.y;
    Location tt(x1,y1);
    return tt;
};