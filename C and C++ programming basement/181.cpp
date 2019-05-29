#include <stdio.h>

int sum(int a, int b)
{
    int t ;
    t = a + b ;
    return(t);
}
int main()
{
    int x ,y, p;
    scanf("%d,%d",&x,&y);
    p = sum(x,y);
    printf("%d\n",p);
    return 0;
}