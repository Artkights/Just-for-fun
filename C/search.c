#include"information struct.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*搜索菜单*/int search_meun()
{
	printf("******功能菜单******\n");
	printf("**                **\n");
	printf("**0.  退    出    **\n");
	printf("**1.  信息修改    **\n");
	printf("**2.  信息删除    **\n");
	printf("**                **\n");
	printf("********************\n");
	printf("请选择功能：");
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		clean_screen();
		return find_meun();
		break;
	case 1:
		informaton_change();
		clean_screen();
		return find_meun();
		break;
	case 2:
		information_delete();
		clean_screen;
		return find_meun();
		break;
	default:
		printf("请输入正确的序号：\n");
		clean_screen();
		return search_meun();
	}
}
/*学生信息修改*/int informaton_change()
{
	int k;
	printf("请输入要修改的学生信息的序号：");
	scanf("%d", &i);
	search_p = search_head;
	for (k = 0; k < i; k++)
	{
		search_p = search_p->next;
	}
	printf("请输入要修改的信息：\n");
	printf("0.退出\n");
	printf("1.学号\n");
	printf("2.姓名\n");
	printf("3.班级\n");
	printf("4.成绩\n");
	printf("5.学分\n");
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		clean_screen();
		return search_meun();
	case 1:
		printf("请输入修改后的学号：");
		scanf("%s", search_p->p->student.num);
		clean_screen();
		return search_meun();
	case 2:
		printf("请输入修改后的姓名：");
		scanf("%s", search_p->p->student.name);
		clean_screen();
		return search_meun();
	case 3:
		printf("请输入修改后的班级：");
		scanf("%s", search_p->p->student.Class);
		clean_screen();
		return search_meun();
	case 4:
		printf("请输入需要修改的对应课程的序号：\n");
		scanf("%d", &i);//后面应更有对应及其序号
		printf("请输入修改后的成绩：");
		scanf("%s", search_p->p->student.num[i - 1]);
		clean_screen();
		return search_meun();
	case 5:
		printf("请输入需要修改的对应课程的序号：\n");
		scanf("%d", &i);//后面应更有对应及其序号
		printf("请输入修改后的学分：");
		scanf("%s", search_p->p->student.num[i - 1]);
		clean_screen();
		return search_meun();
	default:
		printf("请重新输入正确的序号：");
		clean_screen();
		return informaton_change();
		break;
	}
}
/*学生信息删除*/int information_delete()
{
	int k;
	printf("请输入要删除的学生信息的序号或输入-1返回：");
	scanf("%d", &i);
	if (i == -1)
	{
		clean_screen();
		return search_meun();
	}
	search_p = search_head;
	for (k = 0; k < i; k++)
	{
		search_p = search_p->next;
	}
	p = search_p->p;
	p->prew->next = p->next;
	p->next->prew = p->prew;
	free(p);
	clean_screen();
	return search_meun();
}