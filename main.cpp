#include<iostream>
#include<stdio.h>
#include"student.h"
#include"list.h"
using namespace std;
void menu();
void menu1();
void menu2();
void menu3();
void menu4();
int main()
{
	int main_flag, operation_flag, sort_flag, separate_flag, search_flag;
	List pHead;
	pHead.build_in();
	while (1)
	{
		menu();
		cout << "请选择要进行的操作:\n";
		cin >> main_flag;
		//switch语句嵌套比较多，在case后面有“//”是第一级switch的，“///”第二层；“////”第三层
		switch (main_flag)
		{
		case 1:pHead.traverse_out(); system("pause"); system("cls"); break;//
		case 2://
			while (1)
			{
				system("cls");
				pHead.build_in();
				menu1();
				cout << "请选择要进行的操作:\n";
				cin >> operation_flag;
				switch (operation_flag)
				{
				case 1:pHead.addtxt(); system("pause"); system("cls");
					cout << "数据已更新!\n"; pHead.traverse_out();
					pHead.save(); cout << "信息已保存到文件!\n";
					system("pause"); break;
				case 2:try { pHead.add(); }
					  catch(int){cout << "输入学号不符合规范！" << endl; }system("pause"); system("cls");	///
					cout << "数据已更新!\n"; pHead.traverse_out();
					pHead.save(); cout << "信息已保存到文件!\n";
					system("pause"); break;
				case 3:pHead.Delete(); system("pause"); system("cls");	///
					cout << "数据已更新!\n"; pHead.traverse_out();
					pHead.save(); cout << "信息已保存到文件!\n";
					system("pause"); break;
				case 4:try { pHead.modify(); }
					  catch (int) { cout << "输入学号不符合规范！" << endl; }system("pause"); system("cls");	///
					cout << "数据已更新!\n"; pHead.traverse_out();
					pHead.save(); cout << "信息已保存到文件!\n";
					system("pause"); break;
				case 5:											///
					while (1)//排序
					{
						system("cls");
						pHead.build_in();
						menu4();
						cout << "请选择要进行的操作:\n";
						cin >> sort_flag;
						switch (sort_flag)
						{
						case 1://单科降序	
							pHead.sortCPP(1);
							system("pause"); break;
						case 2:	//单科升序					
							pHead.sortCPP(2);
							system("pause"); break;
						case 3:pHead.sortID(1); system("pause"); break;			////
						case 4:pHead.sortID(2); system("pause"); break;			////
						case 5:pHead.sortName(1); system("pause"); break;			////
						case 6:pHead.sortName(2); system("pause"); break;			////
						case 7:system("cls"); break;								////
						}
						if (sort_flag == 7)break;
					}break;
				case 6:							///
					while (1)//统计
					{
						system("cls");
						pHead.build_in();
						menu3();
						cout << "请选择要进行的操作:\n";
						cin >> separate_flag;
						switch (separate_flag)
						{
						case 1:		
							pHead.separate(0);
							system("pause");
							break;
						case 2:pHead.put_grade(); system("pause"); break;
						case 3:pHead.count_avg(); system("pause"); break;			////
						case 4:
							pHead.separate(1);
							system("pause");
							break;
						case 5:pHead.count_num(0); system("pause"); break;			////
						case 6:system("cls"); break;							////
						}
						if (separate_flag == 6)break;
					}break;
				case 7:						///
					while (1)//查询
					{
						system("cls");
						pHead.build_in();
						menu2();
						cout << "请选择要进行的操作:\n";
						cin >> search_flag;
						switch (search_flag)
						{
						case 1:pHead.search_name(); system("pause"); break;		////
						case 2:pHead.search_ID(); system("pause"); break;			////	
						case 3:system("cls"); break;							////
						}
						if (search_flag == 3)break;
					}break;
				case 8:system("cls"); break;		///
				}
				if (operation_flag == 8)break;
			}break;
		case 3:pHead.save(); cout << "数据已保存!"; system("pause"); system("cls"); break;		//
		case 4:/*pHead.delete_list();*/exit(0); break;	
		}
	}
	return 0;
}