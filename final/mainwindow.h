#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class mainWindow;
}

class mainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:

    void on_LoginBotton_clicked();

    void on_registerBotton_clicked();

    void on_changePsw_clicked();

    void on_backups_clicked();

    void on_deleteBotton_clicked();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
