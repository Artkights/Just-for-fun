#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class changePassword;
}

class changePassword : public QDialog
{
    Q_OBJECT

public:
    explicit changePassword(QWidget *parent = nullptr);
    ~changePassword();

private slots:
    void on_orig_password_textEdited();

    void on_new_password_textEdited();

    void on_confirm_textEdited();

    void on_account_textEdited();

    void on_pushButton_clicked();

private:
    Ui::changePassword *ui;
    changePassword *changepwd;
};

#endif // CHANGEPASSWORD_H
