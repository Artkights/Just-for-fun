#ifndef GLOBE_H
#define GLOBE_H
extern struct List *head;
extern struct List *list;
extern struct List *p;
extern struct User_List *User_head;
extern struct User_List *User_list;
extern struct User_List *User_p;
extern struct Province_statistics *Province_head;
extern struct Province_statistics *Province_list;
extern struct Province_statistics *Province_p;
extern struct Search *search_head;
extern struct Search *search_list;
extern struct Search *search_p;
extern int num;//录入的学生个数
extern int User_num;//录入的用户个数
extern int search_num;
extern int state;//标记权限，0为教师，1为学生;
extern int course_num;
#endif // GLOBE_H
