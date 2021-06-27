#include "admin_panel.h"
#include "ui_admin_panel.h"

Admin_panel::Admin_panel(QWidget *parent,QMainWindow *mw) :
    QMainWindow(parent),
    ui(new Ui::Admin_panel)
{
    ui->setupUi(this);
    QString date = QDate :: currentDate().toString();
    QLabel *datel=new QLabel(date);
    ui->statusbar->addWidget(datel);
    QString time = QTime :: currentTime().toString();
    QLabel *timel=new QLabel(time);
    ui->statusbar->addWidget(timel);
    add_movie = new Add_movie(0,this);
    del_movie = new delete_movie(0,this);
    edit_movie = new Edit_movie(0,this);
    this->mw=mw;
}
void Admin_panel::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Admin_panel::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

Admin_panel::~Admin_panel()
{
    delete ui;
}

void Admin_panel::on_exit_btn_clicked()
{
    this->close();
    mw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mw->show();
}


void Admin_panel::on_add_btn_clicked()
{
    this->close();
    add_movie->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    add_movie->show();
}


void Admin_panel::on_delete_btn_clicked()
{
    this->close();
    del_movie->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    del_movie->show();
}


void Admin_panel::on_edit_btn_clicked()
{
    this->close();
    edit_movie->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    edit_movie->show();
}

