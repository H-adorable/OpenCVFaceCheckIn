#ifndef ADMINCHECK_H
#define ADMINCHECK_H

#include <QDialog>
#include <QString>

#include "environment.h"

namespace Ui {
class AdminCheck;
}

class AdminCheck : public QDialog
{
    Q_OBJECT

public:
    explicit AdminCheck(QWidget *parent = 0);
    ~AdminCheck();

public slots:
    void start(int);

    void reShow(int);

private slots:
    void on_password_returnPressed();

    void on_ok_clicked();

    void on_back_clicked();

    void on_close_clicked();

signals:
    void confirmed(int, QString);

    void refused(int, int, QString);

    void back(int);


private:
    Ui::AdminCheck *ui;

    QString password;
};

#endif // ADMINCHECK_H
