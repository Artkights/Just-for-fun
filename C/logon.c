#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"information struct.h"
/*��ʼ�˵�*/int origin_meun()
{
	printf("��ӭʹ��ѧ������ϵͳ\n");
	printf("******���ܲ˵�******\n");
	printf("**                **\n");
	printf("**0.  ��    ��    **\n");
	printf("**1.  ��½�˺�    **\n");
	printf("**2.  ע���˺�    **\n");
	printf("**3.  �˺��һ�    **\n");
	printf("**4.  �˺�ע��    **\n");
	printf("**5.  �����޸�    **\n");
	printf("**                **\n");
	printf("********************\n");
	printf("��ѡ���ܣ�");
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		user_output();
		information_input();
		return 0;
	case 1:
		logon_meun();
		break;
	case 2:
		login_in();
		break;
	case 3:
		find_back();
		break;
	case 4:
		User_delete();
		break;
	case 5:
		password_change();
		return origin_meun();
		break;
	default:
		printf("������������ȷ�����\n");
		clean_screen();
		return origin_meun();
	}
}
/*�˺ŵ�½*/int logon_meun()
{
	char name[20], password[20];
	printf("�����������˺ź�����\n");
	printf("�˺ţ�");
	scanf("%s", name);
	printf("���룺");
	scanf("%s", password);
	User_p = User_head->next;
	while (User_p->next != EOF)
	{
		if (strcmp(name, User_p->user.name) == 0)
		{
			if (strcmp(password, User_p->user.password) == 0)
			{
				printf("��½�ɹ�\n");
				clean_screen();
				information_input();
				user_output();
				return main_meun();
			}
			else
			{
				printf("�˺������벻ƥ�䣬�����������˺ź�����\n");
				clean_screen();
				return logon_meun();
			}
		}
		User_p = User_p->next;
	}
	printf("δ�ҵ����˺ţ������������˺ź�����\n");
	clean_screen();
	return logon_meun();
}
/*�˺�ע��*/int login_in()
{
	User_list->next = NULL;
	printf("�������˺ţ�");
	scanf(" %s", User_p->user.name);
	printf("���������룺");
	scanf(" %s", User_p->user.password);
	printf("�������ֻ����룬���ں����һ��˺ţ�");
	scanf(" %s", User_p->user.number);
	User_num++;
	User_list->next = User_p;
	User_p->prew = User_list;
	User_list = User_p;
	User_list->next = NULL;
	User_p = (struct User_list*)malloc(sizeof(struct User_list));
	clean_screen();
	return origin_meun();
}
/*�˺��һ�*/int find_back()
{
	char name[20], number[20];
	printf("������Ҫ�һص��˺Ż�����*�ŷ�����һ����");
	scanf("%s", name);
	if (strcmp(name, "*") == 0)
	{
		clean_screen();
		return origin_meun();
	}
	printf("������󶨵��ֻ����룺");
	scanf("%s", number);
	User_p = User_head->next;
	while (User_p != NULL)
	{
		if (strcmp(name, User_p->user.name) == 0)
		{
			if (strcmp(number, User_p->user.number) == 0)
			{
				printf("���������ú�����룺");
				scanf("%s", User_p->user.password);
				clean_screen();
				return origin_meun();
			}
			else
			{
				printf("�ֻ�������������������˺ź��ֻ�����\n");
				clean_screen();
				return find_back();
			}
		}
		User_p = User_p->next;
	}
	printf("δ�ҵ���Ӧ�˺ţ�����������\n");
	clean_screen();
	return find_back();
}
/*�û�ע��*/int User_delete()
{
	char name[20], password[20];
	printf("������Ҫע�����˺ţ�");
	scanf("%s", name);
	printf("������ע���˻������룺");
	scanf("%s", password);
	User_p = User_head->next;
	while (User_p->next != EOF)
	{
		if (strcmp(User_p->user.name, name) == 0)
		{
			if (strcmp(User_p->user.password, password) == 0)
			{
				User_p->prew->next = User_p->next;
				User_p->next->prew = User_p->prew;
				free(User_p);
				clean_screen();
				return origin_meun();
			}
			else
			{
				printf("������������ȷ������");
				clean_screen();
				return User_delete();
			}
		}
		User_p = User_p->next;
	}
	printf("������������ȷ���˺�");
	clean_screen();
	return User_delete();
}
/*�����޸�*/int password_change()
{
	char name[20], password[20];
	User_p = User_head->next;
	printf("�������˺ţ�");
	scanf("%s", name);
	while (User_p != EOF)
	{
		if (strcmp(User_p->user.name, name) == 0)break;
		User_p = User_p->next;
	}
	if (User_p == EOF)
	{
		printf("��������ȷ���˺�\n");
		clean_screen();
		return password_change();
	}
	printf("������ԭ���룺");
	scanf("%s", password);
	while (strcmp(password, User_p->user.password) != 0)
	{
		printf("������������ȷ����");
		scanf("%s", password);
	}
	printf("�������޸ĺ�����룺");
	scanf("%s", User_p->user.password);
	clean_screen();
	return origin_meun();
}