#include"student.h"
#include<iostream>
#include<string>
void person::set_all(string name, string age, string sex)
{
	this->age = age;
	this->name = name;
	this->sex = sex;
}
string person::get_name() { return name; }//得到学生的姓名
string person::get_age() { return age; }//得到学生年龄
string person::get_sex(){return sex;}
void Student::set_scores(int ID,double Cpp_grade)
{
	this->ID = ID;
	this->Cpp_grade = Cpp_grade;
}
void Student::set_num(int n) { num = n; }//设置学生编
void Student::get_scores(double* Cpp_grade1)
{
	*Cpp_grade1 = Cpp_grade;
}
int Student::get_ID() { return ID; }//得到学生的学号

int Student::get_num() { return num; }//得到学生的编号
void Student::display()
{
	cout<<ID<<"\t"<<Cpp_grade;
}