/********************************************************************************
** Form generated from reading UI file 'find.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_H
#define UI_FIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Find
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *account;
    QLineEdit *tele;
    QLineEdit *affirm;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *new_pwd;
    QLabel *label_5;
    QPushButton *pushButton;
    QWidget *widget;
    QCheckBox *teacher;
    QCheckBox *student;

    void setupUi(QMainWindow *Find)
    {
        if (Find->objectName().isEmpty())
            Find->setObjectName(QString::fromUtf8("Find"));
        Find->resize(643, 424);
        Find->setMinimumSize(QSize(643, 418));
        Find->setMaximumSize(QSize(643, 1000));
        centralwidget = new QWidget(Find);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 30, 121, 31));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"\351\232\266\344\271\246\";"));
        account = new QLineEdit(centralwidget);
        account->setObjectName(QString::fromUtf8("account"));
        account->setGeometry(QRect(220, 80, 261, 31));
        tele = new QLineEdit(centralwidget);
        tele->setObjectName(QString::fromUtf8("tele"));
        tele->setGeometry(QRect(220, 130, 261, 31));
        affirm = new QLineEdit(centralwidget);
        affirm->setObjectName(QString::fromUtf8("affirm"));
        affirm->setGeometry(QRect(220, 230, 261, 31));
        affirm->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 140, 141, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 90, 41, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 240, 81, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        new_pwd = new QLineEdit(centralwidget);
        new_pwd->setObjectName(QString::fromUtf8("new_pwd"));
        new_pwd->setGeometry(QRect(220, 180, 261, 31));
        new_pwd->setEchoMode(QLineEdit::Password);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 190, 61, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 350, 111, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(170, 280, 311, 61));
        teacher = new QCheckBox(widget);
        teacher->setObjectName(QString::fromUtf8("teacher"));
        teacher->setGeometry(QRect(50, 20, 71, 21));
        teacher->setCursor(QCursor(Qt::PointingHandCursor));
        teacher->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        teacher->setAutoExclusive(true);
        student = new QCheckBox(widget);
        student->setObjectName(QString::fromUtf8("student"));
        student->setGeometry(QRect(190, 20, 71, 21));
        student->setCursor(QCursor(Qt::PointingHandCursor));
        student->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        student->setAutoExclusive(true);
        Find->setCentralWidget(centralwidget);

        retranslateUi(Find);

        QMetaObject::connectSlotsByName(Find);
    } // setupUi

    void retranslateUi(QMainWindow *Find)
    {
        Find->setWindowTitle(QCoreApplication::translate("Find", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Find", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("Find", "\346\263\250\345\206\214\344\275\277\347\224\250\346\211\213\346\234\272\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("Find", "\350\264\246\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("Find", "\345\257\206\347\240\201\347\241\256\350\256\244", nullptr));
        label_5->setText(QCoreApplication::translate("Find", "\346\226\260\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Find", "\347\241\256\350\256\244", nullptr));
        teacher->setText(QCoreApplication::translate("Find", "\346\225\231\345\270\210", nullptr));
        student->setText(QCoreApplication::translate("Find", "\345\255\246\347\224\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Find: public Ui_Find {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_H
