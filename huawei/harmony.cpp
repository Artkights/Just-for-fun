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
/*机器人数量*/const int robot_num = 10;
/*船数量*/const int boat_num = 5;
/*泊位数量*/const int berth_num = 10;
const int N = 210;

//x为纵坐标，y为横坐标 

/*机器人*/struct Robot//船的初始位置为虚拟点
{
	int x;/*交互输入信息，机器人横坐标*/
	int y;/*交互输入信息，机器人纵坐标*/
	int goods;//交互输入信息，是否携带货物,0为未携带，1为携带
	int status = 0;/*0为空闲，1为运输中*/
	int id;/*机器人目标泊位ID*/
	int time = 0;//机器人移动的步数
	int ID;//机器人的序号
	char road[1000] = {};/*机器人运动路径*/
}robot[robot_num];/*机器人*/

/*泊位*/struct Berth
{
	int x;/*泊位横坐标*/
	int y;/*泊位纵坐标*/
	int id;//泊位ID
	int transport_time;//运输时间：从泊位运输到虚拟点的帧数
	int loading_speed;//装载速度：每帧装载的货物数
	int goods_num = 0;/*装载货物数量*/
	int boat_id;/*装货的船的序号*/
	int state = 0;/*泊位的状态，0为空闲，1为有船,2为被视为目标*/
}berth[berth_num];/*泊位*/

/*泊位选择*/struct Berth_choose
{
	Berth berth;
	int distance;//计算机器人到泊位的距离
};/*泊位选择*/

/*船*/struct Boat
{
	int num = 0;/*装载货物数量*/
	int pos;/*交互输入信息，目的地：目标泊位ID,前往虚拟点则为-1*/
	int status;//交互输入信息，船的状态:0为移动中，1为正常运行（装货或运输完成）,2为泊位外等待
	int id=-1;/*前往泊位的ID*/
	int local = -1;//船当前所在泊位ID，-1为虚拟点
}boat[boat_num];/*船*/

/*货物*/struct goods
{
	int x;/*交互输入信息，货物横坐标*/
	int y;/*交互输入信息，货物纵坐标*/
	int val;/*交互输入信息，货物价值*/
	int state = 0;//货物状态:0为未装载，1为机器人搬运中,2为被选为目标
	int time;/*货物消失时间*/
	int id;/*将其视为目标的机器人*/
};/*货物*/

struct Node
{
	int x;
	int y;
	int time;
	int front;
	char path[1000];
};

/*以val为关键字的自定义比较函数*/struct good_cmp
{
	bool operator ()(const goods& a, const goods& b)const
	{
		return a.val > b.val;
	}

};/*以val为关键字的自定义比较函数*/

/*以distance为关键字的自定义比较函数*/struct berth_cmp
{
	bool operator()(const Berth_choose& A, const Berth_choose& B)const
	{
		return A.distance < B.distance;
	};/*以distance为关键字的自定义比较函数*//*以distance为关键字的自定义比较函数*/
};

struct Node_compare
{
	bool operator()(const Node& A, const Node& B)const
	{
		if ((A.x == B.x) && (A.y == B.y))return 0;
		else return A.front < B.front;
	}
};

/*地图判断*/struct road_search
{
	bool ch[210][210] = {};
}map;

