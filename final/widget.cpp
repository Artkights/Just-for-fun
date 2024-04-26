#include "student.h"
#include <QDebug>
#include <QFile>
#include <QTableWidget>
#include <QHeaderView>
#include <QAbstractItemModel>
#include <QTextStream>
#include <QList>
#include <QComboBox>

#include "ui_widget.h"
#include "widget.h"
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
extern void information_input();
Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    readDataFromFile(".\\Student.txt");//当ui界面弹出时已经开始执行从文件中读取数据的函数了
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readDataFromFile(const QString &filename)//从文件中读取学生的学号、班级、成绩等数据，并传到ui界面的表格tableView_2中显示
{
    //打开文件
    QFile file(filename);
    //判断是否打开成功
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo()<<filename<<"open failed";
    }
    else
    {
        qInfo()<<filename<<"open successful";
    }
    //读取文件
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    model = new QStandardItemModel(this);
    ui->tableView_2->setModel(model);

    //1.读取表头
    QStringList headers = stream.readLine().split('\t');
    model->setHorizontalHeaderLabels(headers);

    //2.数据
    while(!stream.atEnd())
    {
        QStringList lineData = stream.readLine().split('\t');
        //生成item
        QList<QStandardItem*> items;
        for(QString data : lineData)
        {
            items.push_back(new QStandardItem(data));
        }
        model->appendRow(items);
    }
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Widget::saveDataToFile(const QString &filename)//保存数据到文件中的函数
{
    //打开文件
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qInfo()<<"saveDataToFile open file failed";
    }
    //写入文件
    QTextStream stream(&file);
    //保存表头
    QString headers;
    int column = model->columnCount();
    for(int i =0; i<column;i++)
    {
        headers.push_back(model->horizontalHeaderItem(i)->text());
        if(i!=column-1)
            headers.push_back('\t');
    }
    stream<<headers<<"\n";

    //保存数据
    for(int r = 0;r<model->rowCount();r++)
    {
        QString lineData;
        for(int i =0;i<column;i++)
        {
            if(!model->item(r,i))
            {
                goto end;
            }
            lineData.push_back(model->item(r,i)->text());
            if(i!= column-1)
                lineData.push_back('\t');
        }
        stream<<lineData<<"\n";
    }
    end:;
}

void Widget::on_add_info_clicked()  //“添加学生”按钮点击后，自动滑至最底一行，可直接在页面中进行输入
{
    qInfo()<<"添加学生被点击";

    for(int i=0;i<model->rowCount();i++)            //显示所有行
        ui->tableView_2->setRowHidden(i,false);
    for(int j=0;j<model->columnCount();j++)        //显示所有列
        ui->tableView_2->setRowHidden(j,false);
    //表格添加一行
    model->setRowCount(model->rowCount()+1);
    //自动滚动至最后一行
    ui->tableView_2->scrollToBottom();
}

void Widget::on_save_data_clicked()     //当“保存数据”按钮被点击，执行相应函数，将新数据保存至文件
{
    qInfo()<<"保存数据被点击";
    saveDataToFile(".\\Student.txt");
}

void Widget::on_delete_info_clicked()
{
    qInfo()<<"删除学生被点击";
    //获取当前选中的学生
    QModelIndex index = ui->tableView_2->currentIndex();
    //按照学号删除该学生
    model->removeRow(index.row());
}

void Widget::on_pushButton_clicked()    //搜索模块
{
    readDataFromFile(".\\student_sort.txt");
    QString name1;
    QByteArray change1;
    char *name;
    name1 = ui->lineEdit->text();
    qDebug()<<name1;
    change1=name1.toUtf8();
    name=change1.data();
    int row = model->rowCount();
    for(int i=0;i<row;i++)            //隐藏所有行
        ui->tableView_2->setRowHidden(i,true);
    if(strcmp(name,"")==0)
    {
        for(int i=0;i<row;i++)
        {
            ui->tableView_2->setRowHidden(i,false);
        }
    }
    else
    {
        FILE *f=fopen(".\\student_sort.txt","r");
        char find[100];
        int i;
        int num=0;
        fgets(find,100,f);
        while(fgets(find,100,f))
        {
            int j = strlen(name);
            char search[100];
            search[j] = '\0';
            for (int k = 0; k + j <= strlen(find); k++)
            {
                for (i = 0; i < j; i++)
                {
                    search[i] = find[i + k];
                }
                search[i] = '\0';
                if (strcmp(search, name) == 0)
                {
                  ui->tableView_2->setRowHidden(num,false);
                  break;
                }
            }
            num++;
        }
        fclose(f);
    }
    QString str=ui->comboBox->currentText();
    QByteArray change=str.toUtf8();
    char *Class=change.data();
    qDebug()<<Class;
    if(strcmp(Class,"全校")==0);
    else
    {
        int num=0;
        for(p=head;p->next!=list;p=p->next,num++)
        {
            if(strcmp(p->next->C_student.Class,Class)!=0)
            {
                ui->tableView_2->setRowHidden(num,true);
            }
        }
    }
}

