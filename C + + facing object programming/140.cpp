#include<iostream>
#include"Clock.h"
using namespace std;
Clock::Clock(int h,int m,int s)
{
	if(h<0||h>23) hour=0;
	else hour=h;
	if(m<0||m>59) minute=0;
	else minute=m;
	if(s<0||s>59) second=0;
	else second=s;
}
void Clock::SetAlarm(int h,int m,int s)
{
	if(h>23) Ahour=0;
	else Ahour=h;
	if(m>59) Aminute=0;
	else Aminute=m;
	if(s>59) Asecond=0;
	else Asecond=s;
	return ;
}
void Clock::run()
{
	second+=1;
	if(second>59)
	{second=0;minute+=1;}
	if(minute>59)
	{minute=0;hour+=1;}
	if(hour>23)
	{hour=0;}
	if((hour==Ahour)&&(minute==Aminute)&&(second==Asecond))
		cout<<"Plink!plink!plink!..."<<endl;
	return ;
}