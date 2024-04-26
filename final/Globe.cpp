extern "C"
{
    #include"Struct.h"
}
void origin()
{
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
}
