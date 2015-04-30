#include "showfaces.h"
#include "ui_showfaces.h"

ShowFaces::ShowFaces(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowFaces)
{
    ui->setupUi(this);
}

ShowFaces::~ShowFaces()
{
    delete ui;
}

void ShowFaces::start(int, QString)
{
    QImage b;
    b.load("temp_1.jpg");
//    ui->p1->setPixmap(QPixmap::fromImage(displayBuffer));
    show();
//    close();
}
