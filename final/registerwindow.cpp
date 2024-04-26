#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "loginwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QMainWindow>
#include <QTextStream>
#include <QFile>
#include <QString>
#include "Struct.h"
#include "globe.h"
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
registerWindow::registerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);
}

registerWindow::~registerWindow()
{
    delete ui;
}


void registerWindow::on_register_2_clicked()    //当“注册”按钮被点击后，查重并写入文件
{
    //检查输入的用户名和密码格式是否正确

    qInfo("注册按钮被点击");
    QString name;
    QString password;
    QString new_password;
    QString telephone;
    QByteArray change1;
    QByteArray change2;
    QByteArray change3;
    QByteArray change4;
    char*newpassword;
    name=ui->account->text();
    change1=name.toLatin1();
    User_list->user.name_=change1.data();
    strcpy(User_list->user.name,User_list->user.name_);
    if (strlen(User_list->user.name) <= 10)
    {
        int i;
        for (i = 0; i < strlen(User_list->user.name); i++)
        {
            if ((User_list->user.name[i] >= 'a' && User_list->user.name[i] <= 'z') || (User_list->user.name[i] >= 'A' && User_list->user.name[i] <= 'Z') || (User_list->user.name[i] >= '0' && User_list->user.name[i] <= '9'));
            else break;
        }
        if (i != strlen(User_list->user.name))
        {
            QMessageBox::warning(this,"","请输入正确格式的账号!");
            ui->account->clear();
            return;
        }
        for (User_p = User_head->next; User_p != User_list; User_p = User_p->next)
        {
            if (strcmp(User_p->user.name, User_list->user.name) == 0)
            {
                QMessageBox::warning(this,"","账号重复!");
                ui->account->clear();
                return;
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"","请输入正确长度的账号!");
        ui->account->clear();
        return;
    }
    password=ui->password->text();
    change2=password.toLatin1();
    User_list->user.password_=change2.data();
    strcpy(User_list->user.password,User_list->user.password_);
    if (strlen(User_list->user.password) >= 10)
    {
        QMessageBox::warning(this,"","请输入正确长度的原密码!");
        ui->password->clear();
        return;
    }
    else
    {
        int i;
        for (i = 0; i < strlen(User_list->user.password); i++)
        {
            if ((User_list->user.password[i] >= 'a' && User_list->user.password[i] <= 'z') || (User_list->user.password[i] >= 'A' && User_list->user.password[i] <= 'Z') || (User_list->user.password[i] >= '0' && User_list->user.password[i] <= '9'));
            else break;
        }
        if (i != strlen(User_list->user.password))
        {
            QMessageBox::warning(this,"","请输入正确格式的原密码!");
            ui->password->clear();
            return;
        }
    }
    new_password=ui->confirm->text();
    change3=new_password.toLatin1();
    newpassword=change3.data();
    if (strlen(newpassword) > 10)
    {
        QMessageBox::warning(this,"","请输入正确长度的确认密码!");
        ui->confirm->clear();
        return;
    }
    else
    {
        int i;
        for (i = 0; i < strlen(newpassword); i++)
        {
            if ((newpassword[i] >= 'a' && newpassword[i] <= 'z') || (newpassword[i] >= 'A' && newpassword[i] <= 'Z') || (newpassword[i] >= '0' && newpassword[i] <= '9'));
            else break;
        }
        if (i != strlen(newpassword))
        {
            QMessageBox::warning(this,"","请输入正确格式的确认密码!");
            ui->confirm->clear();
            return;
        }
    }
    telephone=ui->tele->text();
    change4=telephone.toLatin1();
    User_list->user.number_=change4.data();
    strcpy(User_list->user.number,User_list->user.number_);
    if (strlen(User_list->user.number) != 11)
    {
        QMessageBox::warning(this,"","请输入正确格式的手机号码:");
        ui->tele->clear();
        return;
    }
    else
    {
        int i;
        for (i = 0; i < 11; i++)
        {
            if (User_list->user.number[i] >= '0' && User_list->user.number[i] <= '9');
            else break;
        }
        if (i != 11)
        {
            QMessageBox::warning(this,"","请输入正确格式的手机号码！");
            ui->tele->clear();
            return;
        }
    }
    if((strcmp(User_list->user.name,"")==0)&&(strcmp(User_list->user.password,"")==0))
        QMessageBox::warning(this,"","用户名和密码不能为空！");
    else if(strcmp(User_list->user.name,"")==0)
    {
        QMessageBox::warning(this,"","用户名不可为空！");
        qDebug()<<User_list->user.password<<endl;
    }
    else if(strcmp(User_list->user.password,"")==0)
    {
        QMessageBox::warning(this,"","原密码不能为空！");
        qDebug()<<User_list->user.name<<endl;
    }
    else if(strcmp(newpassword,"")==0)
    {
        QMessageBox::warning(this,"","确认密码不能为空！");
        qDebug()<<User_list->user.password<<endl;
    }
    else if(strcmp(User_list->user.password,newpassword)!=0)
    {
        qDebug()<<User_list->user.password_<<endl<<User_list->user.password<<endl;
        QMessageBox::warning(this,"两次输入密码不符！","请重新输入！");
    }
    else
    {
        qDebug()<<"格式正确！";
        QMessageBox::warning(this,"","格式正确！");
        //将用户名和密码写入
        bool status = ui->teachers->isChecked();
        bool status_1 = ui->students->isChecked();
        //判断用户勾选的身份
        //“教师”身份
        if(status == true)
        {
            strcpy(User_list->user.identity,"teacher");
            User_p=(struct User_List*)malloc(sizeof(User_List));
            User_list->next=User_p;
            User_p->prew=User_list;
            User_list=User_p;
            this->close();
            LoginWindow* loginwindow = new LoginWindow;
            loginwindow->show();
        }
        //“学生”身份
        else if(status_1 == true)
        {
            strcpy(User_list->user.identity,"student");
            User_p=(struct User_List*)malloc(sizeof(User_List));
            User_list->next=User_p;
            User_p->prew=User_list;
            User_list=User_p;
            User_list->next=NULL;
            this->close();
            LoginWindow* loginwindow = new LoginWindow;
            loginwindow->show();
        }
        else
            QMessageBox::warning(this,"","请选择身份！");
    }
}

