/*
    Dialog No. = 1
*/

#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

#include "checklist.h"

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();

public slots:
    // Re-show this welcome window
    void reShow(int);

signals:
    // Number is exist in the system
    void confirmed(int, QString);

    // Number is not sexist in the system
    void refused(int, QString);

    // Administor request into the system
    void administor(int);

private slots:
    void on_checkIn_clicked();

    void on_close_clicked();

    void on_lineIn_returnPressed();

private:
    Ui::Welcome *ui;

    // number holds the input number
    QString number;

    // CheckList class containing SQLite methods
    CheckList check;

    // Event Filter
//    bool eventFilter(QObject *, QEvent *);
};

#endif // WELCOME_H
