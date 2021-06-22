#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr, QMainWindow *mw =0);
    ~Login();

private slots:
    void on_back_btn_clicked();

private:
    Ui::Login *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow * mw;
};

#endif // LOGIN_H
