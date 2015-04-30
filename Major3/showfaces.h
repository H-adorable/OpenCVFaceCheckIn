#ifndef SHOWFACES_H
#define SHOWFACES_H

#include <QDialog>
#include <QImage>

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
    void start(int, QString);

private:
    Ui::ShowFaces *ui;
};

#endif // SHOWFACES_H
