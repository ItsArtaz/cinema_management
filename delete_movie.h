#ifndef DELETE_MOVIE_H
#define DELETE_MOVIE_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "QMessageBox"
#include "QTimeEdit"
#include "QLabel"
#include "QDateEdit"
#include "movie.h"
#include <QVector>
#include <QPair>
namespace Ui {
class delete_movie;
}

class delete_movie : public QMainWindow
{
    Q_OBJECT

public:
    explicit delete_movie(QWidget *parent = nullptr,QMainWindow *panel = nullptr);
    ~delete_movie();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::delete_movie *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow *panel;
};

#endif // DELETE_MOVIE_H
