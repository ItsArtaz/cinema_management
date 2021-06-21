#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimeEdit"
#include "QLabel"
#include "QString"
#include "QDateEdit"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString date = QDate :: currentDate().toString();
    QLabel *datel=new QLabel(date);
    ui->statusbar->addWidget(datel);
    QString time = QTime :: currentTime().toString();
    QLabel *timel=new QLabel(time);
    ui->statusbar->addWidget(timel);
    login = new Login(0,this);
    signup = new Signup(0,this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    this->hide();
    login->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    login->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    this->hide();
    signup->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    signup->show();
}

