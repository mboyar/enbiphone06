#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modemCommands = new QSerialPort();
    modemCommands->setBaudRate(QSerialPort::Baud115200);
    modemCommands->setPortName("/dev/ttyS0");
    modemCommands->open(QIODevice::ReadWrite);

    connect(modemCommands, SIGNAL(readyRead()), this, SLOT(readModem()));
}

MainWindow::~MainWindow()
{
    delete ui;
    modemCommands->close();
}


void MainWindow::on_pushButton_1_clicked()
{
    phoneNumber += "1";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_2_clicked()
{
    phoneNumber += "2";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_3_clicked()
{
    phoneNumber += "3";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_4_clicked()
{
    phoneNumber += "4";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_5_clicked()
{
    phoneNumber += "5";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_6_clicked()
{
    phoneNumber += "6";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_7_clicked()
{
    phoneNumber += "7";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_8_clicked()
{
    phoneNumber += "8";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_9_clicked()
{
    phoneNumber += "9";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_asterisk_clicked()
{
    phoneNumber += "*";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_0_clicked()
{
    phoneNumber += "0";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_sharp_clicked()
{
    phoneNumber += "#";
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_clear_clicked()
{
    phoneNumber.truncate(phoneNumber.size() - 1);
    ui->textBrowser->setText(phoneNumber);
}

void MainWindow::on_pushButton_call_clicked()
{
    QByteArray cmdATD = "ATD" + phoneNumber.toUtf8() + ";" + '\r';
    modemCommands->write(cmdATD);

    qDebug() << "phoneNumber: " << phoneNumber;
}

void MainWindow::readModem()
{
    qDebug() << modemCommands->readAll();
}

void MainWindow::on_pushButton_cancel_clicked()
{
    QByteArray cmdATD = "ATH";
    cmdATD.append('\r');
    modemCommands->write(cmdATD);
}
