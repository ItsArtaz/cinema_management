#include "add_movie.h"
#include "ui_add_movie.h"

Add_movie::Add_movie(QWidget *parent,QMainWindow *panel) :
    QMainWindow(parent),
    ui(new Ui::Add_movie)
{
    ui->setupUi(this);
    QString date = QDate :: currentDate().toString();
    QLabel *datel=new QLabel(date);
    ui->statusbar->addWidget(datel);
    QString time = QTime :: currentTime().toString();
    QLabel *timel=new QLabel(time);
    ui->statusbar->addWidget(timel);
    this->panel=panel;
}
void Add_movie::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Add_movie::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

Add_movie::~Add_movie()
{
    delete ui;
}

void Add_movie::on_save_btn_clicked()
{

}

