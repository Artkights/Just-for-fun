#ifndef FIND_H
#define FIND_H

#include <QMainWindow>

namespace Ui {
class Find;
}

class Find : public QMainWindow
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = nullptr);
    ~Find();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Find *ui;
};

#endif // FIND_H
