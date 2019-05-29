#include <Clock.h>

class NewClock:public Clock{
public:
    void showTime() {
        if (getHour() <= 11)
            cout << "Now:" << getHour() << ":" << getMinute() << ":" << getSecond() << "AM" << endl;
        if (getHour() > 11) {
            int h = getHour() - 12;
            cout << "Now:" << h << ":" << getMinute() << ":" << getSecond() << "PM" << endl;
        }
    }

        NewClock(int h,int m,int s);
};
NewClock::NewClock(int h, int m, int s) :Clock(h,m,s){};

Clock* Clock::createNewClock(int h, int m, int s) {
    return new NewClock(h,m,s);
};