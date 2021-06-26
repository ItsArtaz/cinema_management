#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <user.h>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "QTimeEdit"
#include "QLabel"
#include "QDateEdit"
#include "QMessageBox"
namespace Ui {
class Signup;
}

class Signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr,QMainWindow *mw=nullptr);
    ~Signup();

private slots:
    void on_pb4_clicked();

    void on_pb3_clicked();

private:
    Ui::Signup *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow *mw;
};

#endif // SIGNUP_H
