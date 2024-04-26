/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Student
{
public:
    QPushButton *pushButton_2;
    QLineEdit *search;
    QTableWidget *tablewidget;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_4;

    void setupUi(QDialog *Student)
    {
        if (Student->objectName().isEmpty())
            Student->setObjectName(QString::fromUtf8("Student"));
        Student->setWindowModality(Qt::NonModal);
        Student->resize(931, 762);
        Student->setMinimumSize(QSize(931, 762));
        Student->setMaximumSize(QSize(931, 762));
        Student->setAutoFillBackground(false);
        pushButton_2 = new QPushButton(Student);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 70, 71, 41));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\347\210\261\345\245\207\350\211\272\351\273\221\344\275\223\";"));
        search = new QLineEdit(Student);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(30, 70, 181, 41));
        tablewidget = new QTableWidget(Student);
        tablewidget->setObjectName(QString::fromUtf8("tablewidget"));
        tablewidget->setGeometry(QRect(0, 130, 931, 630));
        tablewidget->setMinimumSize(QSize(931, 630));
        tablewidget->setMaximumSize(QSize(931, 630));
        label = new QLabel(Student);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 10, 171, 41));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\232\266\344\271\246\";"));
        comboBox = new QComboBox(Student);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(570, 70, 131, 31));
        label_2 = new QLabel(Student);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 70, 41, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        comboBox_2 = new QComboBox(Student);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(370, 70, 131, 31));
        label_3 = new QLabel(Student);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 70, 41, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        comboBox_3 = new QComboBox(Student);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(780, 70, 131, 31));
        label_4 = new QLabel(Student);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(740, 70, 41, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));

        retranslateUi(Student);

        QMetaObject::connectSlotsByName(Student);
    } // setupUi

    void retranslateUi(QDialog *Student)
    {
        Student->setWindowTitle(QCoreApplication::translate("Student", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Student", "\346\220\234  \347\264\242", nullptr));
        label->setText(QCoreApplication::translate("Student", "\345\255\246\347\224\237\346\237\245\350\257\242", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Student", "\345\205\250\347\247\221", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Student", "\346\225\260\345\255\246", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Student", "\350\257\255\346\226\207", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Student", "\350\213\261\350\257\255", nullptr));

        label_2->setText(QCoreApplication::translate("Student", "\345\255\246\347\247\221", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Student", "\345\205\250\346\240\241", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Student", "\350\256\241\347\256\227\346\234\2721401", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Student", "\350\256\241\347\256\227\346\234\2721402", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Student", "\350\275\257\344\273\2661401", nullptr));

        label_3->setText(QCoreApplication::translate("Student", "\347\217\255\347\272\247", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Student", "\345\255\246\345\217\267", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Student", "\347\217\255\347\272\247", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Student", "\350\257\255\346\226\207", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("Student", "\346\225\260\345\255\246", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("Student", "\350\213\261\350\257\255", nullptr));

        label_4->setText(QCoreApplication::translate("Student", "\346\216\222\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student: public Ui_Student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H
