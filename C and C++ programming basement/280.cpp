#include <stdio.h>

int main()
{
    float r ;
    float h ;
    float pi = 3.14;
    float area , volumn;
    scanf("%f %f",&r,&h);
    area = pi*r*r;
    volumn = area*h;
    printf("area=%.2f,volumn=%.2f",area,volumn);
    
}
