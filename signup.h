#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>

namespace Ui {
class Signup;
}

class Signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr,QMainWindow *mw=0);
    ~Signup();

private slots:
    void on_pb4_clicked();

private:
    Ui::Signup *ui;
    QMainWindow *mw;
};

#endif // SIGNUP_H
