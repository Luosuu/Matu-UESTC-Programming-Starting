#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef struct student
{
	int id;
	char name[50];
	float chinese;
	float math;
	float english;
	float sum;
}student;
/*����������ַ���name��Ҫ�򿪵��ļ����ơ����������stu�Ƕ�����ѧ������ϸ��Ϣ�������ķ���ֵ��ѧ������.�κδ��󷵻�0*/
int ReadStuInfoFromFile(char *name, student **stu);
/*���������stu��ȫ��ѧ����Ϣ��n�����������������3��ƽ���ɼ�������������noPassStudent,����������m.�����ɹ�����0��ʧ�ܷ���-1*/
int NoPass(student stu[], int n, student **noPassStudent, int *m);
/*���������stu��ȫ��ѧ����Ϣ��n�����������������3��ƽ���ɼ�����������PassStudent,��������m.�����ɹ�����0��ʧ�ܷ���-1*/
int Pass(student stu[], int n, student **PassStudent, int *m);
/*���������stu��ȫ��ѧ����Ϣ��n����������������������ܷ�/ƽ���������Ľ��Ҳ�洢��stu��.�����ɹ�����0��ʧ�ܷ���-1*/
int SortStudents(student stu[], int n);
/*���������stu��ȫ��ѧ����Ϣ��n�������������ɹ�����0��ʧ�ܷ���-1������������ͼ�ϲ�����м�⣬ֻ�ǹ�ͬѧ�ǵ���ʹ�á�*/
int PrintStudents(student stu[], int n);
/*���������stu��ȫ��ѧ����Ϣ��n������,id�Ǵ����ҵ�ѧ�š����������rank���ڰ��ϵ�������stu�����ѧ������ϸ��Ϣ������ֵ�����ҳɹ�����0��ʧ�ܷ���-1*/
int SearchStudent(student stu[], int n, int id,int *rank, student *rstu);
int ReadStuInfoFromFile(char *name, student **stu1)
{
    if(name){
    FILE* fp;
    fp = fopen(name,"rb");//stuScores.txt
    unsigned int num = 0;
    fread(&num,sizeof(int),1,fp);
    *stu1 = (struct student*)malloc(num*sizeof(struct student));
    for(int i = 0;i<num;i++)
    {
        fread(&((*stu1)[i]), sizeof(struct student),1,fp);
        (*stu1)[i].sum = (*stu1)[i].math + (*stu1)[i].english + (*stu1)[i].chinese;
    }
    fclose(fp);
    return num;
    }
    else return 0;
};
int NoPass(student stu1[], int n, student **noPassStudent, int *m)
{
    if(n!=0&&stu1)
    {

        //m = (int*)malloc(sizeof(int));
        float sum = 0;
        int count =0;
        for(int i =0;i<n;i++)
        {
            sum += stu1[i].sum;
        }
        sum = sum/n;
        *noPassStudent = (struct student*)malloc(n*sizeof(struct student));
        for(int i = 0;i<n;i++)
        {
            if(stu1[i].sum<sum)
            {
                noPassStudent[count] = &(*(stu1+i));
                count++;
            }
        }
        *m = count;
        /*for(int i = 0;i<*m;i++)
        {
            cout<<noPassStudent[i]->sum<<endl;
        }*/

        return 0;
    }
    else return -1;

};
int Pass(student stu[], int n, student **PassStudent, int *m)
{
    if(n!=0&&stu)
    {
        //SortStudents(stu,n);
        //m = (int*)malloc(sizeof(int));
        int count = 0;
        float sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum += stu[i].sum;
        }
        sum = sum/n;
        *PassStudent = (struct student*)malloc(n*sizeof(struct student));
        for(int i = 0;i<n;i++)
        {
            if(stu[i].sum > sum)
            {
                PassStudent[count] = &stu[i];
                count++;
            }
        }
        *m = count;
        /*for(int i = 0;i<*m;i++)
        {
            cout << PassStudent[i]->sum<<endl;
        }*/

        return 0;
    }
    else return -1;

};
void swap(struct student*a, struct student*b)
{
    struct student temp = *a;
    *a = *b;
    *b = temp;
};
int SortStudents(student stu1[], int n)
{
    if(stu1&&n!=0)
    {
        int i,j;
        for(i = 0;i<n;i++)
        {
            int max = i;
            for(j = i+1;j<n;j++)
                if(stu1[max].sum < stu1[j].sum)
                    max = j;
            swap(&stu1[i],&stu1[max]);
        }
        return 0;
    }
    else return -1;

};
int PrintStudents(student stu[], int n)
{
    if(stu&&n!=0)
    {
        for(int i = 0;i<n;i++)
        {
           cout<<stu[i].id<<"\t"<<stu[i].chinese<<"\t"<<stu[i].english<<"\t"<<stu[i].math<<"\t"<<stu[i].sum<<"\t"<<stu[i].sum/3<<endl;
        }
        return 0;
    }
    else return -1;
};
int SearchStudent(student stu[], int n, int id,int *rank, student *rstu)
{
    if(stu&&n!=0) {
        rank = (int*)malloc(sizeof(int));
        //rstu = (struct student*)malloc(sizeof(struct student));
        SortStudents(stu, n);
        for (int i = 0; i < n; i++) {
            if (id == stu[i].id) {
                *rank = i + 1;
                *rstu = stu[i];
                //printf("%f",stu[i].sum);
                return 0;
            }
        }
        return -1;
    }
    else return -1;
};