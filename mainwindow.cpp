#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimeEdit"
#include "QLabel"
#include "QString"
#include "QDateEdit"
#include "QSet"
#include "QFile"
#include "QTextStream"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile user_pass_file("username_pass.txt");
    user_pass_file.open(QFile :: Text | QFile :: ReadOnly);
    QSet<QPair<QString, QString>>username_pass_set;
    QTextStream user_pass_txtstream(&user_pass_file);
    QStringList  user_pass_stringlist;
    while (!user_pass_file.atEnd())
    {
      user_pass_stringlist = user_pass_txtstream.readLine().split(",");
      username_pass_set.insert(std :: make_pair(user_pass_stringlist[0], user_pass_stringlist[1]));
    }

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
void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
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

