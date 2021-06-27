#ifndef ADMIN_PANEL_H
#define ADMIN_PANEL_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QString>
#include "QTimeEdit"
#include "QLabel"
#include "QDateEdit"
#include "user.h"
#include "add_movie.h"
#include "delete_movie.h"
namespace Ui {
class Admin_panel;
}

class Admin_panel : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin_panel(QWidget *parent = nullptr,QMainWindow *mw=nullptr);
    ~Admin_panel();

private slots:
    void on_exit_btn_clicked();

    void on_add_btn_clicked();

    void on_delete_btn_clicked();

private:
    Ui::Admin_panel *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow *mw;
    Add_movie *add_movie;
    delete_movie *del_movie;
};

#endif // ADMIN_PANEL_H