void Widget::on_comboBox_activated()//当组合框被激活，即被用户选择时，显示相应班级的学生信息，隐藏未被选择的学生信息
{
    QString name1;
    QByteArray change1;
    char *name;
    name1 = ui->lineEdit->text();
    qDebug()<<name1;
    change1=name1.toUtf8();
    name=change1.data();
    int row = model->rowCount();
    for(int i=0;i<row;i++)            //隐藏所有行
        ui->tableView_2->setRowHidden(i,true);
    if(strcmp(name,"")==0)
    {
        for(int i=0;i<row;i++)
        {
            ui->tableView_2->setRowHidden(i,false);
        }
    }
    else
    {
        FILE *f=fopen(".\\student_sort.txt","r");
        char find[100];
        int i;
        int num=0;
        fgets(find,100,f);
        while(fgets(find,100,f))
        {
            int j = strlen(name);
            char search[100];
            search[j] = '\0';
            for (int k = 0; k + j <= strlen(find); k++)
            {
                for (i = 0; i < j; i++)
                {
                    search[i] = find[i + k];
                }
                search[i] = '\0';
                if (strcmp(search, name) == 0)
                {
                  ui->tableView_2->setRowHidden(num,false);
                  break;
                }
            }
            fclose(f);
            num++;
        }
    }
    QString str=ui->comboBox->currentText();
    QByteArray change=str.toUtf8();
    char *Class=change.data();
    qDebug()<<Class;
    if(strcmp(Class,"全校")==0);
    else
    {
        int num=0;
        for(p=head;p->next!=list;p=p->next,num++)
        {
            if(strcmp(p->next->C_student.Class,Class)!=0)
            {
                ui->tableView_2->setRowHidden(num,true);
            }
        }
    }
}

void Widget::on_comboBox_2_activated()//当组合框被激活，即被用户选择时，显示学生相应学科一列的信息，隐藏未被选择的其他列信息
{
    QString str = ui->comboBox_2->currentText();
    QByteArray change=str.toUtf8();
    char* string=change.data();
    if(strcmp(string,"全科")==0)
    {
        ui->tableView_2->setColumnHidden(3,false);
        ui->tableView_2->setColumnHidden(4,false);
        ui->tableView_2->setColumnHidden(5,false);
    }
    else if(strcmp(string,"语文")==0)
    {
        ui->tableView_2->setColumnHidden(3,false);
        ui->tableView_2->setColumnHidden(4,true);
        ui->tableView_2->setColumnHidden(5,true);
    }
    else if(strcmp(string,"数学")==0)
    {
        ui->tableView_2->setColumnHidden(3,true);
        ui->tableView_2->setColumnHidden(4,false);
        ui->tableView_2->setColumnHidden(5,true);
    }
    else if(strcmp(string,"英语")==0)
    {
        ui->tableView_2->setColumnHidden(3,true);
        ui->tableView_2->setColumnHidden(4,true);
        ui->tableView_2->setColumnHidden(5,false);
    }
}

