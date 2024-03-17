#include <iostream>   
#include <vector>  
#include <queue>
#include <set>
#include <functional>
#include <algorithm>
#include<cmath>
#include <utility>
using namespace std;
const int n = 200;
/*����������*/const int robot_num = 10;
/*������*/const int boat_num = 5;
/*��λ����*/const int berth_num = 10;
const int N = 210;

/*������*/struct Robot//���ĳ�ʼλ��Ϊ�����
{
	int x;/*����������Ϣ�������˺�����*/
	int y;/*����������Ϣ��������������*/
	int goods;//����������Ϣ���Ƿ�Я������,0ΪδЯ����1ΪЯ��
	int status = 0;/*0Ϊ���У�1Ϊ������*/
	int mbx;/*������Ŀ����������*/
	int mby;/*������Ŀ�����������*/
	int id;/*������Ŀ�겴λID*/
	int time = 0;//�������ƶ��Ĳ���
	char road[401];/*�������˶�·��*/
}robot[robot_num];/*������*/

/*��λ*/struct Berth
{
	int x;/*��λ������*/
	int y;/*��λ������*/
	int transport_time;//����ʱ�䣺�Ӳ�λ���䵽������֡��
	int loading_speed;//װ���ٶȣ�ÿ֡װ�صĻ�����
	int goods_num = 0;/*װ�ػ�������*/
	int boat_id;/*װ���Ĵ������*/
	int state = 0;/*��λ��״̬��0Ϊ���У�1Ϊ�д�,2Ϊ����ΪĿ��*/
}berth[berth_num];/*��λ*/

/*��λѡ��*/struct Berth_choose
{
	Berth berth;
	int distance;//��������˵���λ�ľ���
};/*��λѡ��*/

/*��*/struct Boat
{
	int num = 0;/*װ�ػ�������*/
	int pos;/*����������Ϣ��Ŀ�ĵأ�Ŀ�겴λID,ǰ���������Ϊ-1*/
	int status;//����������Ϣ������״̬:0Ϊ�ƶ��У�1Ϊ�������У�װ����������ɣ�,2Ϊ��λ��ȴ�
	int id=-1;/*ǰ����λ��ID*/
	int local = -1;//����ǰ���ڲ�λID��-1Ϊ�����
}boat[boat_num];/*��*/

/*����*/struct goods
{
	int x;/*����������Ϣ�����������*/
	int y;/*����������Ϣ������������*/
	int val;/*����������Ϣ�������ֵ*/
	int state = 0;//����״̬:0Ϊδװ�أ�1Ϊ�����˰�����,2Ϊ��ѡΪĿ��
	int time;/*������ʧʱ��*/
	int id;/*������ΪĿ��Ļ�����*/
};/*����*/

struct node
{
	int x;//�ڵ������
	int y;//�ڵ�������
	int time;//�˶�����
	char path[401];//�ƶ���ʽ
};

/*��valΪ�ؼ��ֵ��Զ���ȽϺ���*/struct cmp
{
	bool operator ()(const goods& a, const goods& b)const
	{
		return a.val > b.val;
	}

};/*��valΪ�ؼ��ֵ��Զ���ȽϺ���*/

/*��distanceΪ�ؼ��ֵ��Զ���ȽϺ���*/struct com
{
	bool operator()(const Berth_choose& A, const Berth_choose& B)const
	{
		return A.distance < B.distance;
	};/*��distanceΪ�ؼ��ֵ��Զ���ȽϺ���*//*��distanceΪ�ؼ��ֵ��Զ���ȽϺ���*/
};

int zhen = 1;
int money;/*��ǰ��Ǯ��*/
int boat_capacity;/*�����ݻ�*/
int id;/*���*/
char ch[N][N];//��ͼ:'.'Ϊ½��,'*'Ϊ����,'#'Ϊ�ϰ�,'A'Ϊ��������ʼλ��,'B'Ϊ��λλ��
set<goods, cmp>good;

