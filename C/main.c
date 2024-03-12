#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"information struct.h"
/*主菜单*/int main_meun()
{
	printf("******功能菜单******\n");
	printf("**                **\n");
	printf("**0.  退    出    **\n");
	printf("**1.  成绩录入    **\n");
	printf("**2.  成绩查询    **\n");
	printf("**3.  成绩排序    **\n");
	printf("**4.  成绩统计    **\n");
	printf("**5.  绩点计算    **\n");
	printf("**6.  绩点排名    **\n");
	printf("**7.  最 高 分    **\n");
	printf("**8.  最 低 分    **\n");
	printf("**9.  平 均 分    **\n");
	printf("**10. 班最高分    **\n");
	printf("**11. 班最低分    **\n");
	printf("**12. 班平均分    **\n");
	printf("**13. 用户备份    **\n");
	printf("**14. 用户恢复    **\n");
	printf("**15. 学生备份    **\n");
	printf("**16. 学生恢复    **\n");
	printf("**                **\n");
	printf("********************\n");
	printf("请选择功能：");
	while (scanf("%d", &i) != EOF)
	{
		switch (i)
		{
		case 0:
			information_output();
			return 0;
		case 1:
			input();
			break;
		case 2:
			find_meun();
			break;
		case 3:
			score_sort();
			break;
		case 4:
			score_statistics();
			break;
		case 5:
			grades_compute();
			break;
		case 6:
			grades_sort();
			break;
		case 7:
			person_max();
			break;
		case 8:
			person_min();
			break;
		case 9:
			person_average();
			break;
		case 10:
			class_max();
			break;
		case 11:
			class_min();
			break;
		case 12:
			class_average();
			break;
		case 13:
			information_save();
			break;
		case 14:
			information_load();
			break;
		case 15:
			user_save();
			break;
		case 16:
			user_load();
			break;
		default:
			printf("请重新输入正确的序号\n");
			break;
		}
		clean_screen();
		main_meun();
	}
}
/*学生录入*/int input()
{
	list->next = NULL;
	printf("请输入学号：");
	scanf(" %s", p->student.num);
	printf("请输入姓名：");
	scanf(" %s", p->student.name);
	printf("请输入班级：");
	scanf(" %s", p->student.Class);
	printf("请输入十个科目的成绩：");
	for (i = 0; i < 10; i++)
	{
		scanf(" %d", &p->student.score[i]);
		if (p->student.score[i] < 0 || p->student.score[i]>100)
		{
			printf("\n每个科目的成绩都应该在0-100之间，请重新输入正确成绩\n");
			i--;
			continue;
		}
	}
	printf("请输入十个科目的学分：");
	for (i = 0; i < 10; i++)
	{
		scanf(" %f", &p->student.credit[i]);
	}
	num++;
	p1 = head->next;
	while (p1 != NULL)
	{
		if (strcmp(p1->student.num, p->student.num) < 0 && strcmp(p1->next->student.num, p->student.num) > 0)
		{
			p->next = p1->next;
			p1->next = p;
			p->prew = p1;
			p1->next->prew = p;
			p = (struct list*)malloc(sizeof(struct list));
			return 0;
		}
		p1 = p1->next;
	}
	list->next = p;
	p->prew = list;
	list = p;
	list->next = NULL;
	p = (struct list*)malloc(sizeof(struct list));
	return 0;
}
/*成绩查询*/int find_meun();
/*成绩排序*/int score_sort()
{
	int* a;
	int j, max, m, min;
	a = (int*)calloc(sizeof(int), num);
	p = head->next;
	for (i = 0; i < num; i++)
	{
		for (a[i] = 0, j = 0; j < 10; j++)
		{
			a[i] += p->student.score[j];
		}
		p = p->next;
	}
	for (i = 1, min = 0; i < num; i++)
	{
		if (a[i] < a[min])min = i;
	}
	for (i = 0, m = 1000; i < num; i++)
	{
		max = min;
		for (j = 0; j < num; j++)
		{
			if (a[max] < a[j] && a[j] < m)max = j;
		}
		p = head->next;
		for (j = 0; j < max && p != NULL; j++)p = p->next;
		printf("%s ", p->student.name);
		m = a[max];
	}
	printf("\n");
	return 0;
}
/*成绩统计*/int score_statistics()
{
	int number[10][5] = { 0 }, j;
	p = head->next;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (p->student.score[j] >= 90 && p->student.score[i] <= 100)number[j][0]++;
			else if (p->student.score[i] >= 80)number[j][1]++;
			else if (p->student.score[i] >= 70)number[j][2]++;
			else if (p->student.score[i] >= 60)number[j][3]++;
			else number[j][4]++;
		}
		p = p->next;
	}
	printf("100~90 90~80  80~70  70~60  60~0\n");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%6d", number[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*绩点计算*/int grades_compute()
{
	int j;
	p = head->next;
	for (i = 0; i < num; i++)
	{
		printf("%s  ", p->student.name);
		for (j = 0; j < 10; j++)
		{
			if (p->student.score[j] < 60)printf("0  ");
			else
			{
				printf("%.1f  ", (p->student.score[j] - 50.0) / 10);
			}
		}
		p = p->next;
		printf("\n");
	}
	return 0;
}
/*绩点排序*/int grades_sort()
{
	int j, max, min;
	long double* score, sum, m;
	score = (long double*)calloc(sizeof(long double), num);
	p = head->next;
	for (i = 0; i < num; i++)
	{
		score[i] = 0;
		for (j = 0, sum = 0; j < 10; j++)
		{
			if (p->student.score[j] >= 60)
			{
				score[i] += ((p->student.score[j] - 50.0) / 10.0 * p->student.credit[j]);
			}
			sum += p->student.credit[j];
		}
		score[i] /= sum;
		p = p->next;
	}
	for (i = 1, min = 0; i < num; i++)if (score[min] > score[i])min = i;
	for (i = 0, m = 1000; i < num; i++)
	{
		max = min;
		for (j = 0; j < num; j++)
		{
			if (score[max] - score[j] < 0 && score[j] - m < 0)max = j;
		}
		p = head->next;
		for (j = 0; j < max && p != NULL; j++)p = p->next;
		printf("%s：%.2Lf\n", p->student.name, score[max]);
		m = score[max];
	}
	return 0;
}
/*最高分*/int person_max()
{
	int j, max[2];
	for (i = 0; i < 10; i++)
	{
		p = head->next;
		max[0] = p->student.score[i];
		max[1] = 0;
		for (j = 1; j < num && p != NULL; j++)
		{
			p = p->next;
			if (p->student.score[i] > max[0])
			{
				max[0] = p->student.score[i];
				max[1] = j;
			}
		}
		p = head->next;
		for (j = 0; j < max[1]; j++)
		{
			p = p->next;
		}
		printf("%s %s %d\n", p->student.num, p->student.name, p->student.score[i]);
	}
	return 0;
}
/*最低分*/int person_min()
{
	int j, min[2];
	for (i = 0; i < 10; i++)
	{
		p = head->next;
		min[0] = p->student.score[i];
		min[1] = 0;
		for (j = 1; j < num && p != NULL; j++)
		{
			p = p->next;
			if (p->student.score[i] < min[0])
			{
				min[0] = p->student.score[i];
				min[1] = j;
			}
		}
		p = head->next;
		for (j = 0; j < min[1]; j++)
		{
			p = p->next;
		}
		printf("%s %s %d\n", p->student.num, p->student.name, p->student.score[i]);
	}
	printf("功能已完成，按回车键以继续");
	return 0;
}
/*平均分*/int person_average()
{
	int j;
	float average[10] = { 0 };
	p = head->next;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < 10; j++)
		{
			average[j] += p->student.score[j];
		}
		p = p->next;
	}
	for (i = 0; i < 10; i++)printf("%.2f  ", average[i] / 10);
	printf("\n");
	return 0;
}
/*班最高分*/int class_max()
{
	struct list* p1;
	char Class[20] = { 0 };
	int score[10][2], j, m;
	p = head->next;
	strcpy(Class, p->student.Class);
	for (m = 0; m < 10; m++)//对score进行初始化处理
	{
		score[m][0] = p->student.score[m];
		score[m][1] = 0;
	}
	for (i = 0; i < num; i++)
	{
		if (strcmp(Class, p->student.Class) != 0)
		{
			printf("%s\n", Class);
			for (m = 0; m < 10; m++)
			{
				p1 = head->next;
				for (j = 0; j < score[m][1]; j++)p1 = p1->next;
				printf("%s %s %d\n", p1->student.num, p1->student.name, p1->student.score[m]);
			}
			strcpy(Class, p->student.Class);
			for (m = 0; m < 10; m++)
			{
				score[m][0] = p->student.score[m];
				score[m][1] = i;
			}
		}
		else
		{
			for (m = 0; m < 10; m++)
			{
				if (score[m][0] < p->student.score[m])
				{
					score[m][0] = p->student.score[m];
					score[m][1] = i;
				}
			}
		}
		p = p->next;
	}
	printf("%s\n", Class);
	for (m = 0; m < 10; m++)
	{
		p1 = head->next;
		for (j = 0; j < score[m][1]; j++)p1 = p1->next;
		printf("%s %s %d\n", p1->student.num, p1->student.name, p1->student.score[m]);
	}
	return 0;
}
/*班最低分*/int class_min()
{
	struct list* p1;
	char Class[20] = { 0 };
	int score[10][2], j, m;
	p = head->next;
	strcpy(Class, p->student.Class);
	for (m = 0; m < 10; m++)
	{
		score[m][0] = p->student.score[m];
		score[m][1] = 0;
	}
	for (i = 0; i < num; i++)
	{
		if (strcmp(Class, p->student.Class) != 0)
		{
			printf("%s\n", Class);
			for (m = 0; m < 10; m++)
			{
				p1 = head->next;
				for (j = 0; j < score[m][1]; j++)p1 = p1->next;
				printf("%s %s %d\n", p1->student.num, p1->student.name, p1->student.score[m]);
			}
			strcpy(Class, p->student.Class);
			for (m = 0; m < 10; m++)
			{
				score[m][0] = p->student.score[m];
				score[m][1] = i;
			}
		}
		else
		{
			for (m = 0; m < 10; m++)
			{
				if (score[m][0] > p->student.score[m])
				{
					score[m][0] = p->student.score[m];
					score[m][1] = i;
				}
			}
		}
		p = p->next;
	}
	printf("%s\n", Class);
	for (m = 0; m < 10; m++)
	{
		p1 = head->next;
		for (j = 0; j < score[m][1]; j++)p1 = p1->next;
		printf("%s %s %d\n", p1->student.num, p1->student.name, p1->student.score[m]);
	}
	return 0;
}
/*班平均分*/int class_average()
{
	char Class[20];
	float score[10], number;
	int m;
	p = head->next;
	strcpy(Class, p->student.Class);
	for (m = 0; m < 10; m++)score[m] = p->student.score[m];
	number = 1;
	for (i = 0; i < num; i++)
	{
		if (strcmp(Class, p->student.Class) != 0)
		{
			printf("%s\n", Class);
			for (m = 0; m < 10; m++)printf("%.2f\n", score[m] / number);
			strcpy(Class, p->student.Class);
			for (m = 0; m < 10; m++)score[m] = p->student.score[m];
			number = 1;
		}
		else
		{
			for (m = 0; m < 10; m++)score[m] += p->student.score[m];
			number++;
		}
		p = p->next;
	}
	printf("%s\n", Class);
	for (m = 0; m < 10; m++)printf("%.2f\n", score[m] / number);
	return 0;
}
/*用户备份*/int user_save()
{
	FILE* f = fopen(".\\User save.txt", "w");
	User_p = User_head->next;
	while (User_p->next != NULL)
	{
		fprintf(f, "%s %s %s\n", User_p->user.name, User_p->user.password, User_p->user.number);
		User_p = User_p->next;
	}
	fclose(f);
	return 0;
}
/*用户恢复*/int user_load()
{
	FILE* f = fopen(".\\User save.txt", "r");
	User_num = 0;
	User_head = (struct User_list*)malloc(sizeof(struct User_list));
	User_list = (struct User_list*)malloc(sizeof(struct User_list));
	User_head->next = User_p;
	User_p->prew = User_head;
	User_p->next = NULL;
	while (fscanf(f, "%s %s %s", User_p->user.name, User_p->user.password, User_p->user.number) != EOF)
	{
		User_list = User_p;
		User_num++;
		User_p = (struct User_list*)malloc(sizeof(struct User_list));
		User_list->next = User_p;
		User_p->prew = User_list;
		User_p->next = NULL;
	}
	fclose(f);
	return 0;
}
/*学生备份*/int information_save()
{
	FILE* f = fopen(".\\Student save.txt", "w");
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
	return 0;
}
/*学生恢复*/int information_load()
{
	FILE* f = fopen(".\\Student save.txt", "r");
	num = 0;
	head = (struct list*)malloc(sizeof(struct list));
	list = (struct list*)malloc(sizeof(struct list));
	head->next = p;
	p->prew = head;
	p->next = NULL;
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
	fclose(f);
	return 0;
}