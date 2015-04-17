#ifndef ALERT_H
#define ALERT_H

#include <QDialog>
#include "information.h"

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
    // Start with code
    void start(int);



private:
    Ui::Alert *ui;

    // Alert information searcher
    Information info;

};

#endif // ALERT_H
