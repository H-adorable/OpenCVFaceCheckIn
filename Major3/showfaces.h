#ifndef SHOWFACES_H
#define SHOWFACES_H

#include <QDialog>
#include <QImage>
#include <QFile>
#include <QMessageBox>
#include <QString>

namespace Ui {
class ShowFaces;
}

class ShowFaces : public QDialog
{
    Q_OBJECT

public:
    explicit ShowFaces(QWidget *parent = 0);
    ~ShowFaces();

public slots:
    void start(int x, QString n);

private slots:
    void on_ok_1_clicked();

    void on_ok_2_clicked();

    void on_ok_3_clicked();

    void on_ok_4_clicked();

    void on_close_clicked();

private:
    Ui::ShowFaces *ui;

    // Image counter
    int n;

    // Image container

    // Page
    int page;

    // client's id
    QString id;
};

#endif // SHOWFACES_H
