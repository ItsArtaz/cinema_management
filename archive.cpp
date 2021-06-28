#include "archive.h"
#include "ui_archive.h"

Archive::Archive(QWidget *parent,QMainWindow *menu) :
    QMainWindow(parent),
    ui(new Ui::Archive)
{
    ui->setupUi(this);
    QString date = QDate :: currentDate().toString();
    QLabel *datel=new QLabel(date);
    ui->statusbar->addWidget(datel);
    QString time = QTime :: currentTime().toString();
    QLabel *timel=new QLabel(time);
    ui->statusbar->addWidget(timel);
    this->menu=menu;
}
void Archive::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Archive::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

Archive::~Archive()
{
    delete ui;
}


void Archive::on_seach_le_textChanged(const QString &arg1)
{
    int i=1;
    ui->listWidget->clear();
    QString line=arg1;
    line=line.toLower();
    QVector <QStringList> info;
    QStringList movie;
    QFile movie_file("movies.txt");
    movie_file.open(QFile ::Text | QFile ::ReadOnly);
    QTextStream movie_txtstream(&movie_file);
    while(!movie_txtstream.atEnd())
    {
        movie = movie_txtstream.readLine().split(',');
        info.push_back(movie);
    }
    movie_file.close();
    if(this->ui->name_rb->isChecked() && line !="")
    {
        for (auto ii : info)
        {
            if (ii[0].startsWith(line))
            {
                ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
                i++;
            }
        }
    }
    else if(this->ui->direct_rb->isChecked() && line !="")
    {
        i=1;
        for (auto ii : info)
        {
            if (ii[3].startsWith(line))
            {
                ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
                i++;
            }
        }
    }
    else if (this->ui->actor_rb->isChecked() && line !="")
    {
        i=1;
        for (auto ii : info)
        {
            if (ii[6].startsWith(line) || ii[5].startsWith(line))
            {
                ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
                i++;
            }
        }
    }
    else if(this->ui->suggested_rb->isChecked())
    {
        i=1;
        for (auto ii : info)
        {
            if (ii[8]=="recommended")
            {
                ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
                i++;
            }
        }
    }
    else if (this->ui->release_rb->isChecked() && line !="")
    {
        i=1;
        for (auto ii : info)
        {
            if (ii[4].startsWith(line))
            {
                ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
                i++;
            }
        }
    }
    else if (this->ui->genre_rb->isChecked() && line !="")
    {
        i=1;
        for (auto ii : info)
        {
            if (ii[1].startsWith(line) | ii[2].startsWith(line))
            {
                ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
                i++;
            }
        }
    }
    else if(this->ui->gp_rb->isChecked() && line !="")
    {
        i=1;
        for (auto ii : info)
        {
            if (ii[9].startsWith(arg1))
            {
                ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
                i++;
            }
        }
    }
    else if (this->ui->seeall_rb->isChecked())
    {
        for (auto ii : info)
        {

            ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
            i++;
        }
    }

}
void Archive::on_back_pb_clicked()
{
    this->ui->seach_le->clear();
    this->close();
    menu->show();
}


void Archive::on_suggested_rb_clicked()
{
    int i=1;
    ui->listWidget->clear();
    QVector <QStringList> info;
    QStringList movie;
    QFile movie_file("movies.txt");
    movie_file.open(QFile ::Text | QFile ::ReadOnly);
    QTextStream movie_txtstream(&movie_file);
    while(!movie_txtstream.atEnd())
    {
        movie = movie_txtstream.readLine().split(',');
        info.push_back(movie);
    }
    movie_file.close();
    i=1;
    for (auto ii : info)
    {
        if (ii[8]=="recommended")
        {
            ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
            i++;
        }
    }
}


void Archive::on_seeall_rb_clicked()
{
    int i=1;
    ui->listWidget->clear();
    QVector <QStringList> info;
    QStringList movie;
    QFile movie_file("movies.txt");
    movie_file.open(QFile ::Text | QFile ::ReadOnly);
    QTextStream movie_txtstream(&movie_file);
    while(!movie_txtstream.atEnd())
    {
        movie = movie_txtstream.readLine().split(',');
        info.push_back(movie);
    }
    movie_file.close();
    i=1;
    for (auto ii : info)
    {

        ui->listWidget->addItem(QString ::number(i) + ".Name : " + ii[0] + '(' + ii[4] + ')' + '\n' + "Genre : " + ii[1] + ',' + ii[2] +'\n' +"Director : " + ii[3] +'\n'+"Actors : " + ii[5] +',' + ii[6] +'\n'+"Capacity : " + ii[7]);
        i++;
    }

}


void Archive::on_genre_rb_clicked()
{
    ui->listWidget->clear();
}


void Archive::on_name_rb_clicked()
{
    ui->listWidget->clear();
}


void Archive::on_gp_rb_clicked()
{
    ui->listWidget->clear();
}


void Archive::on_actor_rb_clicked()
{
    ui->listWidget->clear();
}


void Archive::on_direct_rb_clicked()
{
    ui->listWidget->clear();
}


void Archive::on_release_rb_clicked()
{
    ui->listWidget->clear();
}

