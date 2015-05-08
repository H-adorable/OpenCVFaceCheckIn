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

public slots:
    void start(int, QString);

    void reShow(int);

private slots:
    void on_ok_clicked();

    void on_back_clicked();

    void on_check_clicked();

    void on_close_clicked();

    void on_id_2_returnPressed();

    void on_check_2_clicked();

    void on_ok_3_clicked();

    void on_check_3_clicked();

    void on_ok_4_clicked();

    void on_id_4_returnPressed();

    void on_id_3_returnPressed();

signals:
    void back(int);

    void catchFace(int, QString);

private:
    Ui::Administor *ui;

    // Clear labels and lineeditors
    void clearAll();

    // Line Editor contains
    QString id;
    QString name;
    QString department;
    QString position;

    // SQLite tool
    SQLiteTool check;

    // state flag
    // check before update
    bool isChecked;

};

#endif // ADMINISTOR_H
