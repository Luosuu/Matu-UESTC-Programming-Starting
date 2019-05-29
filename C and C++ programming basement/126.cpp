#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,t=1;
	scanf_s("%d",&n);
	if(n<13)
	{
	  for(int i=1;i<=n;++i)
	  {
		t=t*i;
	  }
	  printf("%d!=%d",n,t);
	}
	else 
	{
	    int n=12;
		for(int i=1;i<=n;++i)
	     {
	 	       t=t*i;
	     }
		printf("%d!=%d",n,t);
	}
	system("pause");
	return 0;
}
