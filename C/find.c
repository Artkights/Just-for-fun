#include"information struct.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*��ѯ�˵�*/int find_meun()
{
	printf("******���ܲ˵�******\n");
	printf("**                **\n");
	printf("**0.  ��    ��    **\n");
	printf("**1.  ѧ�Ų�ѯ    **\n");
	printf("**2.  ������ѯ    **\n");
	printf("**                **\n");
	printf("********************\n");
	printf("��ѡ���ܣ�");
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		clean_screen();
		return main_meun();
		break;
	case 1:
		number_find();
		break;
	case 2:
		name_find();
		break;
	default:
		printf("������������ȷ�����");
		break;
	}
	clean_screen();
	return find_meun();
}
/*ѧ�Ų�ѯ*/int number_find()
{
	search_head = (struct Search*)malloc(sizeof(struct Search));
	search_p = (struct Search*)malloc(sizeof(struct Search));
	search_list = (struct Search*)malloc(sizeof(struct Search));
	search_list = search_p;
	search_head->next = search_p;
	char name[20], student_name[20];
	int j, k = 0;
	printf("��������Ҫ��ѯ��ѧ��ѧ�Ż�����*���أ�");
	scanf("%s", name);
	if (strcmp(name, "*") == 0)return find_meun();
	j = strlen(name);
	student_name[j] = '\0';
	for (p = head->next; p->next != NULL; p = p->next)
	{
		for(k=0;k+j-1<strlen(p->student.name);k++)
		{
			for (i = 0; i < j; i++)
			{
				student_name[i] = p->student.num[i + k];
			}
			if (strcmp(student_name, name) == 0)
			{
				search_p->p = p;
				search_list = search_p;
				search_p = (struct Search*)malloc(sizeof(struct Search));
				search_p->next = NULL;
				search_list->next = search_p;
				break;
			}
		}
	}
	for (k=1,search_p = search_head->next; search_p->next != NULL; search_p = search_p->next,k++)
	{
		printf("%d %s %s %s",k, search_p->p->student.num, search_p->p->student.name, search_p->p->student.Class);
		for (i = 0; i < 10; i++)printf(" %d", search_p->p->student.score[i]);
		for (i = 0; i < 10; i++)printf(" %.2f", search_p->p->student.credit[i]);
		printf("\n");
	}
	return search_meun();
}
/*������ѯ*/int name_find()
{
	search_head = (struct Search*)malloc(sizeof(struct Search));
	search_p = (struct Search*)malloc(sizeof(struct Search));
	search_list = (struct Search*)malloc(sizeof(struct Search));
	search_list = search_p;
	search_head->next = search_p;
	char name[20],student_name[20];
	int j,k=0;
	printf("��������Ҫ��ѯ��ѧ������������*���أ�");
	scanf("%s", name);
	if (strcmp(name, "*") == 0)return find_meun();
	j = strlen(name);
	student_name[j] = '\0';
	for (p = head->next; p->next != NULL; p = p->next)
	{
		for (k = 0; k + j < strlen(p->student.name); k++)
		{
			for (i = 0; i < j; i++)
			{
				student_name[i] = p->student.num[i + k];
			}
			if (strcmp(student_name, name) == 0)
			{
				search_p->p = p;
				search_list = search_p;
				search_p = (struct Search*)malloc(sizeof(struct Search*));
				search_p->next = NULL;
				search_list->next = search_p;
				break;
			}
		}
	}
	for (k = 1, search_p = search_head->next; search_p->next != NULL; search_p = search_p->next, k++)
	{
		printf("%d %s %s %s", k, search_p->p->student.num, search_p->p->student.name, search_p->p->student.Class);
		for (i = 0; i < 10; i++)printf(" %d", search_p->p->student.score[i]);
		for (i = 0; i < 10; i++)printf(" %.2f", search_p->p->student.credit[i]);
		printf("\n");
	}
	return search_meun();
}