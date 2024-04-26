#pragma once
#ifndef STRUCT_H
#define STRUCT_H
#include<stdio.h>
#include<stdlib.h>
#include<io.h>
typedef struct
{
    char num[30];//学号
    char*num_;
    char name[30];//姓名
    char*name_;
    char Class[30];//班级
    char *Class_;
    char course[3][10];
}student;
struct List
{
    student C_student;
    struct List *next;
    struct List *prew;
};
typedef struct
{
    char *name_;//账号
    char *password_;//密码
    char *number_;//找回密码的信息
    char *identity_;
    char name[30];
    char password[30];
    char number[30];
    char identity[30];
}User;
struct User_List
{
    User user;
    struct User_List* next;
    struct User_List* prew;
};
struct Sort
{
    student p;
    struct Sort* next;
};
#endif // STRUCT_H
