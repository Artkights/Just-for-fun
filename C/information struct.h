typedef struct 
{
	char num[20];//ѧ��
	char name[50];//����
	char Class[20];//�༶
	int score[10];//�γ̳ɼ�
	float credit[10];//�γ�ѧ��
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
int num;//¼���ѧ������
int User_num;//¼����û�����
int i;//ѭ���ã���ʵ��
