#include"information struct.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*�����˵�*/int search_meun()
{
	printf("******���ܲ˵�******\n");
	printf("**                **\n");
	printf("**0.  ��    ��    **\n");
	printf("**1.  ��Ϣ�޸�    **\n");
	printf("**2.  ��Ϣɾ��    **\n");
	printf("**                **\n");
	printf("********************\n");
	printf("��ѡ���ܣ�");
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
		printf("��������ȷ����ţ�\n");
		clean_screen();
		return search_meun();
	}
}
/*ѧ����Ϣ�޸�*/int informaton_change()
{
	int k;
	printf("������Ҫ�޸ĵ�ѧ����Ϣ����ţ�");
	scanf("%d", &i);
	search_p = search_head;
	for (k = 0; k < i; k++)
	{
		search_p = search_p->next;
	}
	printf("������Ҫ�޸ĵ���Ϣ��\n");
	printf("0.�˳�\n");
	printf("1.ѧ��\n");
	printf("2.����\n");
	printf("3.�༶\n");
	printf("4.�ɼ�\n");
	printf("5.ѧ��\n");
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		clean_screen();
		return search_meun();
	case 1:
		printf("�������޸ĺ��ѧ�ţ�");
		scanf("%s", search_p->p->student.num);
		clean_screen();
		return search_meun();
	case 2:
		printf("�������޸ĺ��������");
		scanf("%s", search_p->p->student.name);
		clean_screen();
		return search_meun();
	case 3:
		printf("�������޸ĺ�İ༶��");
		scanf("%s", search_p->p->student.Class);
		clean_screen();
		return search_meun();
	case 4:
		printf("��������Ҫ�޸ĵĶ�Ӧ�γ̵���ţ�\n");
		scanf("%d", &i);//����Ӧ���ж�Ӧ�������
		printf("�������޸ĺ�ĳɼ���");
		scanf("%s", search_p->p->student.num[i - 1]);
		clean_screen();
		return search_meun();
	case 5:
		printf("��������Ҫ�޸ĵĶ�Ӧ�γ̵���ţ�\n");
		scanf("%d", &i);//����Ӧ���ж�Ӧ�������
		printf("�������޸ĺ��ѧ�֣�");
		scanf("%s", search_p->p->student.num[i - 1]);
		clean_screen();
		return search_meun();
	default:
		printf("������������ȷ����ţ�");
		clean_screen();
		return informaton_change();
		break;
	}
}
/*ѧ����Ϣɾ��*/int information_delete()
{
	int k;
	printf("������Ҫɾ����ѧ����Ϣ����Ż�����-1���أ�");
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