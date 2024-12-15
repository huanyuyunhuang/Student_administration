#include<iostream>
#include"student.h"
class List
{
private:
    List* Head;//头指针
    List* Next;//指向下一结点指针
public:
    Student stu;
      List() { Head = NULL; Next = NULL; }//构造函数
    ~List();//析构函数，将Head、Next重新置空
    friend ostream& operator<<(ostream&, List*);
    void build_in();//创建链表，将student.txt中的信息读取并保存到链表中
    void traverse_out();//遍历链表，输出学生的信息
    //学生信息查询相关函数
    void search_name();//通过姓名查找
    void search_ID();//通过学号查找
    //排序功能函数
    void sortID(int flag);//根据学号升降排名
    void sortName(int flag);//根据姓名升降排名
    void sortCPP(int flag);//根据C++成绩对学生进行升降序排名
    //成绩统计功能相关函数
    void separate(bool flag);//成绩及格率的统计，和分数段人数的统计
    void count_avg();//计算学科的平均成绩
    int count_num(bool flag);//计算表中男女人数,以及总人数;
    void modify();//修改学生信息
    void Delete();//删除学生信息
    void add();//增加学生信息
    void save();//将列表保存至文件中
    void addtxt();
    int ISsameID(int ID);//判断学号是否有相同的
    void put_grade();//显示学生各科等级和总分等级
    string get_grade(double grade);//获取等级
};
