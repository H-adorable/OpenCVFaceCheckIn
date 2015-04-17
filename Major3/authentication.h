#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDialog>
#include "checklist.h"

namespace Ui {
class Authentication;
}

class Authentication : public QDialog
{
    Q_OBJECT

public:
    explicit Authentication(QWidget *parent = 0);
    ~Authentication();

public slots:
    // Start without argument
    void start(QString);

private:
    Ui::Authentication *ui;

    // Holds the number from 'start (QString)'
    QString number;

    // CheckList class containing SQLite methods
    CheckList check;
};

#endif // AUTHENTICATION_H
