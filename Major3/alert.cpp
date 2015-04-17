#include "alert.h"
#include "ui_alert.h"

Alert::Alert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alert)
{
    ui->setupUi(this);
}

Alert::~Alert()
{
    delete ui;
}
