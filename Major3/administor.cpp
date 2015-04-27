#include "administor.h"
#include "ui_administor.h"

Administor::Administor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administor)
{
    ui->setupUi(this);
}

Administor::~Administor()
{
    delete ui;
}
