#include "signup.h"
#include "ui_signup.h"
#include "QTimeEdit"
#include "QLabel"
#include "QString"
#include "QDateEdit"
#include "QMessageBox"
#include "iterator"
#include "QFile"
#include "QTextStream"
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
void Signup::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Signup::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void Signup::on_pb4_clicked()
{
    this->close();
    mw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mw->show();
}


void Signup::on_pb3_clicked()
{
    bool username_exist = false;
    QFile user_pass_file("username_pass.txt");
    user_pass_file.open(QFile :: Text | QFile :: ReadWrite);
    QTextStream user_pass_txtstream(&user_pass_file);
    QStringList  user_pass_stringlist;
    while (!user_pass_file.atEnd())
    {
        user_pass_stringlist = user_pass_txtstream.readLine().split(",");
        if (this->ui->le1->text()==user_pass_stringlist[0])
        {
            username_exist=true;
            break;
        }
        else
        {
            username_exist=false;
        }
    }
    if (username_exist==false)
    {
        user_pass_txtstream <<this->ui->le1->text()<<","<<this->ui->le2->text();
        user_pass_file.close();
        QMessageBox ::information(this,"Register","Your Account Created !");
        this->close();
        this->mw->show();
    }
    else
    {
        this->ui->l4->setText("This Username Already Exist !!");
        user_pass_file.close();
    }
}

