#include <stdio.h>
#include <math.h>
int main()
{
    double x,n,ans=1;
    scanf("%lf%lf", &x, &n);
    if (n<0) {
        printf("error");
    }
    else for(int i=1; i<=n; i++)
    {
        double fac = pow(x, i);
        for (int j=1; j<=i; j++)
        {
            fac = fac/j;
        }
        ans+=fac;
    }
    printf("%.6f",ans);
    
}
