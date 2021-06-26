#ifndef ADD_MOVIE_H
#define ADD_MOVIE_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QString>
#include "QTimeEdit"
#include "QLabel"
#include "QDateEdit"
#include "movie.h"
namespace Ui {
class Add_movie;
}

class Add_movie : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_movie(QWidget *parent = nullptr,QMainWindow *panel=nullptr);
    ~Add_movie();

private slots:
    void on_save_btn_clicked();

private:
    Ui::Add_movie *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow *panel;

};

#endif // ADD_MOVIE_H
