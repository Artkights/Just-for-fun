/********************************************************************************
** Form generated from reading UI file 'backups.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKUPS_H
#define UI_BACKUPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackUps
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLineEdit *account;
    QLineEdit *password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BackUps)
    {
        if (BackUps->objectName().isEmpty())
            BackUps->setObjectName(QString::fromUtf8("BackUps"));
        BackUps->resize(593, 334);
        centralwidget = new QWidget(BackUps);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 30, 141, 41));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\232\266\344\271\246\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 100, 91, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 150, 91, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 220, 93, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        account = new QLineEdit(centralwidget);
        account->setObjectName(QString::fromUtf8("account"));
        account->setGeometry(QRect(210, 100, 211, 31));
        password = new QLineEdit(centralwidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(210, 150, 211, 31));
        BackUps->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BackUps);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 593, 26));
        BackUps->setMenuBar(menubar);
        statusbar = new QStatusBar(BackUps);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BackUps->setStatusBar(statusbar);

        retranslateUi(BackUps);

        QMetaObject::connectSlotsByName(BackUps);
    } // setupUi

    void retranslateUi(QMainWindow *BackUps)
    {
        BackUps->setWindowTitle(QCoreApplication::translate("BackUps", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("BackUps", "\347\224\250\346\210\267\345\244\207\344\273\275", nullptr));
        label_2->setText(QCoreApplication::translate("BackUps", "\347\256\241\347\220\206\345\221\230\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("BackUps", "\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("BackUps", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackUps: public Ui_BackUps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKUPS_H
