#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include"list.h"
using namespace std;
//�ⲿ��������
string name;//����		
int stuID;//ѧ��
string age;//����
string sex;//�Ա�
double cpp;//cpp�ɼ�
void List::build_in()//���ļ�����ѧ����Ϣ,��������������
{
	List* p_now = NULL;//��ǰ�ڵ�
	List* p_pass = NULL;//��ǰ�ڵ��ǰһ�ڵ�
	Head = NULL;
	int n = 0;//����ͳ��ѧ�������������ñ��
	ifstream out;	//�����ļ�������
	out.open("student.dat", ios::in| ios::binary);
	if (!out)
	{
		cout << "Fail to open the file!" << endl;
	}
	while (1)//�򿪳ɹ�����������������
	{
		if (!(out >> name >> stuID >> sex >> age >> cpp))//���ļ��ж�ȡ����
			break;
		n++;//��ŵ���
		p_now = new List;//�������
		if (Head == NULL)
			Head = p_now;//����ͷָ��
		if (p_pass != NULL)
			p_pass->Next = p_now;//��ǰһ������pNextָ��ǰ���
		//���ļ��е����ݱ����ڵ�ǰ���
		p_now->stu.set_all( name, age, sex);
		p_now->stu.set_scores(stuID,cpp);//����ɼ�
		p_now->stu.set_num(n);//��������
		p_now->Next = NULL;
		p_pass = p_now;
	}
	out.close();//�ر��ļ�
}
ostream& operator<<(ostream& output, List* p)
{
	int num = 0;
	name = p->stu.get_name();//��ȡ��Ա������Ϣ��ֵ���ⲿ����
	stuID = p->stu.get_ID();
	num = p->stu.get_num();
	sex = p->stu.get_sex();
	age = p->stu.get_age();
	p->stu.get_scores(&cpp);//ָ�봫�ݻ�ȡ�ⲿ����ֵ
	output << fixed << setprecision(2) <<num<<"\t"<< name << '\t' << setw(4)<<setfill('0')<<stuID << '\t' << sex << '\t'		//fixed,setprecision(2)������λС��
		<< age << '\t' << cpp << '\t' << endl;
	return output;
}
void List::traverse_out()//����������ӡѧ����Ϣ
{
	int n = 0;//n���
	List* p = Head;
	if (p == NULL) { cout << "����Ϊ��!" << endl; return; }
	cout << "\n���\t����\tѧ��\t�Ա�\t����\tC++\t"  << endl;
	while (p != NULL)
	{
		n++;
		p->stu.set_num(n);//�������ñ��
		cout << p;
		p = p->Next;//����ָ��ָ����һ����㣬��һ���ڵ�ΪNULLʱ����ѭ��,��������
	}
	cout << endl;
}
void List::search_name()//��������������ѧ����Ϣ
{
	int flag = 0;//��������Ƿ��ҵ���Ӧ��ѧ��
	List* p = Head;
	string Name;
	if (p == NULL) { cout << "���Ϊ�գ�" << endl; return; }
	cout << "��������Ҫ��ѯ��ѧ����������";
	cin >> Name;
	while (p != NULL)
	{
		name = p->stu.get_name();
		if (name == Name)//ѭ�����̶�name��Nameһһ�Ƚ�,��������ڴ��ȡ��Ϣ�����������ʵ��ͬ��ȫ���
		{
			flag++;//��ѯѧ�������ǲ��Լ�
			cout << "\n��ѧ������Ϣ���£�" << endl;
			cout << "\n���\t����\tѧ��\t�Ա�\t����\tC++\t" << endl;
			cout << p ;
		}
		p = p->Next;//����ָ��ָ����һ�����
	}
	if (flag == 0)cout << "û���ҵ���ѧ����" << endl;
	else cout << "���õ�" << flag << "�����!" << endl;
}
void List::search_ID()//����ѧ��������ѧ��
{
	int flag = 0;//��������Ƿ��ҵ���Ӧ��ѧ��
	List* p = Head;
	int id;
	if (p == NULL) { cout << "���Ϊ�գ�" << endl; return; }
	cout << "��������Ҫ��ѯ��ѧ����ѧ�ţ�";
	cin >> id;
	while (p != NULL)//����ͬ���������Һ���
	{
		stuID = p->stu.get_ID();
		if (stuID == id)
		{
			flag++;
			cout << "\n��ѧ������Ϣ���£�" << endl;
			cout << "\n���\t����\tѧ��\t�Ա�\t����\tC++\t" << endl;
			cout << p;
			break;
		}
		p = p->Next;//����ָ��ָ����һ�����
	}
	if (flag == 0)
		cout << "û���ҵ���ѧ����" << endl;
}
void List::sortID(int flag)//ѧ����������
{
	int ID1, ID2;
	List* p, * q, temp;//temp��ʱ�Ķ���
	if (Head == NULL) { cout << "û��ѧ����Ϣ���޷�����!"; return; }
	if (flag == 1)
	{
		cout << "��ѧ�Ž�����������:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//����
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
		cout << "��ѧ��������������:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//����
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
	List* p, * q, temp;//temp��ʱ�Ķ���
	if (Head == NULL) { cout << "û��ѧ����Ϣ���޷�����!"; return; }
	if (flag == 1)
	{
		cout << "������������������:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//����
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
		cout << "������������������:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//����
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
void List::separate(bool flag)//����C++�ɼ����зֶ�ͳ��
{
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;//����ͳ�Ƹ������ε�����
	float upass_rate;//ͳ�Ʋ�������
	double cpp;
	List* p = Head;
	if (p == NULL) { cout << "���Ϊ��!" << endl; return; }
	while (p != NULL)
	{
		p->stu.get_scores(&cpp); 
		if (cpp >= 90 && cpp <= 100)t1++;
		else if (cpp >= 80 && cpp<= 89)t2++;
		else if (cpp >= 70 && cpp <= 79)t3++;
		else if (cpp >= 60 && cpp <= 69)t4++;
		else t5++;
		p = p->Next;//pָ����һ���ڵ�
	}
	if (!flag)
	{
		cout << "\nC++�ɼ��ֶ�ͳ������:\n"; 
		cout<< "������" << "\t����" << endl;
		cout << "100-90\t" << t1 << "\n89-80\t" << t2 << "\n79-70\t" << t3 << "\n69-60\t" << t4 << "\n59-0\t" << t5 << endl;
	}
	else
	{
		upass_rate = t5 / float(count_num(1));
		upass_rate = 1 - upass_rate;
		cout << "C++�ɼ�������Ϊ"; 
		cout << setiosflags(ios::fixed) << setprecision(2) << 100 * upass_rate << " %" << endl;
	}
}
void List::count_avg()//����ƽ���ɼ�
{
	double Cavg;//ƽ���ɼ�
	int n = 0;//���ڼ�¼ѧ������
	double Csum = 0;//��Ŀ�ܷ�
	List* p = Head;
	if (p == NULL) { cout << "���Ϊ��!" << endl; return; }
	while (p != NULL)
	{
		p->stu.get_scores(&cpp);
		Csum += cpp;
		++n;
		p = p->Next;
	}
	if (n != 0)//�ж��Ƿ���ѧ����Ϣ
	{
		Cavg = Csum / n;
		cout << "C++��ƽ���ɼ�����:" << Cavg << endl;
	}
}
int List::count_num(bool flag)
{
	string sex;
	int women = 0, men = 0;//ͳ����Ů������
	int n = 0;//���ڼ�¼ѧ������
	List* p = Head;
	if (p == NULL) { cout << "���Ϊ��!" << endl; return -1; }
	while (p != NULL)
	{
		sex = p->stu.get_sex();//��ȡ�Ա���Ϣ
		if (sex == "��")men++;
		else if (sex == "Ů") women++;
		++n;
		p = p->Next;
	}
	if(!flag)
		cout << "������ѧ������Ϊ" << n << "\n������������Ϊ:" << men << "\n����Ů������Ϊ:" << women << endl;
	return n;
}
void List::modify()//�޸�ѧ������Ϣ
{
	int modifyPos = 0;//λ�ñ��
	int num;//���
	int flag = 0;//����Ƿ��ж�Ӧ�ı��
	List* p = Head;//ָ��ǰ����ָ��
	List* pf = NULL;//ָ��ǰһ������ָ��
	cout << "�����������޸ĵ���Ϣ��λ�ã�λ�ñ��,����0����";
	cin >> modifyPos;
	if (p == NULL) { cout << "��������Ϊ��!"; return; }
	while (p != NULL)//��������
	{
		num = p->stu.get_num();
		if (num == modifyPos)
		{
			flag++;
			cout << "���޸���Ϣ���£�" << endl;
			cout << p;
			cout << "�������޸ĺ����Ϣ:\n" << "����\t" << "ѧ��\t" << "�Ա�\t" << "����\t" << "C++" << endl;
			cin >> name >> stuID >> sex >> age >> cpp;
			if (stuID <= 0 || stuID > 9999)throw stuID;
			p->stu.set_all(name, age, sex);
			p->stu.set_scores(stuID, cpp);//�������ø��Ƴɼ�
			break;
		}
		p = p->Next;//����ָ��ָ����һ�����
	}
	if (flag == 0)
		cout << "û���ҵ���ѧ����" << endl;
}
void List::Delete()//ɾ��ѧ����Ϣ
{
	int deletePos = 0;//λ�ñ��
	int num;//���
	int flag = 0;//����Ƿ��ж�Ӧ�ı��
	List* p = Head;//ָ��ǰ����ָ��
	List* pf = NULL;//ָ��ǰһ������ָ��
	int answer;
	cout << "����������ɾ����ѧ���ı��";
	cin >> deletePos;
	if (p == NULL) { cout << "���������Ϊ��!"; return; }
	while (p != NULL)//��������
	{
		num = p->stu.get_num();
		if (num == deletePos)
		{
			flag++;
			cout << "���\t����\tѧ��\t�Ա�\t����\tC++\t"<< endl;
			cout << p;
			cout << "��ȷ��Ҫɾ��������Ϣ��(1.��2.��)";
			cin >> answer;
			if (answer == 1)
			{
				if (pf == NULL)
				{
					List* temp = p;//��ʱ����ָ��ý���ָ��
					Head = p->Next;//������ǰ��㣬ʵ����Ϣ��ɾ��
					delete temp;//������ռ�ڴ�ɾ��
				}
				else
				{
					List* temp = p;
					pf->Next = p->Next;
					delete temp;
				}
				cout << "ɾ���ɹ�!" << endl;
				break;
			}
			else break;
		}
		pf = p;
		p = p->Next;
	}
	if (flag == 0)cout << "�Ҳ�����Ӧ��λ��!" << endl;
}
void List::add()//����ѧ����Ϣ
{
	int insertPos = 0;//λ�ñ��
	int num;//���
	int flag = 0;//����Ƿ��ж�Ӧ�ı��
	List* p = Head;//ָ��ǰ����ָ��
	List* pf = NULL;//ָ��ǰһ������ָ��
	cout << "�������������ӵ���Ϣ��λ�ã�λ�ñ��,����0����";
	cin >> insertPos;
	while (p != NULL)//��������
	{
		num = p->stu.get_num();
		if (num == insertPos)
		{
			flag++;
			List* new_node = new List;//����һ���µĽ��
			cout << "����������ѧ������Ϣ" << endl;
			cout << "����\t" << "ѧ��\t" << "�Ա�\t" << "����\t" << "C++\t" << endl;
			cin >> name >> stuID >> sex >> age >> cpp; 
			if (stuID <= 0||stuID>9999)throw stuID;
			if (ISsameID(stuID)) { cout << "��ѧ����ӵ�У����ʧ��" << endl; delete new_node; return; }
			new_node->stu.set_all( name, age, sex);
			new_node->stu.set_scores(stuID,cpp);
			if (num == 1)//nex_node����ͷ���
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
		List* new_node = new List;//����һ���µĽ��
		cout << "����������ѧ������Ϣ" << endl;
		cout << "����\t" << "ѧ��\t" << "�Ա�\t" << "����\t" << "C++\t" << endl;
		cin >> name >> stuID >> sex >> age >> cpp;
		if (stuID <= 0 || stuID > 9999)throw stuID;
		if (ISsameID(stuID)) { cout << "��ѧ����ӵ�У����ʧ��" << endl; delete new_node; return; }
		new_node->stu.set_all( name, age, sex);
		new_node->stu.set_scores(stuID,cpp);
		Head = new_node;
		new_node->Next = NULL;
	}
	if (flag == 0)
	{
		cout << "����������ѧ������Ϣ" << endl;
		cout << "����\t" << "ѧ��\t" << "�Ա�\t" << "����\t" << "C++\t" << endl;
		cin >> name >> stuID >> sex >> age >> cpp;
		if (stuID <= 0 || stuID > 9999)throw stuID;
		if (ISsameID(stuID)) { cout << "��ѧ����ӵ�У����ʧ��" << endl;  return; }
		List* new_node = new List;//����һ���µĽ��
		new_node->stu.set_all( name, age, sex);
		new_node->stu.set_scores(stuID,cpp);
		pf->Next = new_node;
		new_node->Next = NULL;
	}
}
void List::save()//�����������ļ���
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
		save << name << ' ' << setw(4)<<setfill('0')<<stuID << ' ' << sex << ' ' << age << ' ' <<cpp << endl;//�����E:\\student.txt
		p = p->Next;
	}
	save.close();
}
int List::ISsameID(int ID)
{
	List* q = Head;
	int id;
	if (q == NULL)return 0;//���ظ�ѧ��
	while (q != NULL)
	{
		id = q->stu.get_ID();
		if(id==ID)return 1;//���ظ�ѧ��
		q = q->Next;
	}
	return 0;
}
void List::addtxt()
{
	List* p_now = NULL;//��ǰ�ڵ�
	List* p_pass = NULL;//��ǰ�ڵ��ǰһ�ڵ�
	Head = NULL;
	int n = 0;//����ͳ��ѧ�������������ñ��
	ifstream out,txt;	//�����ļ�������
	out.open("student.dat", ios::in | ios::binary);
	
	while (1)//�򿪳ɹ�����������������
	{
		if (!(out >> name >> stuID >> sex >> age >> cpp))//���ļ��ж�ȡ����
			break;
		n++;//��ŵ���
		p_now = new List;//�������
		if (Head == NULL)
			Head = p_now;//����ͷָ��
		if (p_pass != NULL)
			p_pass->Next = p_now;//��ǰһ������pNextָ��ǰ���
		//���ļ��е����ݱ����ڵ�ǰ���
		p_now->stu.set_all( name, age, sex);
		p_now->stu.set_scores(stuID,cpp);//����ɼ�
		p_now->stu.set_num(n);//��������
		p_now->Next = NULL;
		p_pass = p_now;
	}
	out.close();//�ر��ļ�
	txt.open("stu.txt", ios::in | ios::binary);
	if (!txt)
	{
		cout << "Fail to open the file!" << endl;
	}
	while (1)//�򿪳ɹ�����������������
	{
		if (!(txt >> name >> stuID >> sex >> age >> cpp))//���ļ��ж�ȡ����
			break;
		if (ISsameID(stuID))
		{ cout << "��Ϣ��" << name << "\t" << setw(4) << setfill('0')<< stuID << "\t" << sex << "\t" << age << "\t" << cpp << "\tѧ����Ϣ���У����ʧ�ܣ�" << endl; continue; }
		n++;//��ŵ���
		p_now = new List;//�������
		if (Head == NULL)
			Head = p_now;//����ͷָ��
		if (p_pass != NULL)
			p_pass->Next = p_now;//��ǰһ������pNextָ��ǰ���
		//���ļ��е����ݱ����ڵ�ǰ���
		p_now->stu.set_all( name, age, sex);
		p_now->stu.set_scores(stuID,cpp);//����ɼ�
		p_now->stu.set_num(n);//��������
		p_now->Next = NULL;
		p_pass = p_now;
	}
	txt.close();
	save();
}
void List::put_grade()
{
	int num, n = 0;//n���
	List* p = Head;
	if (p == NULL) { cout << "����Ϊ��!" << endl; return; }
	cout << "��ȫ��ѧ�����Ƴɼ��ȼ������Ľ�����£�" << endl;
	cout << "���\t����\tѧ��\t�Ա�\t����\tC++\t"<< endl;
	while (p != NULL)
	{
		n++;
		p->stu.set_num(n);//�������ñ��
		name = p->stu.get_name();//��ȡ��Ա������Ϣ��ֵ���ⲿ����
		stuID = p->stu.get_ID();
		num = p->stu.get_num();
		sex = p->stu.get_sex();
		age = p->stu.get_age();
		p->stu.get_scores(&cpp);//ָ�봫�ݻ�ȡ�ⲿ����ֵ
		cout << fixed << setprecision(2) << num << '\t' << name << '\t' << stuID << '\t' << sex << '\t'		//fixed,setprecision(2)������λС��
			<< age << '\t' << cpp<<get_grade(cpp)<< endl;
		p = p->Next;//����ָ��ָ����һ����㣬��һ���ڵ�ΪNULLʱ����ѭ��,��������
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
void List::sortCPP(int flag)//�ɼ������򣨽�����֮�����traverse_out()ʵ���������Ϣ�����
{
	double c1, c2;
	List* p, * q, temp;//temp:��ʱ�Ķ���
	if (Head == NULL) { cout << "û��ѧ����Ϣ���޷�����!"; return; }
	if (flag == 1)
	{
		cout << "��C++�ɼ�������������:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//����ʵ��ð�����򷨣�����
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
		cout << "��C++�ɼ�������������:\n";
		for (p = Head; p->Next != NULL; p = p->Next)//����
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