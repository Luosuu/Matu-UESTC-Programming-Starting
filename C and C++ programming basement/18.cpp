#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,i=2,p=1;
    scanf("%d",&n);
    if (n<=3) {
        printf("error");
    }
    else for(;i<=sqrt((float)n);++i)
    { if (n%i==0)
    { p=0;
        break;}}
    if(p==0) printf("no");
    else printf("yes");
    return 0;
}
