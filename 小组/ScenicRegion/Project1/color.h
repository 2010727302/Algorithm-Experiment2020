#pragma once
#pragma once
#include "stdio.h"
#include "windows.h"
int columns, rows;

void set_pointer(int x, int y) //设置控制台光标位置
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}
void set_console_color(unsigned short color_index) //设置输出颜色
{
	if (color_index == 0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
			FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	if (color_index == 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
			FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |
			FOREGROUND_RED);
	if (color_index == 2)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
			FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |
			FOREGROUND_BLUE);
	if (color_index == 3)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
			FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |
			FOREGROUND_GREEN);
	if (color_index == 4)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |
			BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
}


int get_windows_size() //得到控制台大小
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top - 1;
	/*
	 printf("columns: %dn", columns);
	 printf("rows: %dn", rows);
	*/
	return 0;
}

/*void print() {
	//系统界面设置
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	printf("*欢迎进入景区管理系统*");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	set_console_color(0);
	system("pause");
	system("cls");
}*/