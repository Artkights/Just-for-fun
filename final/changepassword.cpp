#include "changepassword.h"
#include "ui_changepassword.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
changePassword::changePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changePassword)
{
    ui->setupUi(this);
}
extern void user_output();

changePassword::~changePassword()
{
    delete ui;
}

void changePassword::on_orig_password_textEdited()  //普通格式输入
{
    ui->orig_password->setEchoMode(QLineEdit::Normal);
}

void changePassword::on_new_password_textEdited()  //密码格式输入
{
    ui->new_password->setEchoMode(QLineEdit::Password);
}

void changePassword::on_confirm_textEdited()  //密码格式输入
{
    ui->confirm->setEchoMode(QLineEdit::Password);
}

void changePassword::on_account_textEdited()  //密码格式输入
{
    ui->account->setEchoMode(QLineEdit::Normal);
}

void changePassword::on_pushButton_clicked()    //当“确认”被点击后，进行查重并改写文件内容
{
    qInfo()<<"登录被点击";
    QString user;
    QString opwd;
    QString newpwd;
    QByteArray change1;
    QByteArray change2;
    QByteArray change3;
    user = ui->account->text();           //获取用户名
    opwd = ui->orig_password->text();     //获取原密码
    newpwd  = ui->new_password->text();   //获取新密码
    char*name;
    char*origin_password;
    char*new_password;
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
            QMessageBox::warning(this,"","请输入正确格式的账号！");
            this->close();
            changePassword *changepwd = new changePassword;
            changepwd ->show();
            return;
        }
    }
    else
    {
        QMessageBox::warning(this,"","请输入正确格式的账号！");
        this->close();
        changePassword *changepwd = new changePassword;
        changepwd ->show();
        return;
    }
    change2=opwd.toLatin1();
    origin_password=change2.data();
    if (strlen(origin_password) > 10)
    {
        QMessageBox::warning(this,"","请输入正确格式的原密码！");
        this->close();
        changePassword *changepwd = new changePassword;
        changepwd ->show();
        return;
    }
    else
    {
        int i;
        for (i = 0; i < strlen(origin_password); i++)
        {
            if ((origin_password[i] >= 'a' && origin_password[i] <= 'z') || (origin_password[i] >= 'A' && origin_password[i] <= 'Z') || (origin_password[i] >= '0' && origin_password[i] <= '9'));
            else break;
        }
        if (i != strlen(origin_password))
        {
            QMessageBox::warning(this,"","请输入正确格式的原密码！");
            this->close();
            changePassword *changepwd = new changePassword;
            changepwd ->show();
            return;
        }
    }
    change3=newpwd.toLatin1();
    new_password=change3.data();
    if (strlen(new_password) > 10)
    {
        QMessageBox::warning(this,"","请输入正确格式的新密码！");
        this->close();
        changePassword *changepwd = new changePassword;
        changepwd ->show();
        return;
    }
    else
    {
        int i;
        for (i = 0; i < strlen(new_password); i++)
        {
            if ((new_password[i] >= 'a' && new_password[i] <= 'z') || (new_password[i] >= 'A' && new_password[i] <= 'Z') || (new_password[i] >= '0' && new_password[i] <= '9'));
            else break;
        }
        if (i != strlen(new_password))
        {
            QMessageBox::warning(this,"","请输入正确格式的新密码！");
            this->close();
            changePassword *changepwd = new changePassword;
            changepwd ->show();
            return;
        }
    }
    if(strcmp(name,"")==0)
        QMessageBox::warning(this,"","用户名不可为空！");
    else if(strcmp(origin_password,"")==0)
        QMessageBox::warning(this,"","原密码不能为空！");
    else if(strcmp(new_password,"")==0)
        QMessageBox::warning(this,"","新密码不能为空！");
    else
    {
       for( User_p = User_head;User_p->next != User_list;User_p=User_p->next)
        {
            if (strcmp(User_p->next->user.name, name) == 0)
            {
                if (strcmp(User_p->next->user.password, origin_password) == 0)
                {
                   strcpy(User_p->next->user.password,new_password);
                   QMessageBox::warning(this,"","修改成功！");
                   this->close();
                   user_output();
                   return;
                }
                else
                {
                    QMessageBox::warning(this,"","账号密码不匹配！");
                }
            }
        }
        QMessageBox::warning(this,"","未找到对应账号！");
    }
}


