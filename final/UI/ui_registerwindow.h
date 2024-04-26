/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerWindow
{
public:
    QPushButton *register_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *account;
    QLineEdit *password;
    QLineEdit *confirm;
    QLineEdit *tele;
    QWidget *widget;
    QCheckBox *students;
    QCheckBox *teachers;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *registerWindow)
    {
        if (registerWindow->objectName().isEmpty())
            registerWindow->setObjectName(QString::fromUtf8("registerWindow"));
        registerWindow->resize(664, 469);
        registerWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/QQ\345\233\276\347\211\20720240331094419.jpg);"));
        register_2 = new QPushButton(registerWindow);
        register_2->setObjectName(QString::fromUtf8("register_2"));
        register_2->setGeometry(QRect(280, 400, 101, 41));
        register_2->setCursor(QCursor(Qt::PointingHandCursor));
        register_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/OIP-C.jpg);\n"
"font: 12pt \"\351\273\221\344\275\223\";"));
        label = new QLabel(registerWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 50, 161, 51));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\232\266\344\271\246\";"));
        label_2 = new QLabel(registerWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 150, 51, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(registerWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 190, 51, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(registerWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 230, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_5 = new QLabel(registerWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 270, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        account = new QLineEdit(registerWindow);
        account->setObjectName(QString::fromUtf8("account"));
        account->setGeometry(QRect(220, 150, 241, 31));
        account->setStyleSheet(QString::fromUtf8("background-image: url(:/images/OIP-C.jpg);"));
        password = new QLineEdit(registerWindow);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(220, 190, 241, 31));
        password->setStyleSheet(QString::fromUtf8("background-image: url(:/images/OIP-C.jpg);"));
        password->setEchoMode(QLineEdit::Password);
        confirm = new QLineEdit(registerWindow);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(220, 230, 241, 31));
        confirm->setStyleSheet(QString::fromUtf8("background-image: url(:/images/OIP-C.jpg);"));
        confirm->setEchoMode(QLineEdit::Password);
        tele = new QLineEdit(registerWindow);
        tele->setObjectName(QString::fromUtf8("tele"));
        tele->setGeometry(QRect(220, 270, 241, 31));
        tele->setStyleSheet(QString::fromUtf8("background-image: url(:/images/OIP-C.jpg);"));
        widget = new QWidget(registerWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 310, 201, 80));
        students = new QCheckBox(widget);
        students->setObjectName(QString::fromUtf8("students"));
        students->setGeometry(QRect(120, 30, 71, 19));
        students->setCursor(QCursor(Qt::PointingHandCursor));
        students->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        students->setAutoExclusive(true);
        teachers = new QCheckBox(widget);
        teachers->setObjectName(QString::fromUtf8("teachers"));
        teachers->setGeometry(QRect(30, 30, 71, 19));
        teachers->setCursor(QCursor(Qt::PointingHandCursor));
        teachers->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        teachers->setAutoExclusive(true);
        label_6 = new QLabel(registerWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 160, 161, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 7pt \"\351\273\221\344\275\223\";"));
        label_7 = new QLabel(registerWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 200, 161, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 7pt \"\351\273\221\344\275\223\";"));

        retranslateUi(registerWindow);

        QMetaObject::connectSlotsByName(registerWindow);
    } // setupUi

    void retranslateUi(QDialog *registerWindow)
    {
        registerWindow->setWindowTitle(QCoreApplication::translate("registerWindow", "Dialog", nullptr));
        register_2->setText(QCoreApplication::translate("registerWindow", "\346\263\250 \345\206\214", nullptr));
        label->setText(QCoreApplication::translate("registerWindow", "\346\254\242\350\277\216\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("registerWindow", "\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("registerWindow", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("registerWindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("registerWindow", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        students->setText(QCoreApplication::translate("registerWindow", "\345\255\246\347\224\237", nullptr));
        teachers->setText(QCoreApplication::translate("registerWindow", "\346\225\231\345\270\210", nullptr));
        label_6->setText(QCoreApplication::translate("registerWindow", "\350\257\267\350\276\223\345\205\24510\344\275\215\344\273\245\345\206\205\347\232\204\350\213\261\346\226\207\346\210\226\346\225\260\345\255\227", nullptr));
        label_7->setText(QCoreApplication::translate("registerWindow", "\350\257\267\350\276\223\345\205\24510\344\275\215\344\273\245\345\206\205\347\232\204\350\213\261\346\226\207\346\210\226\346\225\260\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerWindow: public Ui_registerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
