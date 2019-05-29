#include <stdio.h>
int main()
{
    const int n=10;
    int i,j,array[n],temp;
    for(i=0;i<10;i++)
        scanf("%d",&array[i]);
    for(i=0;i<=n-1;i++)
        for(j=i+1;j<n;j++)
            if(array[i]>array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
    for(i=0;i<=n-1;i++)
    {
        printf("%d",array[i]);
        if(i==n-1)break;
        printf(",");
    }
}
