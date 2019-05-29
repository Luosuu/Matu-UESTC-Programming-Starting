#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a ;
	if(a%2==0) {cout << "error"<<endl;return 0;}
	int t = 0;
	while(a>0)
	{
	for(int i = 0;i<t;i++)
	{
		cout<<" ";
	}
	for(int i = 0;i<a;i++)
	{
		cout << "*";
		if(i+1==a) cout<<endl;
	}
	t++;
	a-=2;
	};
	
}