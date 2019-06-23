#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[20];
	int  sex;
	int  birth;
	int  C, W;
	float height;
};
int main()
{
	struct student stu[10];
	int n,i;
	int C_average=0, C_max=0, C_min,
		W_average=0, W_max=0, W_min;
	scanf_s("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf_s("%s %d %d %f %d %d",stu[i].name,20, &stu[i].sex, &stu[i].birth, &stu[i].height, &stu[i].C, &stu[i].W);
		C_average += stu[i].C ,  W_average += stu[i].W;
		if (C_max  < stu[i].C)   C_max  = stu[i].C;
		if (W_max  < stu[i].W)   W_max  = stu[i].W;
	}
	C_min = stu[0].C, W_min = stu[0].W;
	for (i = 0; i < n; ++i)
	{
		if (C_min > stu[i].C)   C_min = stu[i].C;
		if (W_min > stu[i].W)   W_min = stu[i].W;
	}
	C_average /= n , W_average /= n;
	printf("C_average:%d\nC_max:%d\n",C_average,C_max);               
	for (i = 0; i < n; ++i)
	{
		if (stu[i].C == C_max)
		printf("%s %d %d %.2f %d %d\n", stu[i].name, stu[i].sex, stu[i].birth, stu[i].height, stu[i].C, stu[i].W);
	}
	printf("C_min:%d\n", C_min);
	printf("Calculus_average:%d\nCalculus_max:%d\n", W_average, W_max);
	for (i = 0; i < n; ++i)
	{
		if (stu[i].W == W_max)
		printf("%s %d %d %.2f %d %d\n", stu[i].name, stu[i].sex, stu[i].birth, stu[i].height, stu[i].C, stu[i].W);
	}
	printf("Calculus_min:%d\n", W_min);
	system("pause");
	return 0;
}
