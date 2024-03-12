#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"information struct.h"
/*初始菜单*/int origin_meun()
{
	printf("欢迎使用学生管理系统\n");
	printf("******功能菜单******\n");
	printf("**                **\n");
	printf("**0.  退    出    **\n");
	printf("**1.  登陆账号    **\n");
	printf("**2.  注册账号    **\n");
	printf("**3.  账号找回    **\n");
	printf("**4.  账号注销    **\n");
	printf("**5.  密码修改    **\n");
	printf("**                **\n");
	printf("********************\n");
	printf("请选择功能：");
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
		printf("请重新输入正确的序号\n");
		clean_screen();
		return origin_meun();
	}
}
/*账号登陆*/int logon_meun()
{
	char name[20], password[20];
	printf("请输入您的账号和密码\n");
	printf("账号：");
	scanf("%s", name);
	printf("密码：");
	scanf("%s", password);
	User_p = User_head->next;
	while (User_p->next != EOF)
	{
		if (strcmp(name, User_p->user.name) == 0)
		{
			if (strcmp(password, User_p->user.password) == 0)
			{
				printf("登陆成功\n");
				clean_screen();
				information_input();
				user_output();
				return main_meun();
			}
			else
			{
				printf("账号与密码不匹配，请重新输入账号和密码\n");
				clean_screen();
				return logon_meun();
			}
		}
		User_p = User_p->next;
	}
	printf("未找到该账号，请重新输入账号和密码\n");
	clean_screen();
	return logon_meun();
}
/*账号注册*/int login_in()
{
	User_list->next = NULL;
	printf("请输入账号：");
	scanf(" %s", User_p->user.name);
	printf("请输入密码：");
	scanf(" %s", User_p->user.password);
	printf("请输入手机号码，便于后续找回账号：");
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
/*账号找回*/int find_back()
{
	char name[20], number[20];
	printf("请输入要找回的账号或输入*号返回上一步：");
	scanf("%s", name);
	if (strcmp(name, "*") == 0)
	{
		clean_screen();
		return origin_meun();
	}
	printf("请输入绑定的手机号码：");
	scanf("%s", number);
	User_p = User_head->next;
	while (User_p != NULL)
	{
		if (strcmp(name, User_p->user.name) == 0)
		{
			if (strcmp(number, User_p->user.number) == 0)
			{
				printf("请输入重置后的密码：");
				scanf("%s", User_p->user.password);
				clean_screen();
				return origin_meun();
			}
			else
			{
				printf("手机号码错误，请重新输入账号和手机号码\n");
				clean_screen();
				return find_back();
			}
		}
		User_p = User_p->next;
	}
	printf("未找到对应账号，请重新输入\n");
	clean_screen();
	return find_back();
}
/*用户注销*/int User_delete()
{
	char name[20], password[20];
	printf("请输入要注销的账号：");
	scanf("%s", name);
	printf("请输入注销账户的密码：");
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
				printf("请重新输入正确的密码");
				clean_screen();
				return User_delete();
			}
		}
		User_p = User_p->next;
	}
	printf("请重新输入正确的账号");
	clean_screen();
	return User_delete();
}
/*密码修改*/int password_change()
{
	char name[20], password[20];
	User_p = User_head->next;
	printf("请输入账号：");
	scanf("%s", name);
	while (User_p != EOF)
	{
		if (strcmp(User_p->user.name, name) == 0)break;
		User_p = User_p->next;
	}
	if (User_p == EOF)
	{
		printf("请输入正确的账号\n");
		clean_screen();
		return password_change();
	}
	printf("请输入原密码：");
	scanf("%s", password);
	while (strcmp(password, User_p->user.password) != 0)
	{
		printf("请重新输入正确密码");
		scanf("%s", password);
	}
	printf("请输入修改后的密码：");
	scanf("%s", User_p->user.password);
	clean_screen();
	return origin_meun();
}