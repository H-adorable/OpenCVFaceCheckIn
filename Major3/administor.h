#ifndef ADMINISTOR_H
#define ADMINISTOR_H

#include <QDialog>
#include <QString>

#include <sqlitetool.h>

namespace Ui {
class Administor;
}

class Administor : public QDialog
{
    Q_OBJECT

public:
    explicit Administor(QWidget *parent = 0);
    ~Administor();

private slots:
    void on_ok_clicked();

private:
    Ui::Administor *ui;

    // Line Editor contains
    QString id;
    QString name;
    QString department;
    QString position;

    // SQLite tool
    SQLiteTool check;

};

#endif // ADMINISTOR_H
