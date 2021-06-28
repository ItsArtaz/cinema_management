#include "login.h"
#include "ui_login.h"

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
    this->ui->lineEdit->clear();
    this->ui->lineEdit_2->clear();
    this->close();
    mw->show();
}


void Login::on_continue_btn_clicked()
{
    bool found = false;
    user person ;
    admin_panel = new Admin_panel(0,this->mw);
    menu = new Menu(0,this->mw,this->ui->lineEdit->text());
    person.username=this->ui->lineEdit->text();
    person.password=this->ui->lineEdit_2->text();
    person.username=person.username.toLower();
    if (person.username=="admin")
    {
        if (person.password=="admin")
        {
            this->close();
            admin_panel->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            admin_panel->show();
        }
        else
        {
            this->ui->label_4->setText("Your password is wrong !!");
        }
    }
    else
    {
        QFile user_pass_file("username_pass.txt");
        user_pass_file.open(QFile :: Text | QFile :: ReadOnly);
        QTextStream user_pass_txtstream(&user_pass_file);
        QStringList  user_pass_stringlist;
        while (!user_pass_txtstream.atEnd())
        {
            user_pass_stringlist = user_pass_txtstream.readLine().split(",");
            if (person.username==user_pass_stringlist[0])
            {
                if (person.password==user_pass_stringlist[1])
                {
                    found = true;
                }
                break;
            }
            else
            {
                found = false;
            }
        }
        user_pass_file.close();
        if (found == true)
        {
            this->ui->lineEdit->clear();
            this->ui->lineEdit_2->clear();
            this->ui->label_4->setText("");
            this->close();
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            menu->show();
        }
        else
        {
            this->ui->lineEdit->clear();
            this->ui->lineEdit_2->clear();
            this->ui->label_4->setText("Your username or password is wrong!!");
        }
    }
}

