/********************************************************************************
** Form generated from reading UI file 'logout.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOUT_H
#define UI_LOGOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logout
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *mngr_account;
    QLineEdit *mngr_pwd;
    QLineEdit *delet_account;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *logout)
    {
        if (logout->objectName().isEmpty())
            logout->setObjectName(QString::fromUtf8("logout"));
        logout->resize(668, 384);
        centralwidget = new QWidget(logout);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 270, 111, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 20, 131, 51));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\232\266\344\271\246\";"));
        mngr_account = new QLineEdit(centralwidget);
        mngr_account->setObjectName(QString::fromUtf8("mngr_account"));
        mngr_account->setGeometry(QRect(230, 90, 241, 31));
        mngr_pwd = new QLineEdit(centralwidget);
        mngr_pwd->setObjectName(QString::fromUtf8("mngr_pwd"));
        mngr_pwd->setGeometry(QRect(230, 140, 241, 31));
        mngr_pwd->setEchoMode(QLineEdit::Password);
        delet_account = new QLineEdit(centralwidget);
        delet_account->setObjectName(QString::fromUtf8("delet_account"));
        delet_account->setGeometry(QRect(230, 190, 241, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 100, 101, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 150, 101, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 190, 101, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        logout->setCentralWidget(centralwidget);
        menubar = new QMenuBar(logout);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 668, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        logout->setMenuBar(menubar);
        statusbar = new QStatusBar(logout);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        logout->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(logout);

        QMetaObject::connectSlotsByName(logout);
    } // setupUi

    void retranslateUi(QMainWindow *logout)
    {
        logout->setWindowTitle(QCoreApplication::translate("logout", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("logout", "\347\241\256\350\256\244\346\263\250\351\224\200", nullptr));
        label->setText(QCoreApplication::translate("logout", "\350\264\246\345\217\267\346\263\250\351\224\200", nullptr));
        label_2->setText(QCoreApplication::translate("logout", "\347\256\241\347\220\206\345\221\230\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("logout", "\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("logout", "\351\234\200\346\263\250\351\224\200\350\264\246\345\217\267", nullptr));
        menu->setTitle(QCoreApplication::translate("logout", "\346\263\250\346\204\217\357\274\232\346\255\244\345\212\237\350\203\275\344\273\205\346\225\231\345\270\210\345\217\257\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class logout: public Ui_logout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOUT_H
