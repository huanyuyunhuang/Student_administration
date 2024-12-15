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
    person() { name = "0"; age = "0", sex = "����";  }
    virtual void display() = 0;
    void set_all(string name, string age, string sex); 
    string get_name();//�õ�ѧ��������
    string get_age();//�õ�ѧ������
    string get_sex();//�õ�ѧ���Ա�,��Ů����
};
class Student:public person
{
private:
    int ID;//ѧ��
    double Cpp_grade;//C++�ɼ�
    int num;//ѧ�����
public:
    Student() :person(){ ID = 0;Cpp_grade = 0; }
    void set_scores(int ID,double Cpp_grade);//����ѧ���ĸ��Ƴɼ�
    void set_num(int n);//����ѧ�����
    void get_scores(double* Cpp_grade1);//�õ�ѧ���ĸ��Ƴɼ�
    int get_ID();//�õ�ѧ����ѧ��
    int get_num();//�õ�ѧ���ı��
    void display();
};
#endif
