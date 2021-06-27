#ifndef EDIT_MOVIE_H
#define EDIT_MOVIE_H

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
namespace Ui {
class Edit_movie;
}

class Edit_movie : public QMainWindow
{
    Q_OBJECT

public:
    explicit Edit_movie(QWidget *parent = nullptr,QMainWindow *panel=nullptr);
    ~Edit_movie();

private slots:
    void on_edit_btn_clicked();

private:
    Ui::Edit_movie *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow *panel;
};

#endif // EDIT_MOVIE_H
