#include "signup.h"
#include "ui_signup.h"
#include "QTimeEdit"
#include "QLabel"
#include "QString"
#include "QDateEdit"
Signup::Signup(QWidget *parent,QMainWindow *mw) :
    QMainWindow(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
    QString date = QDate :: currentDate().toString();
    QLabel *datel=new QLabel(date);
    ui->statusbar->addWidget(datel);
    QString time = QTime :: currentTime().toString();
    QLabel *timel=new QLabel(time);
    ui->statusbar->addWidget(timel);
    this->mw=mw;
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_pb4_clicked()
{
    this->hide();
    mw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mw->show();
}

