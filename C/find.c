#include"information struct.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*查询菜单*/int find_meun()
{
	printf("******功能菜单******\n");
	printf("**                **\n");
	printf("**0.  退    出    **\n");
	printf("**1.  学号查询    **\n");
	printf("**2.  姓名查询    **\n");
	printf("**                **\n");
	printf("********************\n");
	printf("请选择功能：");
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
		printf("请重新输入正确的序号");
		break;
	}
	clean_screen();
	return find_meun();
}
/*学号查询*/int number_find()
{
	search_head = (struct Search*)malloc(sizeof(struct Search));
	search_p = (struct Search*)malloc(sizeof(struct Search));
	search_list = (struct Search*)malloc(sizeof(struct Search));
	search_list = search_p;
	search_head->next = search_p;
	char name[20], student_name[20];
	int j, k = 0;
	printf("请输入想要查询的学生学号或输入*返回：");
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
/*姓名查询*/int name_find()
{
	search_head = (struct Search*)malloc(sizeof(struct Search));
	search_p = (struct Search*)malloc(sizeof(struct Search));
	search_list = (struct Search*)malloc(sizeof(struct Search));
	search_list = search_p;
	search_head->next = search_p;
	char name[20],student_name[20];
	int j,k=0;
	printf("请输入想要查询的学生姓名或输入*返回：");
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