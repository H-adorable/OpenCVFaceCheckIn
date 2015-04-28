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
