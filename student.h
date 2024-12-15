#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<iostream>
#include<string>
using namespace std;
class person
{
public:
    string name;
    string age;
    string sex;
    person() { name = "0"; age = "0", sex = "不详";  }
    virtual void display() = 0;
    void set_all(string name, string age, string sex); 
    string get_name();//得到学生的姓名
    string get_age();//得到学生年龄
    string get_sex();//得到学生性别,男女读出
};
class Student:public person
{
private:
    int ID;//学号
    double Cpp_grade;//C++成绩
    int num;//学生编号
public:
    Student() :person(){ ID = 0;Cpp_grade = 0; }
    void set_scores(int ID,double Cpp_grade);//设置学生的各科成绩
    void set_num(int n);//设置学生编号
    void get_scores(double* Cpp_grade1);//得到学生的各科成绩
    int get_ID();//得到学生的学号
    int get_num();//得到学生的编号
    void display();
};
#endif
