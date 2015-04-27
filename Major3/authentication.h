/*
    Dialog No. = 3
*/

#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDialog>
#include "sqlitetool.h"
//#include "environment.h"

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
    // Start with argument
    void start(int x, QString n);

private slots:
    void on_close_clicked();

private:
    Ui::Authentication *ui;

    // Holds the number from 'start (QString)'
    QString number;

    // CheckList class containing SQLite methods
    SQLiteTool check;

    // Show the info of those who is authorised
    bool infoShow();

    // Standard image
    QImage standardFace;

    // Name
    QString name;

    // Department
    QString department;

    // Position
    QString position;

    // Result
    QString result;
};

#endif // AUTHENTICATION_H
