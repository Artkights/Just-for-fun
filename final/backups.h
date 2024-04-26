#ifndef BACKUPS_H
#define BACKUPS_H

#include <QMainWindow>

namespace Ui {
class BackUps;
}

class BackUps : public QMainWindow
{
    Q_OBJECT

public:
    explicit BackUps(QWidget *parent = nullptr);
    ~BackUps();

private slots:
    void on_account_textEdited();

    void on_password_textEdited();

    void on_pushButton_clicked();

private:
    Ui::BackUps *ui;
};

#endif // BACKUPS_H