void Widget::on_comboBox_3_activated()
{
    qDebug()<<"cb3";
    QString str=ui->comboBox_3->currentText();
    QByteArray change=str.toUtf8();
    char*string=change.data();

    if(strcmp(string,"默认")==0);
    else
    {
        struct Sort *sort_head,*sort_list,*sort_p;
        sort_head=(struct Sort*)malloc(sizeof(struct Sort));
        sort_list=(struct Sort*)malloc(sizeof(struct Sort));
        bool *array=(bool *)calloc(num,sizeof(bool));//num为学生数量
        memset(array,0,num*sizeof(bool));
        char *Class;
        memset(Class,0,sizeof(char));
        sort_head->next=sort_list;
        qDebug()<<"链表搭建1";

        if(strcmp(string,"按学号顺序")==0);
        else if(strcmp(string,"按班级顺序")==0)
        {
            qDebug()<<"进入班级顺序";
            for(int i=0;i<num;i++)
            {
                qDebug()<<i;
                int max=0,number=0;
                for(p=head;p->next!=list;p=p->next,number++)//野指针可能地点
                {
                    if(strcmp(Class,p->next->C_student.Class)<0&&array[number]==0)//班级小且未标记
                    {
                        strcpy(Class,p->next->C_student.Class);
                        max=number;
                    }
                }
                for(p=head,number=0;number<max;p=p->next,number++);
                sort_list->p=p->next->C_student;
                qDebug()<<max;
                qDebug()<<p->next->C_student.num<<p->next->C_student.name<<p->next->C_student.Class<<p->next->C_student.course[0]<<p->next->C_student.course[1]<<p->next->C_student.course[2];
                qDebug()<<sort_list->p.num<<sort_list->p.name<<sort_list->p.Class<<sort_list->p.course[0]<<sort_list->p.course[1]<<sort_list->p.course[2];
                sort_p=(struct Sort*)malloc(sizeof(struct Sort));
                sort_list->next=sort_p;
                sort_list=sort_p;
                array[max]=1;
                memset(Class,0,sizeof(char));
            }
            qDebug()<<"打开文件3";
            FILE *f=fopen(".\\student_sort.txt","w");
            qDebug()<<"成功写入4";
            fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",head->C_student.num,head->C_student.name,head->C_student.Class,head->C_student.course[0],head->C_student.course[1],head->C_student.course[2]);
            for(sort_p=sort_head;sort_p->next!=sort_list;sort_p=sort_p->next)
            {
                qDebug()<<"正在输出5";
                fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",sort_p->next->p.num,sort_p->next->p.name,sort_p->next->p.Class,sort_p->next->p.course[0],sort_p->next->p.course[1],sort_p->next->p.course[2]);
            }
            fclose(f);
            qDebug()<<"完成6";
            readDataFromFile(".\\student_sort.txt");
        }
        else if(strcmp(string,"按语文成绩")==0)
        {
            qDebug()<<"进入语文成绩顺序";
            for(int i=0;i<num;i++)
            {
                qDebug()<<i;
                int max=0,number=0;
                for(p=head;p->next!=list;p=p->next,number++)//野指针可能地点
                {
                    if(strcmp(Class,p->next->C_student.course[0])<0&&array[number]==0)//班级小且未标记
                    {
                        strcpy(Class,p->next->C_student.course[0]);
                        max=number;
                    }
                }
                for(p=head,number=0;number<max;p=p->next,number++);
                sort_list->p=p->next->C_student;
                qDebug()<<max;
                qDebug()<<p->next->C_student.num<<p->next->C_student.name<<p->next->C_student.Class<<p->next->C_student.course[0]<<p->next->C_student.course[1]<<p->next->C_student.course[2];
                qDebug()<<sort_list->p.num<<sort_list->p.name<<sort_list->p.Class<<sort_list->p.course[0]<<sort_list->p.course[1]<<sort_list->p.course[2];
                sort_p=(struct Sort*)malloc(sizeof(struct Sort));
                sort_list->next=sort_p;
                sort_list=sort_p;
                array[max]=1;
                memset(Class,0,sizeof(char));
            }
            qDebug()<<"打开文件3";
            FILE *f=fopen(".\\student_sort.txt","w");
            qDebug()<<"成功写入4";
            fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",head->C_student.num,head->C_student.name,head->C_student.Class,head->C_student.course[0],head->C_student.course[1],head->C_student.course[2]);
            for(sort_p=sort_head;sort_p->next!=sort_list;sort_p=sort_p->next)
            {
                qDebug()<<"正在输出5";
                fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",sort_p->next->p.num,sort_p->next->p.name,sort_p->next->p.Class,sort_p->next->p.course[0],sort_p->next->p.course[1],sort_p->next->p.course[2]);
            }
            fclose(f);
            qDebug()<<"完成6";
            readDataFromFile(".\\student_sort.txt");
        }
        else if(strcmp(string,"按数学成绩")==0)
        {
            qDebug()<<"进入语文成绩顺序";
            for(int i=0;i<num;i++)
            {
                qDebug()<<i;
                int max=0,number=0;
                for(p=head;p->next!=list;p=p->next,number++)//野指针可能地点
                {
                    if(strcmp(Class,p->next->C_student.course[1])<0&&array[number]==0)//班级小且未标记
                    {
                        strcpy(Class,p->next->C_student.course[1]);
                        max=number;
                    }
                }
                for(p=head,number=0;number<max;p=p->next,number++);
                sort_list->p=p->next->C_student;
                qDebug()<<max;
                qDebug()<<p->next->C_student.num<<p->next->C_student.name<<p->next->C_student.Class<<p->next->C_student.course[0]<<p->next->C_student.course[1]<<p->next->C_student.course[2];
                qDebug()<<sort_list->p.num<<sort_list->p.name<<sort_list->p.Class<<sort_list->p.course[0]<<sort_list->p.course[1]<<sort_list->p.course[2];
                sort_p=(struct Sort*)malloc(sizeof(struct Sort));
                sort_list->next=sort_p;
                sort_list=sort_p;
                array[max]=1;
                memset(Class,0,sizeof(char));
            }
            qDebug()<<"打开文件3";
            FILE *f=fopen(".\\student_sort.txt","w");
            qDebug()<<"成功写入4";
            fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",head->C_student.num,head->C_student.name,head->C_student.Class,head->C_student.course[0],head->C_student.course[1],head->C_student.course[2]);
            for(sort_p=sort_head;sort_p->next!=sort_list;sort_p=sort_p->next)
            {
                qDebug()<<"正在输出5";
                fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",sort_p->next->p.num,sort_p->next->p.name,sort_p->next->p.Class,sort_p->next->p.course[0],sort_p->next->p.course[1],sort_p->next->p.course[2]);
            }
            fclose(f);
            qDebug()<<"完成6";
            readDataFromFile(".\\student_sort.txt");
        }
        else if(strcmp(string,"按英语成绩")==0)
        {
            qDebug()<<"进入英语成绩顺序";
            for(int i=0;i<num;i++)
            {
                qDebug()<<i;
                int max=0,number=0;
                for(p=head;p->next!=list;p=p->next,number++)//野指针可能地点
                {
                    if(strcmp(Class,p->next->C_student.course[2])<0&&array[number]==0)//班级小且未标记
                    {
                        strcpy(Class,p->next->C_student.course[2]);
                        max=number;
                    }
                }
                for(p=head,number=0;number<max;p=p->next,number++);
                sort_list->p=p->next->C_student;
                qDebug()<<max;
                qDebug()<<p->next->C_student.num<<p->next->C_student.name<<p->next->C_student.Class<<p->next->C_student.course[0]<<p->next->C_student.course[1]<<p->next->C_student.course[2];
                qDebug()<<sort_list->p.num<<sort_list->p.name<<sort_list->p.Class<<sort_list->p.course[0]<<sort_list->p.course[1]<<sort_list->p.course[2];
                sort_p=(struct Sort*)malloc(sizeof(struct Sort));
                sort_list->next=sort_p;
                sort_list=sort_p;
                array[max]=1;
                memset(Class,0,sizeof(char));
            }
            qDebug()<<"打开文件3";
            FILE *f=fopen(".\\student_sort.txt","w");
            qDebug()<<"成功写入4";
            fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",head->C_student.num,head->C_student.name,head->C_student.Class,head->C_student.course[0],head->C_student.course[1],head->C_student.course[2]);
            for(sort_p=sort_head;sort_p->next!=sort_list;sort_p=sort_p->next)
            {
                qDebug()<<"正在输出5";
                fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",sort_p->next->p.num,sort_p->next->p.name,sort_p->next->p.Class,sort_p->next->p.course[0],sort_p->next->p.course[1],sort_p->next->p.course[2]);
            }
            fclose(f);
            qDebug()<<"完成6";
            readDataFromFile(".\\student_sort.txt");
        }
    }
    head=(struct List*)malloc(sizeof(List));
    list=(struct List*)malloc(sizeof(List));
    p=(struct List*)malloc(sizeof(List));
    information_input();
}
