#include<iostream>
#include"student.h"
class List
{
private:
    List* Head;//ͷָ��
    List* Next;//ָ����һ���ָ��
public:
    Student stu;
      List() { Head = NULL; Next = NULL; }//���캯��
    ~List();//������������Head��Next�����ÿ�
    friend ostream& operator<<(ostream&, List*);
    void build_in();//����������student.txt�е���Ϣ��ȡ�����浽������
    void traverse_out();//�����������ѧ������Ϣ
    //ѧ����Ϣ��ѯ��غ���
    void search_name();//ͨ����������
    void search_ID();//ͨ��ѧ�Ų���
    //�����ܺ���
    void sortID(int flag);//����ѧ����������
    void sortName(int flag);//����������������
    void sortCPP(int flag);//����C++�ɼ���ѧ����������������
    //�ɼ�ͳ�ƹ�����غ���
    void separate(bool flag);//�ɼ������ʵ�ͳ�ƣ��ͷ�����������ͳ��
    void count_avg();//����ѧ�Ƶ�ƽ���ɼ�
    int count_num(bool flag);//���������Ů����,�Լ�������;
    void modify();//�޸�ѧ����Ϣ
    void Delete();//ɾ��ѧ����Ϣ
    void add();//����ѧ����Ϣ
    void save();//���б������ļ���
    void addtxt();
    int ISsameID(int ID);//�ж�ѧ���Ƿ�����ͬ��
    void put_grade();//��ʾѧ�����Ƶȼ����ֵܷȼ�
    string get_grade(double grade);//��ȡ�ȼ�
};
