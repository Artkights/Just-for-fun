#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"information struct.h"
/*���˵�*/int main_meun()
{
	printf("******���ܲ˵�******\n");
	printf("**                **\n");
	printf("**0.  ��    ��    **\n");
	printf("**1.  �ɼ�¼��    **\n");
	printf("**2.  �ɼ���ѯ    **\n");
	printf("**3.  �ɼ�����    **\n");
	printf("**4.  �ɼ�ͳ��    **\n");
	printf("**5.  �������    **\n");
	printf("**6.  ��������    **\n");
	printf("**7.  �� �� ��    **\n");
	printf("**8.  �� �� ��    **\n");
	printf("**9.  ƽ �� ��    **\n");
	printf("**10. ����߷�    **\n");
	printf("**11. ����ͷ�    **\n");
	printf("**12. ��ƽ����    **\n");
	printf("**13. �û�����    **\n");
	printf("**14. �û��ָ�    **\n");
	printf("**15. ѧ������    **\n");
	printf("**16. ѧ���ָ�    **\n");
	printf("**                **\n");
	printf("********************\n");
	printf("��ѡ���ܣ�");
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
			printf("������������ȷ�����\n");
			break;
		}
		clean_screen();
		main_meun();
	}
}
/*ѧ��¼��*/int input()
{
	list->next = NULL;
	printf("������ѧ�ţ�");
	scanf(" %s", p->student.num);
	printf("������������");
	scanf(" %s", p->student.name);
	printf("������༶��");
	scanf(" %s", p->student.Class);
	printf("������ʮ����Ŀ�ĳɼ���");
	for (i = 0; i < 10; i++)
	{
		scanf(" %d", &p->student.score[i]);
		if (p->student.score[i] < 0 || p->student.score[i]>100)
		{
			printf("\nÿ����Ŀ�ĳɼ���Ӧ����0-100֮�䣬������������ȷ�ɼ�\n");
			i--;
			continue;
		}
	}
	printf("������ʮ����Ŀ��ѧ�֣�");
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
/*�ɼ���ѯ*/int find_meun();
/*�ɼ�����*/int score_sort()
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
/*�ɼ�ͳ��*/int score_statistics()
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
/*�������*/int grades_compute()
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
/*��������*/int grades_sort()
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
		printf("%s��%.2Lf\n", p->student.name, score[max]);
		m = score[max];
	}
	return 0;
}
/*��߷�*/int person_max()
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
/*��ͷ�*/int person_min()
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
	printf("��������ɣ����س����Լ���");
	return 0;
}
/*ƽ����*/int person_average()
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
/*����߷�*/int class_max()
{
	struct list* p1;
	char Class[20] = { 0 };
	int score[10][2], j, m;
	p = head->next;
	strcpy(Class, p->student.Class);
	for (m = 0; m < 10; m++)//��score���г�ʼ������
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
/*����ͷ�*/int class_min()
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
/*��ƽ����*/int class_average()
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
/*�û�����*/int user_save()
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
/*�û��ָ�*/int user_load()
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
/*ѧ������*/int information_save()
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
/*ѧ���ָ�*/int information_load()
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