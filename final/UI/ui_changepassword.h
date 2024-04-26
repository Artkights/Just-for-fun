/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changePassword
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *orig_password;
    QLineEdit *new_password;
    QLineEdit *confirm;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *account;
    QWidget *widget;
    QCheckBox *teacher;
    QCheckBox *student;
    QLabel *label_7;

    void setupUi(QDialog *changePassword)
    {
        if (changePassword->objectName().isEmpty())
            changePassword->setObjectName(QString::fromUtf8("changePassword"));
        changePassword->resize(624, 436);
        changePassword->setMinimumSize(QSize(624, 436));
        changePassword->setMaximumSize(QSize(624, 436));
        label = new QLabel(changePassword);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 30, 151, 41));
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\232\266\344\271\246\";"));
        pushButton = new QPushButton(changePassword);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 360, 101, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        orig_password = new QLineEdit(changePassword);
        orig_password->setObjectName(QString::fromUtf8("orig_password"));
        orig_password->setGeometry(QRect(200, 150, 251, 31));
        new_password = new QLineEdit(changePassword);
        new_password->setObjectName(QString::fromUtf8("new_password"));
        new_password->setGeometry(QRect(200, 190, 251, 31));
        confirm = new QLineEdit(changePassword);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(200, 230, 251, 31));
        label_2 = new QLabel(changePassword);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 160, 61, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(changePassword);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 200, 61, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(changePassword);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 240, 81, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        label_5 = new QLabel(changePassword);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 120, 61, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        account = new QLineEdit(changePassword);
        account->setObjectName(QString::fromUtf8("account"));
        account->setGeometry(QRect(200, 110, 251, 31));
        widget = new QWidget(changePassword);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 280, 191, 51));
        teacher = new QCheckBox(widget);
        teacher->setObjectName(QString::fromUtf8("teacher"));
        teacher->setGeometry(QRect(10, 20, 71, 19));
        teacher->setCursor(QCursor(Qt::PointingHandCursor));
        teacher->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        teacher->setAutoExclusive(true);
        student = new QCheckBox(widget);
        student->setObjectName(QString::fromUtf8("student"));
        student->setGeometry(QRect(120, 20, 61, 19));
        student->setCursor(QCursor(Qt::PointingHandCursor));
        student->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        student->setAutoExclusive(true);
        label_7 = new QLabel(changePassword);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(460, 190, 161, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 7pt \"\351\273\221\344\275\223\";"));

        retranslateUi(changePassword);

        QMetaObject::connectSlotsByName(changePassword);
    } // setupUi

    void retranslateUi(QDialog *changePassword)
    {
        changePassword->setWindowTitle(QCoreApplication::translate("changePassword", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("changePassword", "\345\257\206\347\240\201\344\277\256\346\224\271", nullptr));
        pushButton->setText(QCoreApplication::translate("changePassword", "\347\241\256 \350\256\244", nullptr));
        label_2->setText(QCoreApplication::translate("changePassword", "\345\216\237\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("changePassword", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("changePassword", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("changePassword", "\347\224\250\346\210\267\345\220\215", nullptr));
        teacher->setText(QCoreApplication::translate("changePassword", "\346\225\231\345\270\210", nullptr));
        student->setText(QCoreApplication::translate("changePassword", "\345\255\246\347\224\237", nullptr));
        label_7->setText(QCoreApplication::translate("changePassword", "\350\257\267\350\276\223\345\205\24510\344\275\215\344\273\245\345\206\205\347\232\204\350\213\261\346\226\207\346\210\226\346\225\260\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changePassword: public Ui_changePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
