#include<iostream>
#include<string>
using namespace std;
//主界面
void menu()
{
	cout << "\n\n\t---------学生成绩管理系统----------" << endl;
	cout << "\t\t1、读取数据功能" << endl;
	cout << "\t\t2、数据操作功能" << endl;
	cout << "\t\t3、数据保存功能" << endl;
	cout << "\t\t4、退出" << endl << endl;
	return;
}
//信息操作界面
void menu1()
{
	cout << "\n\n\t----------数据操作功能----------" << endl;
	cout << "\t注：学号为四位学号，如“0001”" << endl;
	cout << "\t\t1、载入txt文件数据" << endl;
	cout << "\t\t2、增加学生信息" << endl;
	cout << "\t\t3、删除学生信息" << endl;
	cout << "\t\t4、修改学生信息" << endl;
	cout << "\t\t5、排序学生信息" << endl;
	cout << "\t\t6、统计学生信息" << endl;
	cout << "\t\t7、查询学生信息" << endl;
	cout << "\t\t8、返回" << endl;
	return;
}
//查询界面
void menu2()
{
	cout << "\n\n\t----------信息查询功能----------" << endl;
	cout << "\t\t1、按姓名查询" << endl;
	cout << "\t\t2、按学号查询" << endl;
	cout << "\t\t3、返回" << endl;
	return;
}
//统计界面
void menu3()
{
	cout << "\n\n\t-----------统计功能-----------" << endl;
	cout << "\t\t1、对成绩进行分段统计" << endl;
	cout << "\t\t2、对全部学生成绩进行等级评定" << endl;
	cout << "\t\t3、平均成绩" << endl;
	cout << "\t\t4、计算及格率" << endl;
	cout << "\t\t5、统计男女生人数" << endl;
	cout << "\t\t6、返回" << endl;
	return;
}
//排序界面
void menu4()
{
	cout << "\n\n\t----------排序功能----------" << endl;
	cout << "\t\t1、成绩降序" << endl;
	cout << "\t\t2、成绩升序" << endl;
	cout << "\t\t3、学号降序" << endl;
	cout << "\t\t4、学号升序" << endl;
	cout << "\t\t5、姓名降序" << endl;
	cout << "\t\t6、姓名升序" << endl;
	cout << "\t\t7、返回" << endl;
	return;
}
