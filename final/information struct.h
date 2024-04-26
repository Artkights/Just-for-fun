#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<io.h>
typedef struct
{
	int score;//课程成绩
	float credit;//课程学分
	float grade;//单科绩点
	char teacher[30];//授课老师
	char name[5];//课程名称
}Course;
typedef struct 
{
	float grade;//总绩点
	char num[30];//学号
	char name[30];//姓名
	char Class[30];//班级
	char province[30];//省份
	Course course[5];//课程信息
}Student;
struct list
{
	Student student;
	struct list *next;
	struct list *prew;
}*p, * list, * p1, * head;
typedef struct
{
	char name[20];//账号
	char password[20];//密码
	char number[20];//找回密码的信息
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
int num;//录入的学生个数
int User_num;//录入的用户个数
int search_num;
int i;//循环用，无实意
int state;//标记权限，0为教师，1为学生;
int course_num;