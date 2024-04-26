#include "logout.h"
#include "ui_logout.h"
#include <QLineEdit>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
logout::logout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logout)
{
    ui->setupUi(this);
}

logout::~logout()
{
    delete ui;
}

void logout::on_pushButton_clicked()  //“确认注销”被点击后，进行管理员（教师）的身份信息核对，并将输入的要删除的学生的信息从stu_info.txt中删除
{
    qInfo()<<"确认注销被点击";
    QString user;
    QString pwd;
    QString del;
    QByteArray change1;
    QByteArray change2;
    QByteArray change3;
    char *name;
    char *password;
    user = ui->mngr_account->text();//获取用户名
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
            logout *Logout = new logout;
            Logout ->show();
            return;
        }
    }
    else
    {
        QMessageBox::warning(this,"","请输入正确格式的账号:");
        this->close();
        logout *Logout = new logout;
        Logout ->show();
        return;
    }
    pwd = ui->mngr_pwd->text();//获取密码
    change2=pwd.toLatin1();
    password=change2.data();
    if (strlen(password) > 10)
    {
        QMessageBox::warning(this,"","请输入正确格式的密码:");
        this->close();
        logout *Logout = new logout;
        Logout ->show();
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
            logout *Logout = new logout;
            Logout ->show();
            return;
        }
    }
    if((strcmp(name,"")==0)&&(strcmp(password,"")==0))//判断两个输入框是否为空，如果为空则提示用户输入
        QMessageBox::warning(this,"","用户名和密码不能为空！");
    else if(strcmp(name,"")==0)
        QMessageBox::warning(this,"","用户名不可为空！");
    else if(strcmp(password,"")==0)
        QMessageBox::warning(this,"","密码不能为空！");
    else
    {
        for (User_p = User_head; User_p->next != User_list; User_p = User_p->next)
        {
            if (strcmp(User_p->next->user.name, name) == 0)
            {
                if (strcmp(User_p->next->user.password, password) == 0)
                {
                    User_p->next->prew->next = User_p->next->next;
                    User_p->next->next->prew = User_p->next->prew;
                    free(User_p);
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
