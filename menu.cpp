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

