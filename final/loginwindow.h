#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QLineEdit>
#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:

    void on_login_clicked();

    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
    LoginWindow *loginwindow;
};

#endif // LOGINWINDOW_H
