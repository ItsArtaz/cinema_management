#ifndef ARCHIVE_H
#define ARCHIVE_H

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
namespace Ui {
class Archive;
}

class Archive : public QMainWindow
{
    Q_OBJECT

public:
    explicit Archive(QWidget *parent = nullptr,QMainWindow *menu = nullptr);
    ~Archive();

private slots:

    void on_seach_le_textChanged(const QString &arg1);

    void on_back_pb_clicked();

private:
    Ui::Archive *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QMainWindow *menu;
};

#endif // ARCHIVE_H
