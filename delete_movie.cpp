#include "delete_movie.h"
#include "ui_delete_movie.h"

delete_movie::delete_movie(QWidget *parent,QMainWindow *panel) :
    QMainWindow(parent),
    ui(new Ui::delete_movie)
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
void delete_movie::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void delete_movie::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}
delete_movie::~delete_movie()
{
    delete ui;
}

void delete_movie::on_pushButton_3_clicked()
{
    movie info;
    bool writing=false;
    info.name=this->ui->name_le->text();
    info.name=info.name.toLower();
    info.genre=this->ui->genre_le->text();
    info.genre=info.genre.toLower();
    info.released=this->ui->released_le->text();
    info.released=info.released.toLower();
    info.actor=this->ui->actor_le->text();
    info.actor=info.actor.toLower();
    info.director=this->ui->director_le->text();
    info.director=info.director.toLower();
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
        if(movie_stringlist[0] == info.name)
        {
            if(movie_stringlist[1]==info.genre || movie_stringlist[2]==info.genre)
            {
                if (movie_stringlist[3]==info.director)
                {
                    if (movie_stringlist[4]==info.released)
                    {
                        if(movie_stringlist[5]==info.actor || movie_stringlist[6]==info.actor)
                        {
                            writing = false;
                        }
                        else
                        {
                            writing =true;
                        }
                    }
                    else
                    {
                        writing=true;
                    }
                }
                else
                {
                    writing=true;
                }
            }
            else
            {
                writing=true;
            }
        }
        else
        {
            writing=true;
        }
        if (writing == true)
        {
            tmp_txtstream << movie_stringlist[0]<<','<<movie_stringlist[1]<<','<<movie_stringlist[2]<<','<<movie_stringlist[3];
            tmp_txtstream <<','<<movie_stringlist[4]<<','<<movie_stringlist[5]<<','<<movie_stringlist[6]<<','<<movie_stringlist[7]<<','<<movie_stringlist[8];
            tmp_txtstream <<'\n';
        }
    }
    tmp_file.close();
    movie_file.close();
    remove("movies.txt");
    rename("tmp.txt","movies.txt");
    QMessageBox ::information(this,"Deleted","Movie Deleted !!");
    this->close();
    panel->show();

}

