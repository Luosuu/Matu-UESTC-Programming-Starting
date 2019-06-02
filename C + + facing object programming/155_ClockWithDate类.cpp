#include <ClockAndDate.h>
int Date:: days(int year,int month)
{
	if(month==2)
	{
		if(year%4==0&&year%100!=0||year%400==0)
	{
		return 29;
	} 
	else
	return 28;
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		return 31;
	}
	else 
	return 30;
}
void Date::NewDay()
{
	if(month==2)
	{
		if(year%4==0&&year%100!=0||year%400==0)
		{
			if(day==29)
			day=1;
			else if(day>0&&day<29)
			day+=1;
		}
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		if(day==31)
		day=1;
		else if(day>0&&day<31)
		day+=1;	
	}
	else
	{
		if(day==30)
		day=1;
		else if(day>0&&day<30)
		day+=1;
	}
}
class ClockWithDate:public Clock,public Date{
	public:
		ClockWithDate(int h,int m,int s,int year,int month,int day):Clock(h,m,s),Date(year,month,day){	}
		void showTime(){
       Clock::showTime();
       Date::display();}
       void run(){
       	second++;
       	if(second>59)
       	{
       		second=0;
       		minute++;
       		if(minute>59)
       		{
       			minute=0;
       			hour++;
       			if(hour>23)
       			{
       				hour=0;
       				if(month==2)
       				{
       					if(year%4==0&&year%100!=0||year%400==0)
       					{
       						if(day>0&&day<29)
       						{
       							day++;
       						}
       						else if(day==29)
       						{
       							day=1;
       							month=3;
       						}
       					}
       					else 
       					{
       					if(day>0&&day<28)
       						{
       							day++;
       						}
       						else if(day==28)
       						{
       							day=1;
       							month=3;
       						}
       					}
       				}
       				else if(month==1||month==3||month==5||month==7||month==8||month==10)
       				{
       						if(day>0&&day<31)
       						{
       							day++;
       						}
       						else if(day==31)
       						{
       							day=1;
       							month++;
       						}
       				}
       				else if(month==12)
       				{
       						if(day>0&&day<31)
       						{
       							day++;
       						}
       						else if(day==31)
       						{
       							day=1;
       							month=1;
       							year++;
       						}
       				}
       				else
       				{
       					if(day>0&&day<30)
       						{
       							day++;
       						}
       						else if(day==30)
       						{
       							day=1;
       							month++;
       						}
       				}
       			}
       		}
       	}
       }
};
Clock* Clock::createClockWithDate(int h,int m,int s,int year,int month,int day){
	return new ClockWithDate(h,m,s,year,month,day);
}
