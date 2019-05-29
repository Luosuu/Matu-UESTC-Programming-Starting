#include<stdio.h>
int main()
{
	char str1[100],str2[200];
	char *p,*q;
	int n=0;
	gets(str1);
	p=str1;
	q=str2;
	do
	{
		*q++=*p++;
		n++;
		if(n==2)
		{
			n=0;
			if(*p!='\0')
			{
			*q='*';
			q++;
			}
		}
	}while(*p!='\0');
		*q='\0';
	printf("%s\n",str2);
    return 0;
}