bool robot_judge(int ID,int x,int y,int mx,int my)//BFS���������ܷ񵽴�Ŀ�ĵز���¼·��
{
	bool robot_path[210][210] = {};//�ڵ���,0Ϊ���У�1Ϊ������
	queue<node>robot_moving;//BFS����
	node a,n;
	a.x = x;
	a.y = y;
	a.time = 0;
	robot_moving.push(a);
	while (!robot_moving.empty())
	{
		a = robot_moving.front();
		if (a.x != mx || a.y != my)//����ΪĿ�ĵأ������
		{
			robot_moving.pop();
		}
		else if (a.x == mx && a.y == my)//������Ŀ�ĵ�,���˳�ѭ��������1,�����Ӧ�Ļ����˴���·��
		{
			a.path[a.time] = '\0';
			strcpy(robot[ID].road, a.path);
			robot[ID].time = a.time;
			return 1;
		}
		if (ch[a.y][a.x + 1] != '*' && ch[a.y][a.x + 1] != '#' && robot_path[a.y][a.x + 1] == 0 && x + 1 < 200)//����ͼ��Ϊ������ϰ��ұ��Ϊ0�����ǲ����
		{
			n = a;
			n.x++;
			n.path[n.time] = '0';
			n.time++;
			robot_moving.push(n);
			robot_path[n.y][n.x] = 1;
		}
		if (ch[a.y][a.x - 1] != '*' && ch[a.y][a.x - 1] != '#' && robot_path[a.y][a.x - 1] == 0 && x - 1 >= 0)//����ͼ��Ϊ������ϰ��ұ��Ϊ0�����ǲ����
		{
			n = a;
			n.x--;
			n.path[n.time] = '1';
			n.time++;
			robot_moving.push(n);
			robot_path[n.y][n.x] = 1;
		}
		if (ch[a.y + 1][a.x] != '*' && ch[a.y + 1][a.x] != '#' && robot_path[a.y + 1][a.x] == 0 && y + 1 < 200)//����ͼ��Ϊ������ϰ��ұ��Ϊ0�����ǲ����
		{
			n = a;
			n.y++;
			n.path[n.time] = '2';
			n.time++;
			robot_moving.push(n);
			robot_path[n.y][n.x] = 1;
		}
		if (ch[a.y - 1][a.x] != '*' && ch[a.y - 1][a.x] != '#' && robot_path[a.y - 1][a.x] == 0 && y - 1 >= 0)//����ͼ��Ϊ������ϰ��ұ��Ϊ0�����ǲ����
		{
			n = a;
			n.y--;
			n.path[n.time] = '3';
			n.time++;
			robot_moving.push(n);
			robot_path[n.y][n.x] = 1;
		}
	}
	return 0;//��������δ�ܴﵽĿ�ĵأ��򷵻��޷��ﵽ
}
int robot_search(int ID)//����������ǰ��Ŀ�ĵ�
{
	if (robot[ID].goods == 0)//��������δЯ�����������ǰ������ص�
	{
		for (auto p = good.begin();p!=good.end(); p++)
		{		
			if (p->time > zhen && p->state == 0 && robot_judge(ID,robot[ID].x,robot[ID].y,p->x,p->y))
			{
				if (robot[ID].time + zhen >= p->time)
				{
					memset(robot[ID].road, 0, sizeof(robot[ID].road));
					robot[ID].time = 0;
				}
				else
				{
					robot[ID].mbx = p->x;
					robot[ID].mby = p->y;
					robot[ID].status = 1;
					goods a = *p;
					a.state = 2;
					good.erase(p);
					good.insert(a);
				}
				return 0;
			}
		}
	}
	else//��������Я�����������ǰ����λ
	{
		set<Berth_choose, com>a;
		Berth_choose b;
		for (int i = 0; i < 5; i++)
		{
			b.distance = abs(berth[i].x - robot[ID].x) + abs(berth[i].y - robot[ID].y);
			b.berth = berth[i];
			a.insert(b);
		}
		for (auto p = a.begin(); p != a.end(); p++)
		{
			if (robot_judge(ID,robot[ID].x, robot[ID].y, p->berth.x, p->berth.y))
			{
				robot[ID].mbx = p->berth.x;
				robot[ID].mby = p->berth.y;
				robot[ID].status = 1;
				return 0;
			}
		}
	}
	return 0;
}
int robot_move(int ID)//�������ƶ�
{
	printf("move %d %c\n", ID, robot[ID].road[strlen(robot[ID].road)-robot[ID].time]);//����·���ƶ�
	fflush(stdout);
	robot[ID].time--;
	if (robot[ID].time==-1)//���Ѿ��������·���ƶ�����ȡ��Ż���
	{
		if (robot[ID].goods == 0)//��δЯ�������ȡ��
		{
			printf("get %d\n", ID);
			fflush(stdout);
			robot[ID].goods = 1;
		}
		else//��Я�������Ż�
		{
			printf("pull %d\n", ID);
			fflush(stdout);
			robot[ID].goods = 0;
		}
		memset(robot[ID].road, 0, sizeof(robot[ID].goods));
		robot[ID].time = 0;
		robot[ID].status = 0;
	}
	return 0;
}
/*��ʼ��*/void Init()
{
	for (int i = 1; i <= n; i++)//��ͼ��ʼ��
	{
		scanf("%s", ch[i] + 1);
	}
	for (int i = 0; i < berth_num; i++)//��λ��ʼ��
	{
		int id;
		scanf("%d", &id);
		scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
	}
	scanf("%d", &boat_capacity);//��������ʼ��
	char okk[100];
	scanf("%s", okk);
	printf("OK\n");
	fflush(stdout);
}
/*��������*/int Input()
{
	scanf("%d%d", &id, &money);
	int num;//����������������
	scanf("%d", &num);
	for (int i = 0; i < num; i++)//�����������ﲢ�洢�����Ϣ
	{
		goods new_good;
		scanf("%d%d%d", &new_good.x, &new_good.y, &new_good.val);//���ܻ�������꼰��ֵ
		new_good.state = 0;//�����������״̬���Ϊδװ��
		new_good.time = id + 1000;//��¼��ʧʱ��
		good.insert(new_good);
	}
	for (int i = 0; i < robot_num; i++)//���ջ�������Ϣ
	{
		int sts;//������״̬��0Ϊ�ָ���1Ϊ��������
		scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &sts);//��¼������״̬
		if(robot[i].status==0)robot_search(i);//�������˲�����������״̬����ѡ��Ŀ��
	}
	for (int i = 0; i < boat_num; i++)//���մ�����Ϣ
	{
		scanf("%d%d", &boat[i].status, &boat[i].pos);
		if (boat[i].status == 1 && boat[i].pos != boat[i].local)//����������Ŀ�ĵ���λ�ò��������ѵ���Ŀ�겴λ
		{
			boat[i].local = boat[i].pos;
		}
		if (boat[i].pos == -1 && boat[i].local == -1 && boat[i].status == 1)//���������������Ŀ�겴λ���������л���Ĳ�λ
		{
			for (int j = 0; j < berth_num; j++)
			{
				if (berth[j].goods_num != 0 && berth[j].state == 0)
				{
					boat[i].id = j;
					berth[j].state = 2;
					boat->pos = j;
				}
			}
		}
	}
	char okk[100];
	scanf("%s", okk);
	return id;
}
/*�������*/int Output()
{
	for (int i = 0; i < robot_num; i++)//���������
	{
		if(robot[i].status==1)robot_move(i);//�������ƶ�
	}
	for (int i = 0; i < boat_num; i++)//����
	{
		if (boat[i].num == boat_capacity||berth[boat[i].id].goods_num==0&&boat[i].id!=-1)//����ػ�������λ��������Ϊ0���򷵺�
		{
			berth[boat[i].id].boat_id = -1;
			boat[i].pos = -1;
			printf("go %d\n", i);
			fflush(stdout);
		}
		else if (boat[i].status == 1 && boat[i].pos != -1 && boat[i].local == -1)//������λ���������Ŀ�겴λ��Ϊ����㣬��ǰ��Ŀ�겴λ
		{
			printf("ship %d\n", boat[i].pos);
			fflush(stdout);
		}
	}
	for (int i = 0; i < berth_num; i++)//����λװ��
	{
		if (berth[i].goods_num >= berth[i].loading_speed && boat[berth[i].boat_id].num + berth[i].loading_speed < boat_capacity)
		{//�����λ����������С��ÿ֡װ�������Ҵ���װ�غ�δ�����������
			berth[i].goods_num -= berth[i].loading_speed;
			boat[berth[i].boat_id].num += berth[i].loading_speed;
		}
		else if (berth[i].goods_num < berth[i].loading_speed)
		{//����λ��������С��ÿ֡װ������
			boat[berth[i].boat_id].num -= berth[i].goods_num;
			berth[i].goods_num = 0;
		}
		else if (boat[berth[i].boat_id].num + berth[i].loading_speed >= boat_capacity)
		{//������װ�غ��Դﵽ�������
			berth[i].goods_num -= (boat_capacity - boat[berth[i].boat_id].num);
			boat[berth[i].boat_id].num = boat_capacity;
			berth[i].state = 0;
		}
	}
	return 0;
}
int main()
{
	Init();
	for (; zhen <= 15000; zhen++)
	{
		Input();
		Output();
		printf("OK\n");
		fflush(stdout);
	}
}