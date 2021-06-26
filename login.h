#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <admin_panel.h>
#include <menu.h>
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
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr, QMainWindow *mw =nullptr);
    ~Login();

private slots:
    void on_back_btn_clicked();

    void on_continue_btn_clicked();

private:
    Ui::Login *ui;
    Admin_panel *admin_panel;
    Menu *menu;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow * mw;
};

#endif // LOGIN_H
