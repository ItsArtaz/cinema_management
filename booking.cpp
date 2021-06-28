#include "booking.h"
#include "ui_booking.h"

Booking::Booking(QWidget *parent,QMainWindow *menu) :
    QMainWindow(parent),
    ui(new Ui::Booking)
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
void Booking::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Booking::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}
Booking::~Booking()
{
    delete ui;
}

void Booking::on_pushButton_4_clicked()
{
    int capa;
    QString capa_str;
    bool isline=false;
    QFile movie_file("movies.txt");
    QFile tmp_file("tmp.txt");
    tmp_file.open(QFile ::Text |QFile::WriteOnly);
    movie_file.open(QFile :: Text | QFile :: ReadWrite);
    QTextStream movie_txtstream(&movie_file);
    QTextStream tmp_txtstream(&tmp_file);
    QStringList  movie_stringlist;
    while (!movie_txtstream.atEnd())
    {
        movie_stringlist = movie_txtstream.readLine().split(',');
        if(movie_stringlist[0] == this->ui->name_le->text())
        {
            if (movie_stringlist[3]==this->ui->direct_le->text())
            {

                isline = true;
            }
        }
        if (isline == false)
        {
            tmp_txtstream << movie_stringlist[0]<<','<<movie_stringlist[1]<<','<<movie_stringlist[2]<<','<<movie_stringlist[3];
            tmp_txtstream <<','<<movie_stringlist[4]<<','<<movie_stringlist[5]<<','<<movie_stringlist[6]<<','<<movie_stringlist[7]<<',';
            tmp_txtstream <<movie_stringlist[8]<<','<<movie_stringlist[9]<<'\n';
        }
        else
        {
            tmp_txtstream << movie_stringlist[0]<<','<<movie_stringlist[1]<<','<<movie_stringlist[2]<<','<<movie_stringlist[3];
            tmp_txtstream <<','<<movie_stringlist[4]<<','<<movie_stringlist[5]<<','<<movie_stringlist[6]<<',';
            capa=this->ui->capa_le->text().toInt();
            if (capa == 0)
            {
                QMessageBox ::information(this,"Cant book","We dont have Enough room !!");
                tmp_txtstream <<movie_stringlist[7]<<','<<movie_stringlist[8]<<','<<movie_stringlist[9]<<'\n';
            }
            else
            {
                capa--;
                capa_str=QString::number(capa);
                tmp_txtstream <<capa_str<<','<<movie_stringlist[8]<<','<<movie_stringlist[9]<<'\n';
                isline=false;

            }
        }
    }
    tmp_file.close();
    movie_file.close();
    remove("movies.txt");
    rename("tmp.txt","movies.txt");
    if ( this->ui->capa_le->text().toInt() != 0)
    {
        QMessageBox ::information(this,"Booked","Movie Booked !!");
        this->ui->name_le->clear();
        this->ui->direct_le->clear();
        this->ui->genre_le->clear();
        this->ui->actor_le->clear();
        this->ui->capa_le->clear();
        this->ui->seach_le->clear();
        this->close();
        menu->show();
    }
}
void Booking::on_pushButton_3_clicked()
{
    this->ui->name_le->clear();
    this->ui->direct_le->clear();
    this->ui->genre_le->clear();
    this->ui->actor_le->clear();
    this->ui->capa_le->clear();
    bool found=false;
    QString line=this->ui->seach_le->text();
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
    for (auto ii : info)
    {
        for (int i=0;i<10;i++)
        {
            if(true==ii[i].startsWith(line))
            {
                found=true;
                break;
            }
        }
        if (found ==true)
        {
            this->ui->name_le->setText(ii[0]);
            this->ui->direct_le->setText(ii[3]);
            this->ui->genre_le->setText(ii[1] + ',' + ii[2]);
            this->ui->actor_le->setText(ii[5] + ',' + ii[6]);
            this->ui->capa_le->setText(ii[7]);
            break;
        }
        else
        {
            found=false;
        }
    }
    if (found ==false)
    {
        QMessageBox ::information(this,"Not Found","Movie Not Found !!");
    }
}


void Booking::on_seach_le_textChanged(const QString &arg1)
{
    this->ui->name_le->clear();
    this->ui->direct_le->clear();
    this->ui->genre_le->clear();
    this->ui->actor_le->clear();
    this->ui->capa_le->clear();
    bool found=false;
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
    for (auto ii : info)
    {
        for (int i=0;i<10;i++)
        {
            if(true==ii[i].startsWith(line))
            {
                found=true;
                break;
            }
        }
        if (found ==true && line != "")
        {
            this->ui->name_le->setText(ii[0]);
            this->ui->direct_le->setText(ii[3]);
            this->ui->genre_le->setText(ii[1] + ',' + ii[2]);
            this->ui->actor_le->setText(ii[5] + ',' + ii[6]);
            this->ui->capa_le->setText(ii[7]);
            break;
        }
        else
        {
            found=false;
        }
    }
}

