#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"information struct.h"
/*清屏*/void clean_screen()
{
	char ch;
	printf("功能已完成，按回车键以继续");
	getchar();
	while ((ch = getchar()) != '\n' && (ch = getchar()) != EOF);
	system("cls");
}