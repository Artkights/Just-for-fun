#ifndef STUDENT_H
#define STUDENT_H
#include <QStandardItemModel>
#include <QDialog>
#include <QTableWidget>
class QStandardItemModel;


namespace Ui {class Student;}

class Student : public QDialog
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    ~Student();

    void readDataFromFile(const QString &filename);

private slots:
    void on_pushButton_2_clicked();

    void on_comboBox_activated();

    void on_comboBox_2_activated();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Student *ui;
};


#endif // STUDENT_H
