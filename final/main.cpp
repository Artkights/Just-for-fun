#include "widget.h"
#include "student.h"
#include "mainwindow.h"
#include "loginwindow.h"
#include "registerwindow.h"
#include "backups.h"
#include "changepassword.h"
#include <QApplication>
extern "C"
{
    #include"Struct.h"
}
extern void user_input();
struct List *head=(struct List*)malloc(sizeof(List));
struct List *list=(struct List*)malloc(sizeof(List));
struct List *p=(struct List*)malloc(sizeof(List));
struct User_List *User_head=(struct User_List*)malloc(sizeof(User_List));
struct User_List *User_list=(struct User_List*)malloc(sizeof(User_List));
struct User_List *User_p=(struct User_List*)malloc(sizeof(User_List));
int num;//录入的学生个数
int User_num;//录入的用户个数
int search_num;
int state;//标记权限，0为教师，1为学生;
int course_num;
int main(int argc, char *argv[])
{
    user_input();//用户信息需要对齐
    QApplication a(argc, argv);
    mainWindow w;
    w.show();
    return a.exec();
}
//main.cpp 1
//loginwindow.cpp 1
