#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_asterisk_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_sharp_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_call_clicked();

private:
    Ui::MainWindow *ui;
    QString phoneNumber;
    QSerialPort *modemCommands;

};

#endif // MAINWINDOW_H
