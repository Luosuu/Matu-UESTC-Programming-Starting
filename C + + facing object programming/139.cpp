#include <iostream>
#include "CDate.h"
using namespace std;
Date::Date(int y, int m , int d) {
    year = y;
    month = m;
    day = d;
    if (m < 1 || m > 12) {
        cout << "Invalid month!" << endl;
        month = 1;
    }
    if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day<1||day>31))
    {
        cout << "Invalid day!"<<endl;
        day = 1;
    }
    if((month==4||month==6||month==9||month==11)&&(day>30||day<1))
    {
        cout << "Invalid day!"<<endl;
        day = 1;
    }
    if(month==2)
    {
        if((year%4==0&&year%100!=0)||year%400==0)
        {
            if((day>29||day<1))
            {
            cout << "Invalid day!"<<endl;
            day = 1;
            }
        }
        else
        {
            if(day>28||day<1)
            {
                cout << "Invalid day!" << endl;
                day = 1;
            }
    }

    }
};
int Date::days(int year,int month)
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
    else if(month==4||month==6||month==9||month==11)return 30;
    else if(month==2)
    {
        if((year%4==0 && year%100!=0)||year%400==0)return 29;
        else return 28;
    }


};
void Date::NewDay() {
    day++;
    if((month==1||month==3||month==5||month==7||month==8||month==10)&&day==32)
    {
        month++;
        day =1 ;
    }
    else if(month==12&&day==32)
    {
        year++;
        month=1;
        day =1 ;
    }
    else if((month==4||month==6||month==9||month==11)&&day==31)
    {
        month++;
        day = 1;
    }
    else if(month==2)
    {
        if((year%4==0&&year%100!=0)||year%400==0)
        {
            if(day==30) {
                month++;
                day = 1;
            }
        }
        else{
            if(day==29)
            {month++;day=1;}
        }
    }


};