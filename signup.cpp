#include "signup.h"
#include "ui_signup.h"
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
    user person;
    person.username=this->ui->le1->text();
    person.password=this->ui->le2->text();
    person.username= person.username.toLower();
    bool username_exist = false;
    QFile user_pass_file("username_pass.txt");
    user_pass_file.open(QFile :: Text | QFile :: ReadWrite);
    QTextStream user_pass_txtstream(&user_pass_file);
    QStringList  user_pass_stringlist;
    while (!user_pass_txtstream.atEnd())
    {
        user_pass_stringlist = user_pass_txtstream.readLine().split(',');
        if (person.username==user_pass_stringlist[0])
        {
            username_exist=true;
            break;
        }
        else
        {
            username_exist=false;
        }
        user_pass_stringlist={""};
    }
    if (username_exist==false && person.username !="" && person.password != "")
    {
        user_pass_txtstream <<person.username<<","<<person.password<<"\n";
        user_pass_file.close();
        QMessageBox ::information(this,"Register","Your Account Created !!");
        this->ui->le1->setText("");
        this->ui->le2->setText("");
        this->ui->l4->setText("");
        this->ui->cb1->setChecked(false);
        this->close();
        this->mw->show();
    }
    else if (username_exist==true)
    {
        this->ui->l4->setText("This Username Already Exist !!");
        user_pass_file.close();
    }
}

