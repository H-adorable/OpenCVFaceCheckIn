#include "cameraget.h"
#include "ui_cameraget.h"

CameraGet::CameraGet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraGet)
{
    ui->setupUi(this);
}

CameraGet::~CameraGet()
{
    delete ui;
}
