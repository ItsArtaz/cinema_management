#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent,QMainWindow *mw) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QString date = QDate :: currentDate().toString();
    QLabel *datel=new QLabel(date);
    ui->statusbar->addWidget(datel);
    QString time = QTime :: currentTime().toString();
    QLabel *timel=new QLabel(time);
    ui->statusbar->addWidget(timel);
    archive = new Archive(0,this);
    booking = new Booking(0,this);
    this->mw=mw;
}
void Menu::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Menu::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_exit_btn_clicked()
{
    this->close();
    mw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mw->show();
}


void Menu::on_archive_btn_clicked()
{
    this->close();
    archive->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    archive->show();
}


void Menu::on_book_btn_clicked()
{
    this->close();
    booking->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    booking->show();
}

