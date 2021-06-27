#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QString>
#include "QTimeEdit"
#include "QLabel"
#include "QDateEdit"
#include "user.h"
#include "archive.h"
namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr,QMainWindow *mw=nullptr);
    ~Menu();

private slots:
    void on_exit_btn_clicked();

    void on_archive_btn_clicked();

private:
    Ui::Menu *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    Archive *archive;
    QMainWindow *mw;
};

#endif // MENU_H
