#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include"Birth.h"
#include"Digit.h"
using namespace std;

int main(void)
{
	int choice;

	system("color E0"); //黄黑

	//系统界面
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	printf("*欢迎进入算法展示手册*");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	system("pause");
	system("cls");
	do {
		//输出系统菜单
		cout << "======算法展示==============" << endl;
		cout << "*    1.旅游景点时间计算    *" << endl;
		cout << "*    2.八数码              *" << endl;
		cout << "============================" << endl;

		//用户选择功能
		cin >> choice;

		switch (choice)
		{
		case 1:BirthActivity(); break;
		case 2:getdigit(); break;
		case 0:cout << "感谢使用，欢迎您下次再来" << endl; break;
		default:cout << "输入错误！请重新输入！" << endl << endl;;
		}

	} while (choice != 0);

	return 0;
}
