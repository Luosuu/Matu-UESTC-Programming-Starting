#include <stdio.h>
#include <string.h>
int main()
{
    char a[999];
    int n = 0, t = 0;
    scanf("%s",a);
    for(int i = 0;a[i]!='\0';i++)
    {
        if(a[i] == 'a')      //����a�ĸ���
            n++;
        else if(a[i] == 'd')   //����d�ĸ���
            t++;
    }
    printf("a:%d,d:%d",n,t);
    return 0;
}
