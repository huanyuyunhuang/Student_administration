#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include"list.h"
using namespace std;
//外部变量声明
string name;//姓名		
int stuID;//学号
string age;//年龄
string sex;//性别
double cpp;//cpp成绩
void List::build_in()//从文件导入学生信息,并保存在链表中
{
	List* p_now = NULL;//当前节点
	List* p_pass = NULL;//当前节点的前一节点
	Head = NULL;
	int n = 0;//用于统计学生的数量，设置编号
	ifstream out;	//创建文件流对象
	out.open("student.dat", ios::in| ios::binary);
	if (!out)
	{
		cout << "Fail to open the file!" << endl;
	}
	while (1)//打开成功，创建链表保存数据
	{
		if (!(out >> name >> stuID >> sex >> age >> cpp))//从文件中读取数据
			break;
		n++;//编号递增
		p_now = new List;//创建结点
		if (Head == NULL)
			Head = p_now;//保存头指针
		if (p_pass != NULL)
			p_pass->Next = p_now;//将前一个结点的pNext指向当前结点
		//将文件中的数据保存在当前结点
		p_now->stu.set_all( name, age, sex);
		p_now->stu.set_scores(stuID,cpp);//保存成绩
		p_now->stu.set_num(n);//计算总数
		p_now->Next = NULL;
		p_pass = p_now;
	}
	out.close();//关闭文件
}
ostream& operator<<(ostream& output, List* p)
{
	int num = 0;
	name = p->stu.get_name();//获取成员数据信息赋值给外部变量
	stuID = p->stu.get_ID();
	num = p->stu.get_num();
	sex = p->stu.get_sex();
	age = p->stu.get_age();
	p->stu.get_scores(&cpp);//指针传递获取外部变量值
	output << fixed << setprecision(2) <<num<<"\t"<< name << '\t' << setw(4)<<setfill('0')<<stuID << '\t' << sex << '\t'		//fixed,setprecision(2)设置两位小数
		<< age << '\t' << cpp << '\t' << endl;
	return output;
}
void List::traverse_out()//遍历链表，打印学生信息
{
	int n = 0;//n编号
	List* p = Head;
	if (p == NULL) { cout << "链表为空!" << endl; return; }
	cout << "\n编号\t姓名\t学号\t性别\t年龄\tC++\t"  << endl;
	while (p != NULL)
	{
		n++;
		p->stu.set_num(n);//重新设置编号
		cout << p;
		p = p->Next;//设置指针指向下一个结点，下一个节点为NULL时跳出循环,遍历结束
	}
	cout << endl;
}
void List::search_name()//根据姓名来查找学生信息
{
	int flag = 0;//用来标记是否找到对应的学生
	List* p = Head;
	string Name;
	if (p == NULL) { cout << "表格为空！" << endl; return; }
	cout << "请输入你要查询的学生的姓名：";
	cin >> Name;
	while (p != NULL)
	{
		name = p->stu.get_name();
		if (name == Name)//循环过程对name、Name一一比较,成立则从内存获取信息并输出，可以实现同名全输出
		{
			flag++;//查询学生存在是才自加
			cout << "\n该学生的信息如下：" << endl;
			cout << "\n编号\t姓名\t学号\t性别\t年龄\tC++\t" << endl;
			cout << p ;
		}
		p = p->Next;//设置指针指向下一个结点
	}
	if (flag == 0)cout << "没有找到该学生！" << endl;
	else cout << "共得到" << flag << "个结果!" << endl;
}
void List::search_ID()//根据学号来查找学生
{
	int flag = 0;//用来标记是否找到对应的学生
	List* p = Head;
	int id;
	if (p == NULL) { cout << "表格为空！" << endl; return; }
	cout << "请输入你要查询的学生的学号：";
	cin >> id;
	while (p != NULL)//操作同按姓名查找函数
	{
		stuID = p->stu.get_ID();
		if (stuID == id)
		{
			flag++;
			cout << "\n该学生的信息如下：" << endl;
			cout << "\n编号\t姓名\t学号\t性别\t年龄\tC++\t" << endl;
			cout << p;
			break;
		}
		p = p->Next;//设置指针指向下一个结点
	}
	if (flag == 0)
		cout << "没有找到该学生！" << endl;
}
void List::sortID(int flag)//学号升降排序
{
	int ID1, ID2;
	List* p, * q, temp;//temp临时的对象
	if (Head == NULL) { cout << "没有学生信息，无法计算!"; return; }
	if (flag == 1)
	{
		cout << "按学号降序排列如下:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//降序
			for (q = p->Next; q != NULL; q = q->Next)
			{
				ID1 = p->stu.get_ID();
				ID2 = q->stu.get_ID();
				if (ID1 < ID2)
				{
					temp.stu = q->stu;
					q->stu = p->stu;
					p->stu = temp.stu;
				}
			}
	}
	if (flag == 2)
	{
		cout << "按学号升序排列如下:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//升序
			for (q = p->Next; q != NULL; q = q->Next)
			{
				ID1 = p->stu.get_ID();
				ID2 = q->stu.get_ID();
				if (ID1 > ID2)
				{
					temp.stu = q->stu;
					q->stu = p->stu;
					p->stu = temp.stu;
				}
			}
	}
	traverse_out();
}
void List::sortName(int flag)
{
	string Name1, Name2;
	List* p, * q, temp;//temp临时的对象
	if (Head == NULL) { cout << "没有学生信息，无法计算!"; return; }
	if (flag == 1)
	{
		cout << "按姓名降序排列如下:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//降序
			for (q = p->Next; q != NULL; q = q->Next)
			{
				Name1 = p->stu.get_name();
				Name2 = q->stu.get_name();
				if (Name1 < Name2)
				{
					temp.stu = q->stu;
					q->stu = p->stu;
					p->stu = temp.stu;
				}
			}
	}
	if (flag == 2)
	{
		cout << "按姓名升序排列如下:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//升序
			for (q = p->Next; q != NULL; q = q->Next)
			{
				Name1 = p->stu.get_name();
				Name2 = q->stu.get_name();
				if (Name1 > Name2)
				{
					temp.stu = q->stu;
					q->stu = p->stu;
					p->stu = temp.stu;
				}
			}
	}
	traverse_out();
}
void List::separate(bool flag)//根据C++成绩进行分段统计
{
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;//用于统计各分数段的人数
	float upass_rate;//统计不及格率
	double cpp;
	List* p = Head;
	if (p == NULL) { cout << "表格为空!" << endl; return; }
	while (p != NULL)
	{
		p->stu.get_scores(&cpp); 
		if (cpp >= 90 && cpp <= 100)t1++;
		else if (cpp >= 80 && cpp<= 89)t2++;
		else if (cpp >= 70 && cpp <= 79)t3++;
		else if (cpp >= 60 && cpp <= 69)t4++;
		else t5++;
		p = p->Next;//p指向下一个节点
	}
	if (!flag)
	{
		cout << "\nC++成绩分段统计如下:\n"; 
		cout<< "分数段" << "\t人数" << endl;
		cout << "100-90\t" << t1 << "\n89-80\t" << t2 << "\n79-70\t" << t3 << "\n69-60\t" << t4 << "\n59-0\t" << t5 << endl;
	}
	else
	{
		upass_rate = t5 / float(count_num(1));
		upass_rate = 1 - upass_rate;
		cout << "C++成绩及格率为"; 
		cout << setiosflags(ios::fixed) << setprecision(2) << 100 * upass_rate << " %" << endl;
	}
}
void List::count_avg()//计算平均成绩
{
	double Cavg;//平均成绩
	int n = 0;//用于记录学生人数
	double Csum = 0;//科目总分
	List* p = Head;
	if (p == NULL) { cout << "表格为空!" << endl; return; }
	while (p != NULL)
	{
		p->stu.get_scores(&cpp);
		Csum += cpp;
		++n;
		p = p->Next;
	}
	if (n != 0)//判断是否有学生信息
	{
		Cavg = Csum / n;
		cout << "C++的平均成绩如下:" << Cavg << endl;
	}
}
int List::count_num(bool flag)
{
	string sex;
	int women = 0, men = 0;//统计男女生人数
	int n = 0;//用于记录学生人数
	List* p = Head;
	if (p == NULL) { cout << "表格为空!" << endl; return -1; }
	while (p != NULL)
	{
		sex = p->stu.get_sex();//获取性别信息
		if (sex == "男")men++;
		else if (sex == "女") women++;
		++n;
		p = p->Next;
	}
	if(!flag)
		cout << "表中总学生人数为" << n << "\n表中男性人数为:" << men << "\n表中女性人数为:" << women << endl;
	return n;
}
void List::modify()//修改学生的信息
{
	int modifyPos = 0;//位置编号
	int num;//编号
	int flag = 0;//标记是否有对应的编号
	List* p = Head;//指向当前结点的指针
	List* pf = NULL;//指向前一个结点的指针
	cout << "请输入你想修改的信息的位置（位置编号,大于0）：";
	cin >> modifyPos;
	if (p == NULL) { cout << "表内数据为空!"; return; }
	while (p != NULL)//遍历链表
	{
		num = p->stu.get_num();
		if (num == modifyPos)
		{
			flag++;
			cout << "待修改信息如下：" << endl;
			cout << p;
			cout << "请输入修改后的信息:\n" << "姓名\t" << "学号\t" << "性别\t" << "年龄\t" << "C++" << endl;
			cin >> name >> stuID >> sex >> age >> cpp;
			if (stuID <= 0 || stuID > 9999)throw stuID;
			p->stu.set_all(name, age, sex);
			p->stu.set_scores(stuID, cpp);//重新设置各科成绩
			break;
		}
		p = p->Next;//设置指针指向下一个结点
	}
	if (flag == 0)
		cout << "没有找到该学生！" << endl;
}
void List::Delete()//删除学生信息
{
	int deletePos = 0;//位置编号
	int num;//编号
	int flag = 0;//标记是否有对应的编号
	List* p = Head;//指向当前结点的指针
	List* pf = NULL;//指向前一个结点的指针
	int answer;
	cout << "请输入你想删除的学生的编号";
	cin >> deletePos;
	if (p == NULL) { cout << "表格内数据为空!"; return; }
	while (p != NULL)//遍历链表
	{
		num = p->stu.get_num();
		if (num == deletePos)
		{
			flag++;
			cout << "编号\t姓名\t学号\t性别\t年龄\tC++\t"<< endl;
			cout << p;
			cout << "你确定要删除这组信息吗？(1.是2.否)";
			cin >> answer;
			if (answer == 1)
			{
				if (pf == NULL)
				{
					List* temp = p;//暂时保存指向该结点的指针
					Head = p->Next;//跳过当前结点，实现信息的删除
					delete temp;//将其所占内存删除
				}
				else
				{
					List* temp = p;
					pf->Next = p->Next;
					delete temp;
				}
				cout << "删除成功!" << endl;
				break;
			}
			else break;
		}
		pf = p;
		p = p->Next;
	}
	if (flag == 0)cout << "找不到对应的位置!" << endl;
}
void List::add()//增加学生信息
{
	int insertPos = 0;//位置编号
	int num;//编号
	int flag = 0;//标记是否有对应的编号
	List* p = Head;//指向当前结点的指针
	List* pf = NULL;//指向前一个结点的指针
	cout << "请输入你想增加的信息的位置（位置编号,大于0）：";
	cin >> insertPos;
	while (p != NULL)//遍历链表
	{
		num = p->stu.get_num();
		if (num == insertPos)
		{
			flag++;
			List* new_node = new List;//创建一个新的结点
			cout << "请输入新增学生的信息" << endl;
			cout << "姓名\t" << "学号\t" << "性别\t" << "年龄\t" << "C++\t" << endl;
			cin >> name >> stuID >> sex >> age >> cpp; 
			if (stuID <= 0||stuID>9999)throw stuID;
			if (ISsameID(stuID)) { cout << "该学号已拥有，添加失败" << endl; delete new_node; return; }
			new_node->stu.set_all( name, age, sex);
			new_node->stu.set_scores(stuID,cpp);
			if (num == 1)//nex_node顶替头结点
			{
				new_node->Next = Head;
				Head = new_node;
			}
			else if (pf == NULL)
			{
				new_node->Next = p;
				Head->Next = new_node;
				break;
			}
			else
			{
				new_node->Next = p;
				pf->Next = new_node;
				break;
			}
		}
		pf = p;
		p = p->Next;
	}
	if (Head == NULL)
	{
		flag++;
		List* new_node = new List;//创建一个新的结点
		cout << "请输入新增学生的信息" << endl;
		cout << "姓名\t" << "学号\t" << "性别\t" << "年龄\t" << "C++\t" << endl;
		cin >> name >> stuID >> sex >> age >> cpp;
		if (stuID <= 0 || stuID > 9999)throw stuID;
		if (ISsameID(stuID)) { cout << "该学号已拥有，添加失败" << endl; delete new_node; return; }
		new_node->stu.set_all( name, age, sex);
		new_node->stu.set_scores(stuID,cpp);
		Head = new_node;
		new_node->Next = NULL;
	}
	if (flag == 0)
	{
		cout << "请输入新增学生的信息" << endl;
		cout << "姓名\t" << "学号\t" << "性别\t" << "年龄\t" << "C++\t" << endl;
		cin >> name >> stuID >> sex >> age >> cpp;
		if (stuID <= 0 || stuID > 9999)throw stuID;
		if (ISsameID(stuID)) { cout << "该学号已拥有，添加失败" << endl;  return; }
		List* new_node = new List;//创建一个新的结点
		new_node->stu.set_all( name, age, sex);
		new_node->stu.set_scores(stuID,cpp);
		pf->Next = new_node;
		new_node->Next = NULL;
	}
}
void List::save()//保存链表至文件中
{
	List* p = Head;
	ofstream save;
	save.open("student.dat", ios::out | ios::binary);
	while (p != NULL)
	{
		name = p->stu.get_name();
		stuID = p->stu.get_ID();
		age = p->stu.get_age();
		sex = p->stu.get_sex();
		p->stu.get_scores(&cpp);
		save << name << ' ' << setw(4)<<setfill('0')<<stuID << ' ' << sex << ' ' << age << ' ' <<cpp << endl;//输出到E:\\student.txt
		p = p->Next;
	}
	save.close();
}
int List::ISsameID(int ID)
{
	List* q = Head;
	int id;
	if (q == NULL)return 0;//无重复学号
	while (q != NULL)
	{
		id = q->stu.get_ID();
		if(id==ID)return 1;//有重复学号
		q = q->Next;
	}
	return 0;
}
void List::addtxt()
{
	List* p_now = NULL;//当前节点
	List* p_pass = NULL;//当前节点的前一节点
	Head = NULL;
	int n = 0;//用于统计学生的数量，设置编号
	ifstream out,txt;	//创建文件流对象
	out.open("student.dat", ios::in | ios::binary);
	
	while (1)//打开成功，创建链表保存数据
	{
		if (!(out >> name >> stuID >> sex >> age >> cpp))//从文件中读取数据
			break;
		n++;//编号递增
		p_now = new List;//创建结点
		if (Head == NULL)
			Head = p_now;//保存头指针
		if (p_pass != NULL)
			p_pass->Next = p_now;//将前一个结点的pNext指向当前结点
		//将文件中的数据保存在当前结点
		p_now->stu.set_all( name, age, sex);
		p_now->stu.set_scores(stuID,cpp);//保存成绩
		p_now->stu.set_num(n);//计算总数
		p_now->Next = NULL;
		p_pass = p_now;
	}
	out.close();//关闭文件
	txt.open("stu.txt", ios::in | ios::binary);
	if (!txt)
	{
		cout << "Fail to open the file!" << endl;
	}
	while (1)//打开成功，创建链表保存数据
	{
		if (!(txt >> name >> stuID >> sex >> age >> cpp))//从文件中读取数据
			break;
		if (ISsameID(stuID))
		{ cout << "信息：" << name << "\t" << setw(4) << setfill('0')<< stuID << "\t" << sex << "\t" << age << "\t" << cpp << "\t学号信息已有，添加失败！" << endl; continue; }
		n++;//编号递增
		p_now = new List;//创建结点
		if (Head == NULL)
			Head = p_now;//保存头指针
		if (p_pass != NULL)
			p_pass->Next = p_now;//将前一个结点的pNext指向当前结点
		//将文件中的数据保存在当前结点
		p_now->stu.set_all( name, age, sex);
		p_now->stu.set_scores(stuID,cpp);//保存成绩
		p_now->stu.set_num(n);//计算总数
		p_now->Next = NULL;
		p_pass = p_now;
	}
	txt.close();
	save();
}
void List::put_grade()
{
	int num, n = 0;//n编号
	List* p = Head;
	if (p == NULL) { cout << "链表为空!" << endl; return; }
	cout << "对全部学生各科成绩等级评定的结果如下：" << endl;
	cout << "编号\t姓名\t学号\t性别\t年龄\tC++\t"<< endl;
	while (p != NULL)
	{
		n++;
		p->stu.set_num(n);//重新设置编号
		name = p->stu.get_name();//获取成员数据信息赋值给外部变量
		stuID = p->stu.get_ID();
		num = p->stu.get_num();
		sex = p->stu.get_sex();
		age = p->stu.get_age();
		p->stu.get_scores(&cpp);//指针传递获取外部变量值
		cout << fixed << setprecision(2) << num << '\t' << name << '\t' << stuID << '\t' << sex << '\t'		//fixed,setprecision(2)设置两位小数
			<< age << '\t' << cpp<<get_grade(cpp)<< endl;
		p = p->Next;//设置指针指向下一个结点，下一个节点为NULL时跳出循环,遍历结束
	}
	cout << endl;
}
string List::get_grade(double grade)
{
	if (90 <= grade && grade <= 100)return "(A)";
	else if (80 <= grade && grade < 90)return "(B)";
	else if (70 <= grade && grade < 89)return "(C)";
	else if (60 <= grade && grade < 79)return "(D)";
	else return "(E)";
}
void List::sortCPP(int flag)//成绩升降序（仅排序，之后调用traverse_out()实现排序后信息输出）
{
	double c1, c2;
	List* p, * q, temp;//temp:临时的对象
	if (Head == NULL) { cout << "没有学生信息，无法计算!"; return; }
	if (flag == 1)
	{
		cout << "按C++成绩降序排列如下:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//链表实现冒泡排序法，降序
			for (q = p->Next; q != NULL; q = q->Next)
			{
				p->stu.get_scores(&c1);
				q->stu.get_scores(&c2);
				if (c1 < c2)
				{
					temp.stu = q->stu;
					q->stu = p->stu;
					p->stu = temp.stu;
				}
			}
	}
	else if (flag == 2)
	{
		cout << "按C++成绩升序排列如下:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//升序
			for (q = p->Next; q != NULL; q = q->Next)
			{
				p->stu.get_scores(&c1);
				q->stu.get_scores(&c2);
				if (c1 > c2)
				{
					temp.stu = q->stu;
					q->stu = p->stu;
					p->stu = temp.stu;
				}
			}
	}
	traverse_out();
}
List::~List()
{
	List* p = Head;
	List* pt;
	while (p != NULL)
	{
		pt = p;
		p = p->Next;
		delete pt;
	}
	pt = NULL;
	Head = NULL;Next = NULL;
	p = NULL;
}