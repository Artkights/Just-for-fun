#include "find.h"
#include "ui_find.h"
#include "loginwindow.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
Find::Find(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);
}

Find::~Find()
{
    delete ui;
}


void Find::on_pushButton_clicked()  //当确认被点击后，核对是否有相应的用户名及手机号码，进行文件中密码的改写
{
    qInfo()<<"确认被点击";
    QString user;
    QString tel;
    QString newpwd;
    QByteArray change1;
    QByteArray change2;
    QByteArray change3;
    char*name;
    char*telephone;
    char*newpassword;
    user = ui->account->text();//获取用户名
    change1=user.toLatin1();
    name=change1.data();
    if (strlen(name) <= 10)
    {
        int i;
        for (i = 0; i < strlen(User_list->user.name); i++)
        {
            if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9'));
            else break;
        }
        if (i != strlen(User_list->user.name))
        {
            QMessageBox::warning(this,"","请输入正确格式的账号:");
            this->close();
            Find *find = new Find;
            find ->show();
            return;
        }
    }
    else
    {
        QMessageBox::warning(this,"","请输入正确格式的账号:");
        this->close();
        Find *find = new Find;
        find ->show();
        return;
    }
    tel = ui->tele->text();//获取注册使用的电话号码
    change2=tel.toLatin1();
    telephone=change2.data();
    if (strlen(telephone) != 11)
    {
        QMessageBox::warning(this,"","请输入正确格式的手机号码:");
        this->close();
        Find *find = new Find;
        find ->show();
        return;
    }
    else
    {
        int i;
        for (i = 0; i < 11; i++)
        {
            if (telephone[i] >= '0' && telephone[i] <= '9');
            else break;
        }
        if (i != 11)
        {
            QMessageBox::warning(this,"","请输入正确格式的手机号码:");
            this->close();
            Find *find = new Find;
            find ->show();
            return;
        }
    }
    newpwd = ui->new_pwd->text();        //获取新密码
    change3=newpwd.toLatin1();
    newpassword=change3.data();
    if (strlen(newpassword) > 10)
    {
        QMessageBox::warning(this,"","请输入正确格式的新密码:");
        this->close();
        Find *find = new Find;
        find ->show();
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
            QMessageBox::warning(this,"","请输入正确格式的新密码:");
            this->close();
            Find *find = new Find;
            find ->show();
            return;
        }
    }
    if(strcmp(name,"")==0)
        QMessageBox::warning(this,"","用户名不可为空！");
    else if(strcmp(telephone,"")==0)
        QMessageBox::warning(this,"","电话号码不能为空！");
    else if(strcmp(newpassword,"")==0)
        QMessageBox::warning(this,"","新密码不能为空！");
    else
    {
        for( User_p = User_head;User_p->next != User_list;User_p=User_p->next)
         {
             if (strcmp(User_p->next->user.name, name) == 0)
             {
                 if (strcmp(User_p->next->user.number, telephone) == 0)
                 {
                    strcpy(User_p->next->user.password,newpassword);
                    QMessageBox::warning(this,"","修改成功！");
                    this->close();
                 }
                 else
                 {
                     printf("账号与手机账号不匹配");
                 }
             }
         }
         QMessageBox::warning(this,"","未找到对应账号！");
    }
}
