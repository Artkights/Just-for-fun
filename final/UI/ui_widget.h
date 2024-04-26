/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QAction *tableView;
    QWidget *centralwidget;
    QPushButton *add_info;
    QPushButton *delete_info;
    QPushButton *save_data;
    QTableView *tableView_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1212, 793);
        Widget->setMinimumSize(QSize(1212, 793));
        Widget->setMaximumSize(QSize(1212, 793));
        tableView = new QAction(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        centralwidget = new QWidget(Widget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        add_info = new QPushButton(centralwidget);
        add_info->setObjectName(QString::fromUtf8("add_info"));
        add_info->setGeometry(QRect(10, 70, 93, 28));
        add_info->setCursor(QCursor(Qt::PointingHandCursor));
        delete_info = new QPushButton(centralwidget);
        delete_info->setObjectName(QString::fromUtf8("delete_info"));
        delete_info->setGeometry(QRect(110, 70, 93, 28));
        delete_info->setCursor(QCursor(Qt::PointingHandCursor));
        save_data = new QPushButton(centralwidget);
        save_data->setObjectName(QString::fromUtf8("save_data"));
        save_data->setGeometry(QRect(210, 70, 93, 28));
        save_data->setCursor(QCursor(Qt::PointingHandCursor));
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(0, 140, 1211, 631));
        tableView_2->setMinimumSize(QSize(1211, 631));
        tableView_2->setMaximumSize(QSize(1211, 631));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 10, 171, 51));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\232\266\344\271\246\";"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(330, 70, 181, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 70, 71, 28));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(710, 70, 121, 31));
        comboBox->setCursor(QCursor(Qt::OpenHandCursor));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(890, 70, 121, 31));
        comboBox_2->setCursor(QCursor(Qt::OpenHandCursor));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(630, 70, 72, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(850, 75, 41, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(1070, 70, 121, 31));
        comboBox_3->setCursor(QCursor(Qt::OpenHandCursor));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1030, 70, 41, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        Widget->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Widget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Widget->setStatusBar(statusbar);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QMainWindow *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        tableView->setText(QCoreApplication::translate("Widget", "tableView", nullptr));
        add_info->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\345\255\246\347\224\237", nullptr));
        delete_info->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244\345\255\246\347\224\237", nullptr));
        save_data->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\225\231\345\270\210\347\256\241\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "\345\205\250\346\240\241", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "\350\275\257\344\273\2661401", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "\350\256\241\347\256\227\346\234\2721401", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Widget", "\350\256\241\347\256\227\346\234\2721402", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("Widget", "\345\205\250\346\240\241", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Widget", "\345\205\250\347\247\221", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Widget", "\350\257\255\346\226\207", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Widget", "\346\225\260\345\255\246", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Widget", "\350\213\261\350\257\255", nullptr));

        comboBox_2->setCurrentText(QCoreApplication::translate("Widget", "\345\205\250\347\247\221", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\344\270\223\344\270\232\347\217\255\347\272\247", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\255\246\347\247\221", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Widget", "\351\273\230\350\256\244", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Widget", "\346\214\211\345\255\246\345\217\267\351\241\272\345\272\217", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Widget", "\346\214\211\347\217\255\347\272\247\351\241\272\345\272\217", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("Widget", "\346\214\211\350\257\255\346\226\207\346\210\220\347\273\251", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("Widget", "\346\214\211\346\225\260\345\255\246\346\210\220\347\273\251", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("Widget", "\346\214\211\350\213\261\350\257\255\346\210\220\347\273\251", nullptr));

        comboBox_3->setCurrentText(QCoreApplication::translate("Widget", "\351\273\230\350\256\244", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\346\216\222\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
