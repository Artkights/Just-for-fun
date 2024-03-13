#include <iostream>   
#include <vector>  
#include <queue>     
using namespace std;

const int n = 200;
/*机器人数量*/const int robot_num = 10;
/*船数量*/const int boat_num = 5;
/*泊位数量*/const int berth_num = 10;
const int N = 210;

bool robot_judge(int x, int y, int mbx, int mby);
int robot_pull(int ID/*机器人ID*/);
int robot_get(int ID/*机器人ID*/);
int boat_ship(int ID/*船ID*/, int pos/*泊位ID,-1为虚拟点*/);

/*机器人*/struct Robot//船的初始位置为虚拟点
{
    /*机器人横坐标*/int x;
    /*机器人纵坐标*/int y;
    /*是否携带货物*/int goods;//0为未携带，1为携带
    /*机器人状态*/int status;
    /*机器人目标货物横坐标*/int mbx=-1;
    /*机器人目标货物纵坐标*/int mby;
    /*机器人目标泊位ID*/int id;
}robot[robot_num];

/*泊位*/struct Berth
{
    /*横坐标*/int x;
    /*纵坐标*/int y;
    /*运输时间*/int transport_time;//从泊位运输到虚拟点的帧数
    /*装载速度*/int loading_speed;//每帧装载的货物数
    /*装载货物数量*/int goods_num = 0;
    /*泊位ID*/int ID;//用于输出给定的泊位ID
    /*泊位序号*/int id;//用于记录泊位的下标
    /*装货的船的序号*/int boat_id;
}berth[berth_num];

/*泊位选择*/struct Berth_choose
{
    Berth berth;
    int distance;
};

/*船*/struct Boat
{
    /*装载货物数量*/int num=0;
    /*目的地*/int pos;/*目标泊位ID,前往虚拟点则为-1*/
    /*船的状态*/int status;//0为移动中，1为正常运行（装货或运输完成）,2为泊位外等待
    /*前往泊位的序号*/int id;
}boat[boat_num];

/*货物*/struct goods
{
    /*货物横坐标*/int x;
    /*货物纵坐标*/int y;
    /*货物价值*/int val;
    /*货物状态*/int state = 0;//0为未装载，1为机器人搬运中,2为被选为目标
};

/*以val为关键字的自定义比较函数*/bool cmp(goods& a, goods& b)
{
    return a.val > b.val;
};

/*以distance为关键字的自定义比较函数*/struct com
{
    bool operator()(Berth_choose& A, Berth_choose& B)
    {
        return A.distance > B.distance;
    }
};

/*货物*/vector<goods>a;
/*当前金钱数*/int money;
/*船的容积*/int boat_capacity;
/*编号*/int id;
/*地图*/char ch[N][N];//'.'为陆地,'*'为海洋,'#'为障碍,'A'为机器人起始位置,'B'为泊位位置
/*货物存在数量*/int goods_num=0;
/*机器人空闲数量*/int robot_free = 10;
/*用于循环，无实意*/int i, j;

/*初始化*/void Init()
{
    for (i = 1; i <= n; i++)
    {
        scanf("%s", ch[i] + 1);
    }
    for (i = 0; i < berth_num; i++)
    {
        int id;
        scanf("%d", &id);
        berth[id].ID = id;
        scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
        berth[id].id = i;
    }
    scanf("%d", &boat_capacity);
    char okk[100];//OK,表示初始化结束
    scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);
}

/*机器人判断能否到达*/bool robot_judge(int x, int y, int mbx, int mby)//用递归计算机器人能否到达（算法存在极大改进空间）
{
    if (x > mbx && ch[y][x - 1] == '.')return robot_judge(x - 1, y, mbx, mby);
    else if (x < mbx && ch[y][x + 1] == '.')return robot_judge(x + 1, y, mbx, mby);
    else if (y < mby && ch[y + 1][x] == '.')return robot_judge(x, y + 1, mbx, mby);
    else if (y > mby && ch[y - 1][x] == '.')return robot_judge(x, y - 1, mbx, mby);
    else if (x == mbx && y == mby && ch[y][x] == '.')return 1;
    else return 0;
}

/*机器人运动*/int robot_move(int ID/*机器人ID*/)
{
    /*机器人运动状态*/int state;//0为右移一格，1为左移一格，2为上移一格，3为下移一格
    if (robot[ID].x > robot[ID].mbx && ch[robot[ID].y][robot[ID].x - 1] == '.')state = 1;
    else if (robot[ID].x < robot[ID].mbx && ch[robot[ID].y][robot[ID].x + 1] == '.')state = 0;
    else if (robot[ID].y < robot[ID].mby && ch[robot[ID].y + 1][robot[ID].x] == '.')state = 2;
    else if (robot[ID].y > robot[ID].mby && ch[robot[ID].y - 1][robot[ID].x] == '.')state = 3;
    else return 0;
    cout << "move " << ID << " " << state;
    switch (state)
    {
    case 0:

        robot[ID].x++;
        break;
    case 1:
        robot[ID].x--;
        break;
    case 2:
        robot[ID].y++;
        break;
    case 3:
        robot[ID].y--;
        break;
    }
    if (robot[ID].x == robot[ID].mbx && robot[ID].y == robot[ID].mby && robot[ID].goods == 0)return robot_get(ID);
    else if (robot[ID].x == robot[ID].mbx && robot[ID].y == robot[ID].mby && robot[ID].goods == 1)return robot_pull(ID);
    else return 0;
}

