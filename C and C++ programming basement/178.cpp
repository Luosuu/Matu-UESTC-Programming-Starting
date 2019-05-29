#include <stdio.h>
#include<stdlib.h>
int volume(int a,int b,int c)
{
	int p;
	p=a * b * c;
	return(p);
}
int main()
{
	int x,y,z,v;
	scanf("%d%d%d",&x,&y,&z);
	v = volume(x,y,z);
	printf("%d",v);
	system("pause");
	return 0;
}