int zhen = 1;
int money;/*当前金钱数*/
int boat_capacity;/*船的容积*/
int id;/*编号*/
char ch[N][N];//地图:'.'为陆地,'*'为海洋,'#'为障碍,'A'为机器人起始位置,'B'为泊位位置
set<goods, good_cmp>good;
queue<Robot>robot_queue;
bool robot_judge(int ID, int x, int y, int mx, int my, int time)//BFS，机器人能否到达目的地并记录路径
{
	set<Node,Node_compare>robot_moving;//BFS队列
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
		if (path.ch[a->x][a->y + 1] == 0 && a->y <= 200 && a->time < time)//若地图不为海洋或障碍且标记为0，则标记并入队
		{
			n = *a;
			n.y++;
			n.path[n.time] = '0';
			n.time++;
			n.front = abs(n.x - mx) + abs(n.y - my);
			robot_moving.insert(n);
			path.ch[n.x][n.y] = 1;
		}
		if (path.ch[a->x][a->y - 1] == 0 && a->y > 0 && a->time < time)//若地图不为海洋或障碍且标记为0，则标记并入队
		{
			n = *a;
			n.y--;
			n.path[n.time] = '1';
			n.time++;
			n.front = abs(n.x - mx) + abs(n.y - my);
			robot_moving.insert(n);
			path.ch[n.x][n.y] = 1;
		}
		if (path.ch[a->x + 1][a->y] == 0 && a->x <= 200 && a->time < time)//若地图不为海洋或障碍且标记为0，则标记并入队
		{
			n = *a;
			n.x++;
			n.path[n.time] = '3';
			n.time++;
			n.front = abs(n.x - mx) + abs(n.y - my);
			robot_moving.insert(n);
			path.ch[n.x][n.y] = 1;
		}
		if (path.ch[a->x - 1][a->y] == 0 && a->x > 0 && a->time < time)//若地图不为海洋或障碍且标记为0，则标记并入队
		{
			n = *a;
			n.x--;
			n.path[n.time] = '2';
			n.time++;
			n.front = abs(n.x - mx) + abs(n.y - my);
			robot_moving.insert(n);
			path.ch[n.x][n.y] = 1;
		}
		if (a->x == mx && a->y == my)//若到达目的地,则退出循环并返回1,且向对应的机器人传递路径
		{
			n=*a;
			n.path[n.time] = '\0';
			strcpy(robot[ID].road, n.path);
			robot[ID].time = n.time;
			return 1;
		}
		else //若不为目的地，则出队
		{
			robot_moving.erase(a);
		}
	}
	return 0;//若遍历后未能达到目的地，则返回无法达到
}
int robot_search(int ID)//机器人搜索前往目的地
{
	if (robot[ID].goods == 0)//若机器人未携带货物，则搜索前往货物地点
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
						return 1;//成功
					}
				}
			}
		}
	}
	else//若机器人携带货物，则搜索前往泊位
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
					return 1;//成功
				}
			}
		}
	}
	return 0;//失败
}
int robot_move(int ID)//机器人移动
{
	printf("move %d %c\n", ID, robot[ID].road[strlen(robot[ID].road)-robot[ID].time]);//依据路径移动
	fflush(stdout);
	robot[ID].time--;
	if (robot[ID].time==0)//若已经完成所有路径移动，则取或放货物
	{
		if (robot[ID].goods == 0)//若未携带货物，则取货
		{
			printf("get %d\n", ID);
			fflush(stdout);
		}
		else//若携带货物，则放货
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
/*初始化*/void Init()
{
	for (int i = 1; i <= n; i++)//地图初始化
	{
		scanf("%s", ch[i] + 1);
		for (int j = 1; j <= n; j++)
		{
			if (ch[i][j] == '#' || ch[i][j] == '*')map.ch[i][j] = 1;
			else map.ch[i][j] = 0;
		}
	}
	for (int i = 0; i < berth_num; i++)//泊位初始化
	{
		int id;
		scanf("%d", &id);
		scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
		berth[i].id = id;
	}
	for (int i = 0; i < robot_num; i++)//机器人初始化
	{
		robot[i].ID = i;
	}
	scanf("%d", &boat_capacity);//船容量初始化
	char okk[100];
	scanf("%s", okk);
	printf("OK\n");
	fflush(stdout);
}
/*交互输入*/int Input()
{
	scanf("%d%d", &id, &money);
	int num;//场上新增货物数量
	scanf("%d", &num);
	for (int i = 0; i < num; i++)//接收新增货物并存储相关信息
	{
		goods new_good;
		scanf("%d%d%d", &new_good.x, &new_good.y, &new_good.val);//接受货物的坐标及价值
		new_good.state = 0;//将新增货物的状态标记为未装载
		new_good.time = id + 1000;//记录消失时间
		good.insert(new_good);
	}
	for (int i = 0; i < robot_num; i++)//接收机器人信息
	{
		int sts;//机器人状态，0为恢复，1为正常运行
		scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &sts);//记录机器人状态
		if (robot[i].status == 0)//若空闲则入队
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
	if (!robot_queue.empty())//若处于空闲的机器人不为空，则检索
	{
		Robot a=robot_queue.front();	
		if (!robot_search(a.ID))robot_queue.push(a);//若加入失败，则重新入队
		robot_queue.pop();
	}
	for (int i = 0; i < boat_num; i++)//接收船的信息
	{
		scanf("%d%d", &boat[i].status, &boat[i].pos);
		if (boat[i].status == 1 && boat[i].pos != boat[i].local)//若船正常且目的地与位置不符，则已到达目标泊位
		{
			boat[i].local = boat[i].pos;
			if (boat[i].id != -1)berth[boat[i].id].state = 1;
		}
		if (boat[i].pos == -1 && boat[i].local == -1 && boat[i].status == 1)//船处于虚拟点且无目标泊位，则搜索有货物的泊位
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
/*交互输出*/int Output()
{
	for (int i = 0; i < robot_num; i++)//处理机器人
	{
		if(robot[i].status==1)
		{
			robot_move(i);//机器人移动
		}
	}
	for (int i = 0; i < boat_num; i++)//处理船
	{
		if(boat[i].local!=-1)//若船不在虚拟点
		{
			if (boat[i].num == boat_capacity || berth[boat[i].id].goods_num == 0)//如果载货量满或泊位货物数量为0，则返航
			{
				berth[boat[i].id].boat_id = -1;
				berth[boat[i].id].state = 0;
				boat[i].id = -1;
				printf("go %d\n", i);
				fflush(stdout);
			}
		}
		else if (boat[i].status == 1 && boat[i].id != -1 && boat[i].local == -1)//船正常位于虚拟点且目标泊位不为虚拟点，则前往目标泊位
		{
			printf("ship %d %d\n", i, boat[i].id);
			fflush(stdout);
		}
	}
	for (int i = 0; i < berth_num; i++)//处理泊位装货
	{
		if(berth[i].state==1)//若泊位内有船
		{
			if (berth[i].goods_num > berth[i].loading_speed && boat[berth[i].boat_id].num + berth[i].loading_speed < boat_capacity)
			{//如果泊位货物数量不小于每帧装载数量且船在装载后未到达最大容量
				berth[i].goods_num -= berth[i].loading_speed;
				boat[berth[i].boat_id].num += berth[i].loading_speed;
			}
			else if (berth[i].goods_num <= berth[i].loading_speed)
			{//若泊位货物数量小于每帧装载数量
				boat[berth[i].boat_id].num += berth[i].goods_num;
				berth[i].goods_num = 0;
			}
			else if (boat[berth[i].boat_id].num + berth[i].loading_speed >= boat_capacity)
			{//若船在装载后以达到最大容量
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