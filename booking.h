#ifndef BOOKING_H
#define BOOKING_H

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
#include <sstream>
namespace Ui {
class Booking;
}

class Booking : public QMainWindow
{
    Q_OBJECT

public:
    explicit Booking(QWidget *parent = nullptr,QMainWindow *menu=nullptr);
    ~Booking();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_seach_le_textChanged(const QString &arg1);

private:
    Ui::Booking *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow *menu;
};

#endif // BOOKING_H
