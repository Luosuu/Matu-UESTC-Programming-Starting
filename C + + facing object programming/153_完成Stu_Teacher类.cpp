#include<iostream>
#include<cstring> 
using namespace std;
class Person {
public:
    Person(char *name,char sex,char *ID,char *birthday) {
        strcpy(this->name,name);
        this->sex = sex;
        strcpy(this->ID,      ID);
        strcpy(this->birthday,birthday);
    }
    virtual void display() {
        cout << "Name:" << name << endl;
        cout << "Sex:" << sex << endl;
        cout << "ID:" << ID << endl;
        cout << "Birthday:" << birthday << endl;
    }
    Person*createStu_Techer(char *name,char sex,char *ID, char *birthday,char *position,char *major);
    Person*createStudent(char *name,char sex,char *ID,char *birthday,char *major);
    Person*createTeacher(char *name,char sex, char *ID,char *birthday,char *position);
protected:
    char name[20];
    char sex;
    char ID[20];
    char birthday[12];
};

Person*createStu_Techer(char *name,char sex,char *ID, char *birthday,char *position,char *major);
Person*createStudent(char *name,char sex,char *ID,char *birthday,char *major);
Person*createTeacher(char *name,char sex, char *ID,char *birthday,char *position);


class Student : public Person {
public:
    Student(char *name,char sex,char *ID,char *birthday,char *major)
        :Person(name,  sex,  ID,  birthday) {
        strcpy(this->major,major);
    }
    void display() {
        cout << "Major:" << major << endl;
    }
protected:
    char major[20];
};
class Techer : public Person {
public:
    Techer(char *name,char sex,char *ID,char *birthday,char *position) :Person(name,sex,ID,birthday) {
        strcpy(this->position,position);
    }
    virtual void display() {
        cout << "Position:" << position << endl;
    }
protected:
    char position[20];
};
class Stu_Teacher : public Student,public Techer {
public:
    Stu_Teacher(char *name,char sex,char *ID, char *birthday,char *position,char *major)
        :Student(name,sex,ID, birthday,major),Techer(name, sex,ID,birthday,position) {
//        Person(char *name,char sex,char *ID,char *birthday);
//        Student(char *name,char sex,char *ID,char *birthday,char *major);
//        Techer(char *name,char sex,char *ID,char *birthday,char *position);
    }
    void display() {
        cout << "Name:" << Student::name << endl;
        cout << "Sex:" << Student::sex << endl;
        cout << "ID:" << Student::ID << endl;
        cout << "Birthday:" << Student::birthday << endl;
        cout << "Major:" << Student::major << endl;
        cout << "Position:" << Techer::position << endl;
    }
};
Person*Person::createStudent(char *name,char sex,char *ID,char *birthday,char *major) {
    return new Student(name,sex,ID,birthday,major);
}
Person*Person::createTeacher(char *name,char sex, char *ID,char *birthday,char *position) {
    return new Techer(name,sex,ID,birthday,position);
}
Person*Person::createStu_Techer(char *name,char sex,char *ID, char *birthday,char *position,char *major) {
    return (Student*)new Stu_Teacher(name,sex,ID, birthday,position,major);
}