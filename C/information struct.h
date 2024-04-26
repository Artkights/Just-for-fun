typedef struct 
{
	char num[20];//学号
	char name[50];//姓名
	char Class[20];//班级
	int score[10];//课程成绩
	float credit[10];//课程学分
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
}*search_head, * search_list, * search_p;
int num;//录入的学生个数
int User_num;//录入的用户个数
int i;//循环用，无实意
