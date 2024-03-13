#include <iostream>   
#include <vector>  
#include <queue>     
using namespace std;

const int n = 200;
/*����������*/const int robot_num = 10;
/*������*/const int boat_num = 5;
/*��λ����*/const int berth_num = 10;
const int N = 210;

bool robot_judge(int x, int y, int mbx, int mby);
int robot_pull(int ID/*������ID*/);
int robot_get(int ID/*������ID*/);
int boat_ship(int ID/*��ID*/, int pos/*��λID,-1Ϊ�����*/);

/*������*/struct Robot//���ĳ�ʼλ��Ϊ�����
{
    /*�����˺�����*/int x;
    /*������������*/int y;
    /*�Ƿ�Я������*/int goods;//0ΪδЯ����1ΪЯ��
    /*������״̬*/int status;
    /*������Ŀ����������*/int mbx=-1;
    /*������Ŀ�����������*/int mby;
    /*������Ŀ�겴λID*/int id;
}robot[robot_num];

/*��λ*/struct Berth
{
    /*������*/int x;
    /*������*/int y;
    /*����ʱ��*/int transport_time;//�Ӳ�λ���䵽������֡��
    /*װ���ٶ�*/int loading_speed;//ÿ֡װ�صĻ�����
    /*װ�ػ�������*/int goods_num = 0;
    /*��λID*/int ID;//������������Ĳ�λID
    /*��λ���*/int id;//���ڼ�¼��λ���±�
    /*װ���Ĵ������*/int boat_id;
}berth[berth_num];

/*��λѡ��*/struct Berth_choose
{
    Berth berth;
    int distance;
};

/*��*/struct Boat
{
    /*װ�ػ�������*/int num=0;
    /*Ŀ�ĵ�*/int pos;/*Ŀ�겴λID,ǰ���������Ϊ-1*/
    /*����״̬*/int status;//0Ϊ�ƶ��У�1Ϊ�������У�װ����������ɣ�,2Ϊ��λ��ȴ�
    /*ǰ����λ�����*/int id;
}boat[boat_num];

/*����*/struct goods
{
    /*���������*/int x;
    /*����������*/int y;
    /*�����ֵ*/int val;
    /*����״̬*/int state = 0;//0Ϊδװ�أ�1Ϊ�����˰�����,2Ϊ��ѡΪĿ��
};

/*��valΪ�ؼ��ֵ��Զ���ȽϺ���*/bool cmp(goods& a, goods& b)
{
    return a.val > b.val;
};

/*��distanceΪ�ؼ��ֵ��Զ���ȽϺ���*/struct com
{
    bool operator()(Berth_choose& A, Berth_choose& B)
    {
        return A.distance > B.distance;
    }
};

/*����*/vector<goods>a;
/*��ǰ��Ǯ��*/int money;
/*�����ݻ�*/int boat_capacity;
/*���*/int id;
/*��ͼ*/char ch[N][N];//'.'Ϊ½��,'*'Ϊ����,'#'Ϊ�ϰ�,'A'Ϊ��������ʼλ��,'B'Ϊ��λλ��
/*�����������*/int goods_num=0;
/*�����˿�������*/int robot_free = 10;
/*����ѭ������ʵ��*/int i, j;

/*��ʼ��*/void Init()
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
    char okk[100];//OK,��ʾ��ʼ������
    scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);
}

/*�������ж��ܷ񵽴�*/bool robot_judge(int x, int y, int mbx, int mby)//�õݹ����������ܷ񵽴�㷨���ڼ���Ľ��ռ䣩
{
    if (x > mbx && ch[y][x - 1] == '.')return robot_judge(x - 1, y, mbx, mby);
    else if (x < mbx && ch[y][x + 1] == '.')return robot_judge(x + 1, y, mbx, mby);
    else if (y < mby && ch[y + 1][x] == '.')return robot_judge(x, y + 1, mbx, mby);
    else if (y > mby && ch[y - 1][x] == '.')return robot_judge(x, y - 1, mbx, mby);
    else if (x == mbx && y == mby && ch[y][x] == '.')return 1;
    else return 0;
}

/*�������˶�*/int robot_move(int ID/*������ID*/)
{
    /*�������˶�״̬*/int state;//0Ϊ����һ��1Ϊ����һ��2Ϊ����һ��3Ϊ����һ��
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

/*������ȷ������Ŀ��*/int robot_search(int ID)
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

/*������ȷ����λĿ��*/int robot_find(int ID)
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

/*��ȷ����λĿ��*/int boat_search(int ID)//����ID������������ʹ�����д�ǰ����һ���л���ĸۿڣ����Ľ���
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

/*���������ʻ��λ*/int boat_ship(int ID/*��ID*/,int pos/*��λID,-1Ϊ�����*/)
{
    cout << "ship " << ID <<" " << pos << endl;
    return 0;
}

/*������ȡ��*/int robot_get(int ID/*������ID*/)//����������ڻ������ɴ��Ҵ���δЯ������״̬����ȡ���ɹ�
{
    cout << "get " << ID << endl;
    robot[ID].goods = 1;
    return robot_find(ID);
}

/*�����˷Ż�*/int robot_pull(int ID/*������ID*/)//����������ڲ�λ����������Я������״̬������óɹ�
{
    cout << "pull " << ID << endl;
    robot[ID].goods = 0;
    robot[ID].mbx = -1;//���Ϊ����״̬
    berth[robot[ID].id].goods_num++;
    return 0;
}

/*���Ӳ�λʻ���������*/int boat_go(int ID/*��ID*/)
{
    berth[boat[ID].id].boat_id = -1;
    cout << "go " << ID << endl;
    return 0;
}

/*��������*/int Input()
{
    scanf("%d%d", &id, &money);//IDΪ֡���
    /*����������������*/int num;
    scanf("%d", &num);
    /*������Ϊ*/for (i = 1; i <= num; i++)//���ܻ�����Ϣ���Ҵ��浽vector������
    {
        goods good;
        scanf("%d%d%d", &good.x, &good.y, &good.val);
        a.push_back(good);
        goods_num++;
    }
    /*��������Ϊ*/for (i = 0; i < robot_num; i++)
    {
        /*������״̬*/int sts;//0Ϊ�ָ���1Ϊ��������
        scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &sts);
        if (robot[i].mbx == -1)robot_search(i);//��������˿��У���Ի������ɨ�貢ǰ��
        else robot_move(i);//�����������Ŀ����δ����Ŀ�ĵأ����ƶ�
    }
    /*����Ϊ*/for (i = 0; i < 5; i++)//ж�²�λ����װ�����ϣ���������������˻��߻������ڵ���װ�����ޣ���װ���������������Ϊ0Ϊֹ
    {
        scanf("%d%d\n", &boat[i].status, &boat[i].pos);
        if (boat[i].status == 1 && boat[i].pos == -1)boat_search(i);
        else if (boat[i].status == 1 && boat[i].pos != -1 && (berth[boat[i].id].goods_num == 0 || boat[i].num == boat_capacity))boat_go(i);
        else if (boat[i].status == 1 && boat[i].pos != -1)berth[boat[i].id].boat_id = i;
    }
    /*��λװ��*/for (i = 0; i < berth_num; i++)
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
    char okk[100];//OK,��ʾ��������
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
//���ڵ����⣺1.�ж�·���㷨�м���Ľ��ռ� 2.��ȷ����λĿ��ĺ����м���Ľ��ռ