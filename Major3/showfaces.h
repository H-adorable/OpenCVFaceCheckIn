#ifndef SHOWFACES_H
#define SHOWFACES_H

#include <QDialog>
#include <QImage>
#include <QFile>
#include <QMessageBox>
#include <QProgressDialog>
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

    void on_fomer_clicked();

    void on_latter_clicked();

    void on_back_clicked();

signals:
    void back(int n);

private:
    Ui::ShowFaces *ui;

    // Image counter
    int n;

    // Image container

    // Page
    int page;

    // client's id
    QString id;

    // Array of image lable, pic[0] = NULL
    QLabel* pic[5];

    // Delete other temp Images;
    bool clearTemps();

    // File Header
    QString header;

    // Get face success
    bool goBack();
};

#endif // SHOWFACES_H
