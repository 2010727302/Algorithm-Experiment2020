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

	system("color E0"); //�ƺ�

	//ϵͳ����
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	printf("*��ӭ�����㷨չʾ�ֲ�*");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	system("pause");
	system("cls");
	do {
		//���ϵͳ�˵�
		cout << "======�㷨չʾ==============" << endl;
		cout << "*    1.���ξ���ʱ�����    *" << endl;
		cout << "*    2.������              *" << endl;
		cout << "============================" << endl;

		//�û�ѡ����
		cin >> choice;

		switch (choice)
		{
		case 1:BirthActivity(); break;
		case 2:getdigit(); break;
		case 0:cout << "��лʹ�ã���ӭ���´�����" << endl; break;
		default:cout << "����������������룡" << endl << endl;;
		}

	} while (choice != 0);

	return 0;
}
