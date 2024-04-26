#include "backups.h"
#include "ui_backups.h"
#include "registerwindow.h"
#include "student.h"
#include <QLineEdit>
#include "widget.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
BackUps::BackUps(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BackUps)
{
    ui->setupUi(this);
}

BackUps::~BackUps()
{
    delete ui;
}

void BackUps::on_account_textEdited()   //普通格式输入
{
    ui->account->setEchoMode(QLineEdit::Normal);
}

void BackUps::on_password_textEdited()  //密码格式输入
{
    ui->password->setEchoMode(QLineEdit::Password);
}


void BackUps::on_pushButton_clicked()
{
    qInfo()<<"确认被点击";
    QString user;
    QString pwd;
    QByteArray change1;
    QByteArray change2;
    char *name;
    char *password;
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
            BackUps *backups = new BackUps;
            backups ->show();
            return;
        }
    }
    else
    {
        QMessageBox::warning(this,"","请输入正确格式的账号:");
        this->close();
        BackUps *backups = new BackUps;
        backups ->show();
        return;
    }
    pwd = ui->password->text();//获取密码
    change2=user.toLatin1();
    password=change2.data();
    if (strlen(password) > 10)
    {
        QMessageBox::warning(this,"","请输入正确格式的密码:");
        this->close();
        BackUps *backups = new BackUps;
        backups ->show();
        return;
    }
    else
    {
        int i;
        for (i = 0; i < strlen(password); i++)
        {
            if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9'));
            else break;
        }
        if (i != strlen(password))
        {
            QMessageBox::warning(this,"","请输入正确格式的密码:");
            this->close();
            BackUps *backups = new BackUps;
            backups ->show();
            return;
        }
    }
    if((strcmp(name,"")==0)&&(strcmp(password,"")==0))//判断两个输入框是否为空，如果为空则提示用户输入
        QMessageBox::warning(this,"","用户名和密码不能为空！");
    else if(strcmp(name,"")==0)
        QMessageBox::warning(this,"","用户名不可为空！");
    else if(strcmp(password,"")==0)
        QMessageBox::warning(this,"","密码不能为空！");
    //遍历储存“教师”账户和密码的文件，判断是否为老师
    else
    {
        for (User_p = User_head; User_p->next != User_list; User_p = User_p->next)
        {
            if(strcmp(User_p->next->user.identity,"teacher")==0)
            {
                if (strcmp(name, User_p->next->user.name) == 0)
                {
                    if (strcmp(password, User_p->next->user.password) == 0)
                    {
                        FILE* f = fopen(".\\User information.txt", "w");
                        for (User_p = User_head;User_p->next != User_list;User_p = User_p->next)
                        {
                            fprintf(f, "%s %s %s %s\n", User_p->next->user.name, User_p->next->user.password,User_p->next->user.number,User_p->user.identity);
                        }
                        QMessageBox::warning(this,"","备份成功！");
                        fclose(f);
                    }
                }
                else
                {
                    QMessageBox::warning(this,"","账号与密码不匹配！");
                }
            }
        }
        if(User_p==User_list)
        {
            QMessageBox::warning(this,"","未找到对应账号！");
        }
    }
}
