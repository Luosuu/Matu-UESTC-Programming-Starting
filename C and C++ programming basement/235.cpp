#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int * p = (int*)malloc(n*sizeof(int));
    int * q = p;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",q+i);
    }
    for(int i = 0; i<n;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(*(q+j)>*(q+j+1))
            {
                int s = *(q+j);
                *(q+j)=*(q+j+1);
                *(q+j+1)=s;
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        printf("%d",*(p+i));
        if(i<n-1)
        {
            printf(",");
        }
    }
    }
