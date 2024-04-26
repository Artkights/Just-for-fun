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

//xΪ�����꣬yΪ������ 

/*������*/struct Robot//���ĳ�ʼλ��Ϊ�����
{
	int x;/*����������Ϣ�������˺�����*/
	int y;/*����������Ϣ��������������*/
	int goods;//����������Ϣ���Ƿ�Я������,0ΪδЯ����1ΪЯ��
	int status = 0;/*0Ϊ���У�1Ϊ������*/
	int id;/*������Ŀ�겴λID*/
	int time = 0;//�������ƶ��Ĳ���
	int ID;//�����˵����
	char road[1000] = {};/*�������˶�·��*/
}robot[robot_num];/*������*/

/*��λ*/struct Berth
{
	int x;/*��λ������*/
	int y;/*��λ������*/
	int id;//��λID
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

struct Node
{
	int x;
	int y;
	int time;
	int front;
	char path[1000];
};

/*��valΪ�ؼ��ֵ��Զ���ȽϺ���*/struct good_cmp
{
	bool operator ()(const goods& a, const goods& b)const
	{
		return a.val > b.val;
	}

};/*��valΪ�ؼ��ֵ��Զ���ȽϺ���*/

/*��distanceΪ�ؼ��ֵ��Զ���ȽϺ���*/struct berth_cmp
{
	bool operator()(const Berth_choose& A, const Berth_choose& B)const
	{
		return A.distance < B.distance;
	};/*��distanceΪ�ؼ��ֵ��Զ���ȽϺ���*//*��distanceΪ�ؼ��ֵ��Զ���ȽϺ���*/
};

struct Node_compare
{
	bool operator()(const Node& A, const Node& B)const
	{
		if ((A.x == B.x) && (A.y == B.y))return 0;
		else return A.front < B.front;
	}
};

/*��ͼ�ж�*/struct road_search
{
	bool ch[210][210] = {};
}map;

int zhen = 1;
int money;/*��ǰ��Ǯ��*/
int boat_capacity;/*�����ݻ�*/
int id;/*���*/
char ch[N][N];//��ͼ:'.'Ϊ½��,'*'Ϊ����,'#'Ϊ�ϰ�,'A'Ϊ��������ʼλ��,'B'Ϊ��λλ��
set<goods, good_cmp>good;
queue<Robot>robot_queue;
bool robot_judge(int ID, int x, int y, int mx, int my, int time)//BFS���������ܷ񵽴�Ŀ�ĵز���¼·��
{
	set<Node,Node_compare>robot_moving;//BFS����
	road_search path = map;
	Node a, n;
	a.x = x;
	a.y = y;
	a.time = 0;
	robot_moving.insert(a);
	path.ch[a.x][a.y] = 1;
	while (!robot_moving.empty())
	{
		auto a = robot_moving.begin();
		if (path.ch[a->x][a->y + 1] == 0 && a->y <= 200 && a->time < time)//����ͼ��Ϊ������ϰ��ұ��Ϊ0�����ǲ����
		{
			n = *a;
			n.y++;
			n.path[n.time] = '0';
			n.time++;
			n.front = abs(n.x - mx) + abs(n.y - my);
			robot_moving.insert(n);
			path.ch[n.x][n.y] = 1;
		}
		if (path.ch[a->x][a->y - 1] == 0 && a->y > 0 && a->time < time)//����ͼ��Ϊ������ϰ��ұ��Ϊ0�����ǲ����
		{
			n = *a;
			n.y--;
			n.path[n.time] = '1';
			n.time++;
			n.front = abs(n.x - mx) + abs(n.y - my);
			robot_moving.insert(n);
			path.ch[n.x][n.y] = 1;
		}
		if (path.ch[a->x + 1][a->y] == 0 && a->x <= 200 && a->time < time)//����ͼ��Ϊ������ϰ��ұ��Ϊ0�����ǲ����
		{
			n = *a;
			n.x++;
			n.path[n.time] = '3';
			n.time++;
			n.front = abs(n.x - mx) + abs(n.y - my);
			robot_moving.insert(n);
			path.ch[n.x][n.y] = 1;
		}
		if (path.ch[a->x - 1][a->y] == 0 && a->x > 0 && a->time < time)//����ͼ��Ϊ������ϰ��ұ��Ϊ0�����ǲ����
		{
			n = *a;
			n.x--;
			n.path[n.time] = '2';
			n.time++;
			n.front = abs(n.x - mx) + abs(n.y - my);
			robot_moving.insert(n);
			path.ch[n.x][n.y] = 1;
		}
		if (a->x == mx && a->y == my)//������Ŀ�ĵ�,���˳�ѭ��������1,�����Ӧ�Ļ����˴���·��
		{
			n=*a;
			n.path[n.time] = '\0';
			strcpy(robot[ID].road, n.path);
			robot[ID].time = n.time;
			return 1;
		}
		else //����ΪĿ�ĵأ������
		{
			robot_moving.erase(a);
		}
	}
	return 0;//��������δ�ܴﵽĿ�ĵأ��򷵻��޷��ﵽ
}
int robot_search(int ID)//����������ǰ��Ŀ�ĵ�
{
	if (robot[ID].goods == 0)//��������δЯ�����������ǰ������ص�
	{
		for (auto p = good.begin(); p != good.end(); p++)
		{	
			while(p->time <= zhen)
			{
				p=good.erase(p);
				if (p == good.end())return 0;
			}
			if (p->state == 0)
			{
				int distance = abs(robot[ID].x - p->x) + abs(robot[ID].y - p->y);
				if (distance < p->time - zhen)
				{
					if (robot_judge(ID, robot[ID].x, robot[ID].y, p->x, p->y, p->time - zhen))
					{
						robot[ID].status = 1;
						goods a = *p;
						a.state = 2;
						good.erase(p);
						good.insert(a);
						return 1;//�ɹ�
					}
				}
			}
		}
	}
	else//��������Я�����������ǰ����λ
	{
		set<Berth_choose, berth_cmp>a;
		Berth_choose b;
		for (int i = 0; i < berth_num; i++)
		{
			b.distance = abs(berth[i].x - robot[ID].x) + abs(berth[i].y - robot[ID].y);
			b.berth = berth[i];
			a.insert(b);
		}
		for (auto p = a.begin(); p != a.end(); p++)
		{
			if(p->berth.state==0)
			{
				if (robot_judge(ID, robot[ID].x, robot[ID].y, p->berth.x, p->berth.y, 1000))
				{
					robot[ID].status = 1;
					robot[ID].id = p->berth.id;
					return 1;//�ɹ�
				}
			}
		}
	}
	return 0;//ʧ��
}
int robot_move(int ID)//�������ƶ�
{
	printf("move %d %c\n", ID, robot[ID].road[strlen(robot[ID].road)-robot[ID].time]);//����·���ƶ�
	fflush(stdout);
	robot[ID].time--;
	if (robot[ID].time==0)//���Ѿ��������·���ƶ�����ȡ��Ż���
	{
		if (robot[ID].goods == 0)//��δЯ�������ȡ��
		{
			printf("get %d\n", ID);
			fflush(stdout);
		}
		else//��Я�������Ż�
		{
			printf("pull %d\n", ID);
			fflush(stdout);
			berth[robot[ID].id].goods_num++;
			robot[ID].id = -1;
		}
		memset(robot[ID].road, 0, sizeof(robot[ID].goods));
		robot[ID].status = 0;
	}
	return 0;
}
/*��ʼ��*/void Init()
{
	for (int i = 1; i <= n; i++)//��ͼ��ʼ��
	{
		scanf("%s", ch[i] + 1);
		for (int j = 1; j <= n; j++)
		{
			if (ch[i][j] == '#' || ch[i][j] == '*')map.ch[i][j] = 1;
			else map.ch[i][j] = 0;
		}
	}
	for (int i = 0; i < berth_num; i++)//��λ��ʼ��
	{
		int id;
		scanf("%d", &id);
		scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
		berth[i].id = id;
	}
	for (int i = 0; i < robot_num; i++)//�����˳�ʼ��
	{
		robot[i].ID = i;
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
		if (robot[i].status == 0)//�����������
		{
			robot[i].status = 2;
			robot_queue.push(robot[i]);
		}
		else if (sts == 0)
		{
			if (robot[i].goods == 0)robot[i].status = 0;
			else
			{
				for (int j = 0; j < berth_num; j++)
				{
					if (robot_judge(j, robot[j].x, robot[j].y, berth[i].x, berth[i].y, 1000))
					{
						robot[j].id = berth[i].id;
						break;
					}
				}
			}
		}
	}
	if (!robot_queue.empty())//�����ڿ��еĻ����˲�Ϊ�գ������
	{
		Robot a=robot_queue.front();	
		if (!robot_search(a.ID))robot_queue.push(a);//������ʧ�ܣ����������
		robot_queue.pop();
	}
	for (int i = 0; i < boat_num; i++)//���մ�����Ϣ
	{
		scanf("%d%d", &boat[i].status, &boat[i].pos);
		if (boat[i].status == 1 && boat[i].pos != boat[i].local)//����������Ŀ�ĵ���λ�ò��������ѵ���Ŀ�겴λ
		{
			boat[i].local = boat[i].pos;
			if (boat[i].id != -1)berth[boat[i].id].state = 1;
		}
		if (boat[i].pos == -1 && boat[i].local == -1 && boat[i].status == 1)//���������������Ŀ�겴λ���������л���Ĳ�λ
		{
			for (int j = 0; j < berth_num; j++)
			{
				if (berth[j].goods_num != 0 && berth[j].state == 0)
				{
					boat[i].id = j;
					berth[j].state = 2;
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
		if(robot[i].status==1)
		{
			robot_move(i);//�������ƶ�
		}
	}
	for (int i = 0; i < boat_num; i++)//����
	{
		if(boat[i].local!=-1)//�������������
		{
			if (boat[i].num == boat_capacity || berth[boat[i].id].goods_num == 0)//����ػ�������λ��������Ϊ0���򷵺�
			{
				berth[boat[i].id].boat_id = -1;
				berth[boat[i].id].state = 0;
				boat[i].id = -1;
				printf("go %d\n", i);
				fflush(stdout);
			}
		}
		else if (boat[i].status == 1 && boat[i].id != -1 && boat[i].local == -1)//������λ���������Ŀ�겴λ��Ϊ����㣬��ǰ��Ŀ�겴λ
		{
			printf("ship %d %d\n", i, boat[i].id);
			fflush(stdout);
		}
	}
	for (int i = 0; i < berth_num; i++)//����λװ��
	{
		if(berth[i].state==1)//����λ���д�
		{
			if (berth[i].goods_num > berth[i].loading_speed && boat[berth[i].boat_id].num + berth[i].loading_speed < boat_capacity)
			{//�����λ����������С��ÿ֡װ�������Ҵ���װ�غ�δ�����������
				berth[i].goods_num -= berth[i].loading_speed;
				boat[berth[i].boat_id].num += berth[i].loading_speed;
			}
			else if (berth[i].goods_num <= berth[i].loading_speed)
			{//����λ��������С��ÿ֡װ������
				boat[berth[i].boat_id].num += berth[i].goods_num;
				berth[i].goods_num = 0;
			}
			else if (boat[berth[i].boat_id].num + berth[i].loading_speed >= boat_capacity)
			{//������װ�غ��Դﵽ�������
				berth[i].goods_num -= (boat_capacity - boat[berth[i].boat_id].num);
				boat[berth[i].boat_id].num = boat_capacity;
			}
		}
	}
	return 0;
}
int main()
{
	//FILE* f = freopen("D:\\Downloads\\WindowsReleasev1.2\\WindowsReleasev1.2\\output.txt", "r", stdin);
	//FILE* a = freopen(".\\output.txt", "w", stdout);
	Init();
	cout << map.ch[190][52]<<endl;
	for (; zhen <= 15000; zhen++)
	{
		printf("%d\n", zhen);
		Input();
		Output();
		printf("OK\n");
		fflush(stdout);
	}
}