#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<io.h>
typedef struct
{
	int score;//�γ̳ɼ�
	float credit;//�γ�ѧ��
	float grade;//���Ƽ���
	char teacher[30];//�ڿ���ʦ
	char name[5];//�γ�����
}Course;
typedef struct 
{
	float grade;//�ܼ���
	char num[30];//ѧ��
	char name[30];//����
	char Class[30];//�༶
	char province[30];//ʡ��
	Course course[5];//�γ���Ϣ
}Student;
struct list
{
	Student student;
	struct list *next;
	struct list *prew;
}*p, * list, * p1, * head;
typedef struct
{
	char name[20];//�˺�
	char password[20];//����
	char number[20];//�һ��������Ϣ
	char identity[10];
}User;
struct User_list
{
	User user;
	struct User_list* next;
	struct User_list* prew;
}*User_p,*User_list,*User_head;
struct Search
{
	struct list* p;
	struct Search* next;
}*search_head,*search_list,*search_p;
typedef struct 
{
	struct list* p;
	struct Search* next;
	int num;
}Sort;
struct Province_statistics
{
	char province[10];
	int num;
	struct Province_statistics* next;
}*Province_head,*Province_p,*Province_list;
int num;//¼���ѧ������
int User_num;//¼����û�����
int search_num;
int i;//ѭ���ã���ʵ��
int state;//���Ȩ�ޣ�0Ϊ��ʦ��1Ϊѧ��;
int course_num;