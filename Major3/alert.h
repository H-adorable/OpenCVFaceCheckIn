#ifndef ALERT_H
#define ALERT_H

#include <QDialog>
#include <string>
#include <iostream>

#include "environment.h"

namespace Ui {
class Alert;
}

class Alert : public QDialog
{
    Q_OBJECT

public:
    explicit Alert(QWidget *parent = 0);
    ~Alert();

public slots:
    // start the dialog
    void start(int x, int y, QString s);

signals:
    // when 'back' clicked
    void back(int);

private slots:
    void on_back_clicked();

    void on_close_clicked();

private:
    Ui::Alert *ui;

    // information to show
    QString hint;
};

#endif // ALERT_H
