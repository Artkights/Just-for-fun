#include "student.h"
#include "ui_student.h"
#include <QDebug>
#include <QFile>
#include <QTableWidget>
#include <QHeaderView>
#include <QAbstractItemModel>
#include <QTextStream>
#include <QList>
#include <QComboBox>
#include "Struct.h"
#include "globe.h"
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
Student::Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
    readDataFromFile(".\\Student.txt");
}

Student::~Student()
{
    delete ui;
}

void Student::readDataFromFile(const QString &filename)   //保存数据到文件中的函数
{
    //打开文件
    QFile file(".\\Student.txt");

    //判断是否打开成功
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo()<<filename<<"open failed";
    }
    else //从文件读取数据
    {
        qInfo()<<filename<<"open successful";

        QTextStream output(&file);
        output.setCodec("UTF-8");
        QHash<QString, QString> varHash;
        QString linestr;
        QStringList linelist;
        varHash.clear();
        linelist.clear();

        ui ->tablewidget ->setColumnCount(6);
        //建立表头
        QStringList headers = output.readLine().split('\t');
        ui ->tablewidget ->setHorizontalHeaderLabels(headers);
        //拉伸模式
        ui ->tablewidget ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        while(!output.atEnd())
        {
            linestr = output.readLine();
            linelist = linestr.split('\t');
            int rowcount = ui->tablewidget->rowCount();
            ui->tablewidget->insertRow(rowcount);
            for(int i = 0; i < 6; i++)
            {
                ui->tablewidget->setItem(rowcount,i,new QTableWidgetItem(linelist[i]));
            }
        }
        file.close();
    }
}


void Student::on_pushButton_2_clicked()   //搜索模块，模糊及精准查找
{
    int row = ui->tablewidget->rowCount();
    for(int i=0;i<row;i++)            //隐藏所有行
    {
        ui->tablewidget->setRowHidden(i,true);
    }

    QString name1;
    QByteArray change1;
    char *name;
    name1 = ui->search->text();
    qDebug()<<name1;
    change1=name1.toLatin1();
    name=change1.data();
    int row_num = ui->tablewidget->rowCount();
    if(strcmp(name,"")==0)
    {
        for(int i=0;i<row_num;i++)
        {
            ui->tablewidget->setRowHidden(i,false);
        }
    }
    else
    {
        FILE *f=fopen(".\\Student.txt","r");
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
                  ui->tablewidget->setRowHidden(num,false);
                  break;
                }
            }
            num++;
        }
    }
    QString str=ui->comboBox_2->currentText();
    QByteArray change=str.toUtf8();
    char *Class=change.data();
    qDebug()<<Class;
    if(strcmp(Class,"全校")==0);
    else
    {
        int num=-1;
        for(p=head;p->next!=list;p=p->next,num++)
        {
            if(strcmp(p->next->C_student.Class,Class)!=0)
            {
                ui->tablewidget->setRowHidden(num,true);
            }
        }
    }
}


void Student::on_comboBox_activated()  //当组合框被激活，即被用户选择时，显示学生相应学科一列的信息，隐藏未被选择的其他列信息
{
    QString str = ui->comboBox->currentText();

    if(str == "全科")
    {
        ui->tablewidget->setColumnHidden(3,false);
        ui->tablewidget->setColumnHidden(4,false);
        ui->tablewidget->setColumnHidden(5,false);
    }
    else if(str == "语文")
    {
        ui->tablewidget->setColumnHidden(3,false);
        ui->tablewidget->setColumnHidden(4,true);
        ui->tablewidget->setColumnHidden(5,true);
    }
    else if(str == "数学")
    {
        ui->tablewidget->setColumnHidden(3,true);
        ui->tablewidget->setColumnHidden(4,false);
        ui->tablewidget->setColumnHidden(5,true);
    }
    else if(str == "英语")
    {
        ui->tablewidget->setColumnHidden(3,true);
        ui->tablewidget->setColumnHidden(4,true);
        ui->tablewidget->setColumnHidden(5,false);
    }
}

void Student::on_comboBox_2_activated()
{
    QString name1;
    QByteArray change1;
    char *name;
    name1 = ui->search->text();
    qDebug()<<name1;
    change1=name1.toLatin1();
    name=change1.data();
    int row_num = ui->tablewidget->rowCount();
    if(strcmp(name,"")==0)
    {
        for(int i=0;i<row_num;i++)
        {
            ui->tablewidget->setRowHidden(i,false);
        }
    }
    else
    {
        FILE *f=fopen(".\\Student.txt","r");
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
                  ui->tablewidget->setRowHidden(num,false);
                  break;
                }
            }
            num++;
        }
        fclose(f);
    }
    QString str=ui->comboBox_2->currentText();
    QByteArray change=str.toUtf8();
    char *Class=change.data();
    qDebug()<<Class;
    if(strcmp(Class,"全校")==0);
    else
    {
        int num=-1;
        for(p=head;p->next!=list;p=p->next,num++)
        {
            if(strcmp(p->next->C_student.Class,Class)!=0)
            {
                ui->tablewidget->setRowHidden(num,true);
            }
        }
    }
}


void Student::on_comboBox_activated(const QString &arg1)
{

}