/*机器人确立货物目标*/int robot_search(int ID)
{
    auto p1 = a.begin();
    auto p2 = a.end();
    sort(p1, p2, cmp);
    for(i=0;i<a.size()&&robot_free>0;i++)
    {
        if (a[i].state == 0&&robot_judge(robot[ID].x,robot[ID].y,a[i].x,a[i].y))
        {
            robot[ID].mbx = a[i].x;
            robot[ID].mby = a[i].y;
            a[i].state = 2;
            return robot_move(ID);
        }
    }
    return 0;
}

/*机器人确立泊位目标*/int robot_find(int ID)
{
    priority_queue<Berth_choose, vector<Berth_choose>, com>a;
    Berth_choose b;
    for (i = 0; i < berth_num; i++)
    {
        b.distance = abs(berth[i].x - robot[ID].x) + abs(berth[i].y - robot[ID].y);
        b.berth = berth[i];
        a.push(b);
    }
    b = a.top();
    while (!robot_judge(robot[ID].x, robot[ID].y, b.berth.x, b.berth.y))
    {
        a.pop();
        b = a.top();
    }
    robot[ID].mbx = b.berth.x;
    robot[ID].mby = b.berth.y;
    robot[ID].id = b.berth.id;
    return 0;
}

/*船确立泊位目标*/int boat_search(int ID)//船的ID（本函数容易使得所有船前往第一个有货物的港口，待改进）
{
    for (j = 0; j < berth_num; j++)
    {
        if (berth[j].goods_num > 0)
        {
            boat_ship(ID, berth[j].ID);
            boat[ID].id = berth[j].id;
            break;
        }
    }
    return 0;
}

/*船从虚拟点驶向泊位*/int boat_ship(int ID/*船ID*/,int pos/*泊位ID,-1为虚拟点*/)
{
    cout << "ship " << ID <<" " << pos << endl;
    return 0;
}

/*机器人取货*/int robot_get(int ID/*机器人ID*/)//如果机器人在货物生成处且处于未携带货物状态，则取货成功
{
    cout << "get " << ID << endl;
    robot[ID].goods = 1;
    return robot_find(ID);
}

/*机器人放货*/int robot_pull(int ID/*机器人ID*/)//如果机器人在泊位处，并处于携带货物状态，则放置成功
{
    cout << "pull " << ID << endl;
    robot[ID].goods = 0;
    robot[ID].mbx = -1;//标记为空闲状态
    berth[robot[ID].id].goods_num++;
    return 0;
}

/*船从泊位驶出至虚拟点*/int boat_go(int ID/*船ID*/)
{
    berth[boat[ID].id].boat_id = -1;
    cout << "go " << ID << endl;
    return 0;
}

/*交互输入*/int Input()
{
    scanf("%d%d", &id, &money);//ID为帧序号
    /*场上新增货物数量*/int num;
    scanf("%d", &num);
    /*货物行为*/for (i = 1; i <= num; i++)//接受货物信息并且储存到vector容器中
    {
        goods good;
        scanf("%d%d%d", &good.x, &good.y, &good.val);
        a.push_back(good);
        goods_num++;
    }
    /*机器人行为*/for (i = 0; i < robot_num; i++)
    {
        /*机器人状态*/int sts;//0为恢复，1为正常运行
        scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &sts);
        if (robot[i].mbx == -1)robot_search(i);//如果机器人空闲，则对货物进行扫描并前往
        else robot_move(i);//如果机器人有目标且未到达目的地，则移动
    }
    /*船行为*/for (i = 0; i < 5; i++)//卸下泊位货物装到船上，如果船的容量超了或者货物少于单次装载上限，则装到船容量满或货物为0为止
    {
        scanf("%d%d\n", &boat[i].status, &boat[i].pos);
        if (boat[i].status == 1 && boat[i].pos == -1)boat_search(i);
        else if (boat[i].status == 1 && boat[i].pos != -1 && (berth[boat[i].id].goods_num == 0 || boat[i].num == boat_capacity))boat_go(i);
        else if (boat[i].status == 1 && boat[i].pos != -1)berth[boat[i].id].boat_id = i;
    }
    /*泊位装货*/for (i = 0; i < berth_num; i++)
    {
        if (berth[i].goods_num >= berth[i].loading_speed && boat[berth[i].boat_id].num + berth[i].loading_speed <= boat_capacity)
        {
            berth[i].goods_num -= berth[i].loading_speed;
            boat[berth[i].boat_id].num += berth[i].loading_speed;
        }
        else if (berth[i].goods_num < berth[i].loading_speed)
        {
            boat[berth[i].boat_id].num -= berth[i].goods_num;
            berth[i].goods_num = 0;
        }
        else if (boat[berth[i].boat_id].num + berth[i].loading_speed > boat_capacity)
        {
            berth[i].goods_num -= (boat_capacity-boat[berth[i].boat_id].num);
            boat[berth[i].boat_id].num = boat_capacity;
        }
    }
    char okk[100];//OK,表示交互结束
    scanf("%s", okk);
    return id;
}

int main()
{
    Init();
    for (int zhen = 1; zhen <= 15000; zhen++)
    {
        int id = Input();
        cout << "OK" << endl;
        fflush(stdout);
    }
    return 0;
}
//存在的问题：1.判断路径算法有极大改进空间 2.船确立泊位目标的函数有极大改进空间