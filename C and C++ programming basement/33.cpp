#include <stdio.h>
#include <string.h>
void my_strcpy(char * des,char * source)
{
    if(des == NULL||source == NULL)
    {
        printf("error");
        return;
    }
    unsigned long int n = strlen(source);
    for(int i = 0;i<n;i++)
    {
        if(source+i==des)
        {
            printf("error");
            return;
        }
        else if(des + i ==source)
        {
            printf("error");
            return;
        }
    }
    for(int i = 0;i < n ;i++)
    {
        des[i] = source[i];
    }
}
