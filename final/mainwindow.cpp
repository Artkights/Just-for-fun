#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "registerwindow.h"
#include "changepassword.h"
#include "backups.h"
#include "logout.h"
#include <QDebug>
extern "C"
{
    #include"Struct.h"
    #include "globe.h"
}
mainWindow::mainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_LoginBotton_clicked()   //一些点击按钮后子窗口弹出的函数
{
    qInfo()<< "登录账号被点击";
    LoginWindow *loginwindow = new LoginWindow;

    loginwindow ->show();
}

void mainWindow::on_changePsw_clicked()
{
    qInfo()<< "修改密码被点击";
    changePassword *changepwd = new changePassword;

    changepwd ->show();
}

void mainWindow::on_registerBotton_clicked()
{
    qInfo()<<"注册账号被点击";
    registerWindow *registerwindow = new registerWindow;

    registerwindow ->show();
}

void mainWindow::on_backups_clicked()
{
    qInfo()<<"用户备份被点击";
    BackUps *backups = new BackUps;

    backups ->show();
}

void mainWindow::on_deleteBotton_clicked()
{
    qInfo()<<"用户注销被点击";
    logout *Logout = new logout;

    Logout ->show();
}
