#include<QDebug>
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
/*学生信息导入*/void information_input()
{
    num = 0;
    course_num = 3;
    head->next = list;
    list->prew = head;
    list->next = NULL;
    if(access(".\\Student.txt",0)==0)
    {
        FILE* f = fopen(".\\student_sort.txt", "r");
        fscanf(f,"%s\t%s\t%s\t%s\t%s\t%s",head->C_student.num,head->C_student.name,head->C_student.Class,head->C_student.course[0],head->C_student.course[1],head->C_student.course[2]);
        qDebug()<<head->C_student.num<<head->C_student.name<<head->C_student.Class<<head->C_student.course[0]<<head->C_student.course[1]<<head->C_student.course[2];
        while (fscanf(f, "%s\t%s\t%s\t%s\t%s\t%s", list->C_student.num, list->C_student.name, list->C_student.Class,list->C_student.course[0],list->C_student.course[1],list->C_student.course[2]) != EOF)
        {
            list->next = p;
            p->prew = list;
            p->next = NULL;
            list = p;
            p = (struct List*)malloc(sizeof(struct List));
            num++;
        }
        for(p=head;p->next!=list;p=p->next)
        {
            qDebug()<<p->next->C_student.num<<p->next->C_student.name<<p->next->C_student.Class<<p->next->C_student.course[0]<<p->next->C_student.course[1]<<p->next->C_student.course[2]<<endl;
        }
        fclose(f);
    }
    else
    {
        FILE* f = fopen(".\\Student.txt", "w");
        fclose(f);
        return information_input();
    }
}
/*学生信息导出*/void information_output()
{
    FILE* f = fopen(".\\Student.txt", "w");
    for(p = head;p->next!=list;p=p->next)
    {
        fprintf(f, "\t%s\t%s\t%s", p->C_student.num, p->C_student.name, p->C_student.Class);
        for(int i=0;i<course_num;i++)
        {
            fprintf( f,"\t%d",p->C_student.course[i]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
/*用户信息导入*/void user_input()
{
    if (access(".\\User information.txt", 0) == 0)
    {
        User_num = 0;
        FILE* f = fopen(".\\User information.txt", "r");
        User_head->next = User_list;
        User_list->prew = User_head;
        User_list->next = NULL;
        while (fscanf(f, " %s %s %s %s", User_list->user.name,User_list->user.password,User_list->user.number,User_list->user.identity) != EOF)
        {
            qDebug()<<User_list->user.name;
            User_p = (struct User_List*)malloc(sizeof(struct User_List));
            User_list->next = User_p;
            User_p->prew = User_list;
            User_list = User_p;
            User_list->next = NULL;
            User_num++;
        }
        fclose(f);
    }
    else
    {
        FILE* f = fopen(".\\User information.txt", "w");
        fclose(f);
        return user_input();
    }
}
/*用户信息导出*/void user_output()
{
    FILE* f = fopen(".\\User information.txt", "w");
    qDebug()<<"1";
    for (User_p = User_head;User_p->next != User_list;User_p = User_p->next)
    {
        qDebug()<<"2";
        fprintf(f, "%s %s %s %s\n", User_p->next->user.name, User_p->next->user.password,User_p->next->user.number,User_p->next->user.identity);
    }
    fclose(f);
}
