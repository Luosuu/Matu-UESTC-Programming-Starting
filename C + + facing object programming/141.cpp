#include <iostream>
#include <stdio.h>
using namespace std;
class Student{
public:
    char num[12];
    char name[10];
    double grade[3];
    void display();
    double average1(Student *a,Student *b,Student *c);
    double average2(Student *a,Student *b,Student *c);
    double average3(Student *a,Student *b,Student *c);
    Student(char *name1,char *num1, int a,int b, int c);
};
void Student::display() {
    printf("%s %s ",name,num);
    cout<<grade[0]<<" "<<grade[1]<<" "<<grade[2]<<endl;
};

double Student::average1(Student *a,Student *b,Student *c) {
    return (a->grade[0]+b->grade[0]+c->grade[0])/3;
};
double Student::average2(Student *a,Student *b,Student *c) {
    return (a->grade[1]+b->grade[1]+c->grade[1])/3;
};
double Student::average3(Student *a,Student *b,Student *c) {
    return (a->grade[2]+b->grade[2]+c->grade[2])/3;
};
Student::Student(char *name1,char *num1, int a,int b, int c) {
    //*name = *name1;
    //*num = *num1;
    strcpy(name,name1);
    strcpy(num,num1);
    grade[0] = a;
    grade[1] = b;
    grade[2] = c;
}
int main(){
    Student *stu1,*stu2,*stu3;
    char name1[10],name2[10],name3[10];
    char num1[12],num2[12],num3[12];
    int grade1[3],grade2[3],grade3[3];
    cin>>name1>>num1>>grade1[0]>>grade1[1]>>grade1[2];
    cin>>name2>>num2>>grade2[0]>>grade2[1]>>grade2[2];
    cin>>name3>>num3>>grade3[0]>>grade3[1]>>grade3[2];
    stu1 = new Student(name1,num1,grade1[0],grade1[1],grade1[2]);
    stu2 = new Student(name2,num2,grade2[0],grade2[1],grade2[2]);
    stu3 = new Student(name3,num3,grade3[0],grade3[1],grade3[2]);

    stu1->display();
    stu2->display();
    stu3->display();
    

    cout<<"The average grade of course1:"<<stu2->average1(stu1,stu2,stu3)<<endl;
    cout<<"The average grade of course2:"<<stu2->average2(stu1,stu2,stu3)<<endl;
    cout<<"The average grade of course3:"<<stu2->average3(stu1,stu2,stu3)<<endl;
    return 0;
}