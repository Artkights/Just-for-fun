/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QPushButton *LoginBotton;
    QPushButton *registerBotton;
    QPushButton *changePsw;
    QPushButton *deleteBotton;
    QLabel *welcome;
    QPushButton *backups;

    void setupUi(QDialog *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(842, 711);
        mainWindow->setMinimumSize(QSize(842, 711));
        mainWindow->setMaximumSize(QSize(842, 711));
        mainWindow->setFocusPolicy(Qt::NoFocus);
        mainWindow->setAutoFillBackground(false);
        mainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/background.jpg);"));
        LoginBotton = new QPushButton(mainWindow);
        LoginBotton->setObjectName(QString::fromUtf8("LoginBotton"));
        LoginBotton->setGeometry(QRect(330, 210, 181, 51));
        LoginBotton->setCursor(QCursor(Qt::PointingHandCursor));
        LoginBotton->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));
        registerBotton = new QPushButton(mainWindow);
        registerBotton->setObjectName(QString::fromUtf8("registerBotton"));
        registerBotton->setGeometry(QRect(330, 290, 181, 51));
        registerBotton->setCursor(QCursor(Qt::PointingHandCursor));
        registerBotton->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));
        changePsw = new QPushButton(mainWindow);
        changePsw->setObjectName(QString::fromUtf8("changePsw"));
        changePsw->setGeometry(QRect(330, 370, 181, 51));
        changePsw->setCursor(QCursor(Qt::PointingHandCursor));
        changePsw->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));
        deleteBotton = new QPushButton(mainWindow);
        deleteBotton->setObjectName(QString::fromUtf8("deleteBotton"));
        deleteBotton->setGeometry(QRect(330, 450, 181, 51));
        deleteBotton->setCursor(QCursor(Qt::PointingHandCursor));
        deleteBotton->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));
        welcome = new QLabel(mainWindow);
        welcome->setObjectName(QString::fromUtf8("welcome"));
        welcome->setGeometry(QRect(180, 100, 481, 71));
        welcome->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\232\266\344\271\246\";"));
        welcome->setFrameShape(QFrame::NoFrame);
        backups = new QPushButton(mainWindow);
        backups->setObjectName(QString::fromUtf8("backups"));
        backups->setGeometry(QRect(330, 530, 181, 51));
        backups->setCursor(QCursor(Qt::PointingHandCursor));
        backups->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QDialog *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "Dialog", nullptr));
        LoginBotton->setText(QCoreApplication::translate("mainWindow", "\347\231\273\351\231\206\350\264\246\345\217\267", nullptr));
        registerBotton->setText(QCoreApplication::translate("mainWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        changePsw->setText(QCoreApplication::translate("mainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        deleteBotton->setText(QCoreApplication::translate("mainWindow", "\346\263\250\351\224\200\350\264\246\345\217\267", nullptr));
        welcome->setText(QCoreApplication::translate("mainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\345\255\246\347\224\237\346\210\220\347\273\251\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        backups->setText(QCoreApplication::translate("mainWindow", "\347\224\250\346\210\267\345\244\207\344\273\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
