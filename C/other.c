#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"information struct.h"
/*����*/void clean_screen()
{
	char ch;
	printf("��������ɣ����س����Լ���");
	getchar();
	while ((ch = getchar()) != '\n' && (ch = getchar()) != EOF);
	system("cls");
}