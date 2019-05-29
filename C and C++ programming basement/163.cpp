#include<iostream>
using namespace std;
class Date{
public:
	Date(int y=1996,int m=1,int d=1)
	{
		day = d;
		month = m;
		year = y;
		if (m>12 || m<1)
		{
			month=1;
		}
		if (d>days(y,m))
		{
			cout<<"Invalid day!"<<endl;
			day=1;
		}
	};
	friend ostream & operator<<(ostream & out ,Date & date)
	{
		date.display();
		return out;
	}
	int days(int y,int m);
	void display()
	{
		cout<<year<<"-"<<month<<"-"<<day<<endl;
	}
private:
	int year;
	int month;
	int day;
};
int Date::days(int y,int m)
{
	int dd=0;
	if(m!=2)
		{
			if(m==1 || m==3|| m==5|| m==7|| m==8|| m==10|| m==12)
				dd=31;
			else  dd=30;
		}
	else 
	{
		if(y%4==0 && y%100!=0 || y%400==0)
			dd=29;
		else dd=28;
	}
	return dd;
}
int main()
{
     int y,m,d;
	 cin>>y>>m>>d;
	 Date dt(y,m,d);
	 cout<<dt;
	 system("pause");
	 return 0;
}