#include"information struct.h"
#include<stdio.h>
#include<stdlib.h>
/*ѧ����Ϣ����*/void information_input()
{
	head = (struct list*)malloc(sizeof(struct list));
	list = (struct list*)malloc(sizeof(struct list));
	p = (struct list*)malloc(sizeof(struct list));
	list = p;
	head->next = p;
	p->prew = head;
	p->next = NULL;
	FILE* f = fopen(".\\Student information.txt", "r");
	if (f == NULL)
	{
		FILE* f = fopen(".\\Student information.txt", "w");
		printf("�Ѵ�����Ӧ�ı����Դ���ѧ�����ݣ����б�������������Χ������������");
	}
	else
	{
		while (fscanf(f, "%s %s %s", p->student.num, p->student.name, p->student.Class) != EOF)
		{
			for (i = 0; i < 10; i++)fscanf(f, "%d", &p->student.score[i]);
			for (i = 0; i < 10; i++)fscanf(f, "%f", &p->student.credit[i]);
			list = p;
			num++;
			p = (struct list*)malloc(sizeof(struct list));
			list->next = p;
			p->prew = list;
			p->next = NULL;
		}
	}
	fclose(f);
}
/*ѧ����Ϣ����*/void information_output()
{
	FILE* f = fopen(".\\Student information.txt", "w");
	p = head->next;
	while (p->next != NULL)
	{
		fprintf(f, "%s %s %s", p->student.num, p->student.name, p->student.Class);
		for (i = 0; i < 10; i++)fprintf(f, " %d", p->student.score[i]);
		for (i = 0; i < 10; i++)fprintf(f, " %.2f", p->student.credit[i]);
		fprintf(f, "\n");
		p = p->next;
	}
	fclose(f);
}
/*�û���Ϣ����*/void user_input()
{
	FILE* f = fopen(".\\User information.txt", "r");
	if (f == NULL)
	{
		FILE* f = fopen(".\\Student information.txt", "w");
		printf("�Ѵ�����Ӧ�ı����Դ����û����ݣ����б�������������Χ������������");
	}
	else
	{
		User_head = (struct User_list*)malloc(sizeof(struct User_list));
		User_list = (struct User_list*)malloc(sizeof(struct User_list));
		User_p = (struct User_list*)malloc(sizeof(struct User_list));
		User_head->next = User_p;
		User_p->prew = User_head;
		User_p->next = NULL;
		while (fscanf(f, " %s %s %s", User_p->user.name, User_p->user.password,User_p->user.number) != EOF)
		{
			User_list = User_p;
			User_num++;
			User_p = (struct User_list*)malloc(sizeof(struct User_list));
			User_list->next = User_p;
			User_p->prew = User_list;
			User_p->next = NULL;
		}
	}
	fclose(f);
}
/*�û���Ϣ����*/void user_output()
{
	FILE* f = fopen(".\\User information.txt", "w");
	User_p = User_head->next;
	while (User_p->next != NULL)
	{
		fprintf(f, "%s %s %s\n", User_p->user.name, User_p->user.password,User_p->user.number);
		User_p = User_p->next;
	}
	fclose(f);
}