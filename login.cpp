#include "login.h"
#include "ui_login.h"
#include "QTimeEdit"
#include "QLabel"
#include "QString"
#include "QDateEdit"

Login::Login(QWidget *parent, QMainWindow *mw) :
    QMainWindow(parent),
    ui(new Ui::Login)
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

Login::~Login()
{
    delete ui;
}
void Login::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Login::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void Login::on_back_btn_clicked()
{
    this->close();
    mw->show();
}

