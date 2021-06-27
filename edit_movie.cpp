#include "edit_movie.h"
#include "ui_edit_movie.h"

Edit_movie::Edit_movie(QWidget *parent,QMainWindow *panel) :
    QMainWindow(parent),
    ui(new Ui::Edit_movie)
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
void Edit_movie::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Edit_movie::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

Edit_movie::~Edit_movie()
{
    delete ui;
}

void Edit_movie::on_edit_btn_clicked()
{
    bool isline=false,isfound=false;
    movie newinfo;
    newinfo.name=this->ui->newname_le->text();
    newinfo.name=newinfo.name.toLower();
    newinfo.genre=this->ui->newgenre_le->text();
    newinfo.genre=newinfo.genre.toLower();
    newinfo.released=this->ui->newrelease_le->text();
    newinfo.released=newinfo.released.toLower();
    newinfo.actor=this->ui->newactor_le->text();
    newinfo.actor=newinfo.actor.toLower();
    newinfo.director=this->ui->newdirect_le->text();
    newinfo.director=newinfo.director.toLower();
    newinfo.group=this->ui->newgp_le->text();
    newinfo.group=newinfo.group.toLower();
    newinfo.capacity=this->ui->newcapa_le->text();
    newinfo.suggested=this->ui->checkBox->isChecked();
    movie oldinfo;
    oldinfo.name=this->ui->oldname_le->text();
    oldinfo.name=oldinfo.name.toLower();
    oldinfo.genre=this->ui->oldgenre_le->text();
    oldinfo.genre=oldinfo.genre.toLower();
    oldinfo.released=this->ui->oldrelease_le->text();
    oldinfo.released=oldinfo.released.toLower();
    oldinfo.actor=this->ui->oldactor_le->text();
    oldinfo.actor=oldinfo.actor.toLower();
    oldinfo.director=this->ui->olddirect_le->text();
    oldinfo.director=oldinfo.director.toLower();
    oldinfo.group=this->ui->oldgp_le->text();
    oldinfo.group=oldinfo.group.toLower();
    oldinfo.capacity=this->ui->oldcapa_le->text();
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
        if(movie_stringlist[0] == oldinfo.name)
        {
            if(movie_stringlist[1]==oldinfo.genre || movie_stringlist[2]==oldinfo.genre)
            {
                if (movie_stringlist[3]==oldinfo.director)
                {
                    if (movie_stringlist[4]==oldinfo.released)
                    {
                        if(movie_stringlist[5]==oldinfo.actor || movie_stringlist[6]==oldinfo.actor)
                        {
                            isline = false;
                            isfound =true;
                        }
                        else
                        {
                            isline =true;
                        }
                    }
                    else
                    {
                        isline=true;
                    }
                }
                else
                {
                    isline=true;
                }
            }
            else
            {
                isline=true;
            }
        }
        else
        {
            isline=true;
        }
        if (isline == true)
        {
            tmp_txtstream << movie_stringlist[0]<<','<<movie_stringlist[1]<<','<<movie_stringlist[2]<<','<<movie_stringlist[3];
            tmp_txtstream <<','<<movie_stringlist[4]<<','<<movie_stringlist[5]<<','<<movie_stringlist[6]<<','<<movie_stringlist[7]<<','<<movie_stringlist[8];
            tmp_txtstream <<'\n';
        }
        else
        {
            tmp_txtstream <<newinfo.name<<','<<newinfo.genre<<','<<newinfo.director<<','<<newinfo.released<<','<<newinfo.actor<<','<<newinfo.capacity;
            if (newinfo.suggested==true)
            {
                tmp_txtstream <<','<<"recommended";
            }
            else
            {
                tmp_txtstream <<','<<"no recommended";
            }
        }
        if(newinfo.group != "")
        {
            tmp_txtstream <<','<<newinfo.group<<'\n';
        }
        else
        {
            tmp_txtstream <<','<<'\n';
        }
    }
    tmp_file.close();
    movie_file.close();
    remove("movies.txt");
    rename("tmp.txt","movies.txt");
    if (isfound == true)
    {
        QMessageBox ::information(this,"Edited","Movie Edited !!");
        this->close();
        panel->show();
    }
    else
    {
        QMessageBox ::information(this,"Error","Movie Not Found !!");
    }

}

