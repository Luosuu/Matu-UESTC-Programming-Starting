#include <stdio.h>
 
int main()
{
	char sentence[256]={'\0'};
	int isSpace=1;
	int i=0;	
	int wordCount=0;

	gets(sentence);
	
	for( ;'\0' != sentence[i];i++)
	{
		
		if(' '== sentence[i])
			isSpace=1;//±êÖ¾Î»
		else if(isSpace == 1)
		{
			isSpace=0;
			wordCount++;
		}
	}
	printf("%d",wordCount);
}
