#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "student.h"
#include "widget.h"
#include "find.h"
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
void user_output();
void information_input();

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_login_clicked()        //当“登录”按钮被点击时，核对用户名及密码
{
    qInfo()<<"登录被点击";
    QString user;
    QString pwd;
    char*name;
    char*password;
    QByteArray change1;//由QString向char*转换的中间态,中文输入或许出问题
    QByteArray change2;
    int count=0;
    user = ui->account->text();//获取用户名
    change1=user.toUtf8();
    name=change1.data();
    if (strlen(name) <= 10)
    {
        int i;
        for (i = 0; i < strlen(name); i++)
        {
            if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9'));
            else break;
        }
        if (i != strlen(name))
        {
            QMessageBox::warning(this,"","请输入正确格式的账号!");
            ui->account->clear();
            return;
        }
    }
    else
    {
        QMessageBox::warning(this,"","请输入正确格式的账号!");
        ui->account->clear();
        return;
    }
    pwd = ui->password->text();//获取密码
    change2=pwd.toUtf8();
    password=change2.data();
    if (strlen(password) > 10)
    {
        QMessageBox::warning(this,"","请输入正确格式的密码!");
        ui->password->clear();
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
            QMessageBox::warning(this,"","请输入正确格式的密码!");
            ui->password->clear();
            return;
        }
    }
    if((strcmp(name,"")==0)&&(strcmp(password,"")==0))//判断两个输入框是否为空，如果为空则提示用户输入
    {
        QMessageBox::warning(this,"","用户名和密码不能为空！");
    }
    else if(strcmp(name,"")==0)
    {
        QMessageBox::warning(this,"","用户名不可为空！");
    }
    else if(strcmp(password,"")==0)
    {
        QMessageBox::warning(this,"","密码不能为空！");
    }
    else
    {
        bool status = ui->teacher->isChecked();
        bool status_1 = ui->student->isChecked();
        //用于判断用户勾选的身份
        if(status==false&&status_1==false)QMessageBox::warning(this,"","请选择身份！");
        else
        {
            for (User_p = User_head->next; User_p != User_list; User_p = User_p->next)
            {
                qDebug()<<User_p->user.name;
                if (strcmp(name, User_p->user.name) == 0)
                {
                    if (strcmp(password, User_p->user.password) == 0)
                    {
                        if (strcmp(User_p->user.identity, "teacher") == 0 && (status == true)&&(status_1 == false))state = 0;
                        else if (strcmp(User_p->user.identity, "student") == 0 && (status_1 == true)&&(status == false))state = 1;
                        else
                        {
                            QMessageBox::information(this,"","请重新输入正确的账号！");
                            ui->account->clear();
                            break;
                        }
                        QMessageBox::information(this,"","登录成功！");
                        user_output();
                        information_input();
                        if (state == 0)//给予老师权限
                        {
                            this->close();
                            Widget* widget = new Widget;
                            widget->show();
                            count=1;
                            return;
                        }
                        else//给予学生权限
                        {
                            this->close();
                            Student* student = new Student;
                            student->show();
                            count=1;
                            return;
                        }
                    }
                    else
                    {
                        QMessageBox::warning(this,"","账号与密码不匹配！");
                        ui->account->clear();
                        ui->password->clear();
                        qDebug()<<name<<password<<endl;
                        break;
                    }
                }
            }
            if(User_p==User_list&&count==0)
            {
                QMessageBox::warning(this,"","未找到对应账号！");
                ui->account->clear();
                ui->password->clear();
            }
        }
    }
}

void LoginWindow::on_pushButton_clicked()   //当用户点击了“忘记密码”按钮，弹出“找回密码”窗口
{
    Find *find = new Find;
    this -> close();
    find ->show();
}
