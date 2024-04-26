/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLineEdit *account;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *login;
    QWidget *widget;
    QCheckBox *teacher;
    QCheckBox *student;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(594, 402);
        LoginWindow->setMinimumSize(QSize(594, 402));
        LoginWindow->setMaximumSize(QSize(594, 402));
        LoginWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/QQ\345\233\276\347\211\20720240331094419.jpg);"));
        account = new QLineEdit(LoginWindow);
        account->setObjectName(QString::fromUtf8("account"));
        account->setGeometry(QRect(190, 140, 221, 31));
        account->setStyleSheet(QString::fromUtf8("background-image: url(:/images/OIP-C.jpg);"));
        password = new QLineEdit(LoginWindow);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(190, 190, 221, 31));
        password->setStyleSheet(QString::fromUtf8("background-image: url(:/images/OIP-C.jpg);"));
        password->setEchoMode(QLineEdit::Password);
        label = new QLabel(LoginWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 140, 41, 31));
        label->setAcceptDrops(false);
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 190, 41, 31));
        label_2->setAcceptDrops(false);
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 50, 161, 51));
        label_3->setMinimumSize(QSize(161, 0));
        label_3->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\232\266\344\271\246\";"));
        login = new QPushButton(LoginWindow);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(230, 310, 141, 51));
        login->setCursor(QCursor(Qt::PointingHandCursor));
        login->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        widget = new QWidget(LoginWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(200, 240, 191, 41));
        teacher = new QCheckBox(widget);
        teacher->setObjectName(QString::fromUtf8("teacher"));
        teacher->setGeometry(QRect(30, 10, 71, 19));
        teacher->setCursor(QCursor(Qt::PointingHandCursor));
        teacher->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        teacher->setAutoExclusive(true);
        student = new QCheckBox(widget);
        student->setObjectName(QString::fromUtf8("student"));
        student->setGeometry(QRect(110, 10, 71, 19));
        student->setCursor(QCursor(Qt::PointingHandCursor));
        student->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        student->setAutoExclusive(true);
        pushButton = new QPushButton(LoginWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(490, 360, 91, 31));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 9pt \"\347\255\211\347\272\277\";"));
        label_4 = new QLabel(LoginWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(420, 139, 161, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 7pt \"\351\273\221\344\275\223\";"));
        label_5 = new QLabel(LoginWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(420, 190, 161, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 7pt \"\351\273\221\344\275\223\";"));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "\346\254\242\350\277\216\347\231\273\345\275\225", nullptr));
        login->setText(QCoreApplication::translate("LoginWindow", "\347\231\273  \345\275\225", nullptr));
        teacher->setText(QCoreApplication::translate("LoginWindow", "\346\225\231\345\270\210", nullptr));
        student->setText(QCoreApplication::translate("LoginWindow", "\345\255\246\347\224\237", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "\345\277\230\350\256\260\345\257\206\347\240\201\357\274\237", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "\350\257\267\350\276\223\345\205\24510\344\275\215\344\273\245\345\206\205\347\232\204\350\213\261\346\226\207\346\210\226\346\225\260\345\255\227", nullptr));
        label_5->setText(QCoreApplication::translate("LoginWindow", "\350\257\267\350\276\223\345\205\24510\344\275\215\344\273\245\345\206\205\347\232\204\350\213\261\346\226\207\346\210\226\346\225\260\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
