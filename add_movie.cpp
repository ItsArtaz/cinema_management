#include "add_movie.h"
#include "ui_add_movie.h"

Add_movie::Add_movie(QWidget *parent,QMainWindow *panel) :
    QMainWindow(parent),
    ui(new Ui::Add_movie)
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
void Add_movie::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Add_movie::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

Add_movie::~Add_movie()
{
    delete ui;
}

void Add_movie::on_save_btn_clicked()
{
    movie info;
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
    info.capacity=this->ui->capacity_le->text();
    info.suggested=this->ui->checkBox->isChecked();
    info.group=this->ui->group_le->text();
    info.group=info.group.toLower();
    QFile just_for_create("movies.txt");
    just_for_create.open(QFile :: Text | QFile ::WriteOnly);
    just_for_create.close();
    QFile movie_file("movies.txt");
    movie_file.open(QFile :: Text | QFile ::Append);
    QTextStream movie_txtstream(&movie_file);
    movie_txtstream <<info.name<<','<<info.genre<<','<<info.director<<','<<info.released<<','<<info.actor<<','<<info.capacity;
    if (info.suggested==true)
    {
        movie_txtstream <<','<<"recommended";
    }
    else
    {
        movie_txtstream <<','<<"no recommended";
    }
    if (info.group != "")
    {
        movie_txtstream <<',' <<info.group<<'\n';
    }
    else
    {
        movie_txtstream <<','<<'\n';
    }
    movie_file.close();
    QMessageBox ::information(this,"Saved","Movie added !!");
    this->close();
    this->panel->show();
}

