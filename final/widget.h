#ifndef WIDGET_H
#define WIDGET_H
#include <QMainWindow>
class QStandardItemModel;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //从指定的文件读取数据
    void readDataFromFile(const QString &filename);

    void saveDataToFile(const QString &filename);

private slots:
    void on_add_info_clicked();

    void on_save_data_clicked();

    void on_delete_info_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated();

    void on_comboBox_2_activated();

    void on_comboBox_3_activated();

private:
    Ui::Widget *ui;
    QStandardItemModel* model;
};
#endif // WIDGET_H
