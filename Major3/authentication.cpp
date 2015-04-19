#include "authentication.h"
#include "ui_authentication.h"

#include <QDebug>

Authentication::Authentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authentication)
{
    ui->setupUi(this);
}

Authentication::~Authentication()
{
    qDebug() << "Authentication delete";
    delete ui;
}

void Authentication::start(QString x)
{
    number = x;
    show();
    if(infoShow())
        emit accepted();
    else
        emit rejected();
}

bool Authentication::infoShow()
{
    // Search the database for detail information
    if(check.search(number,
                 standardFace,
                 name,
                 department,
                 position)){
        result = "Admission";
        // Show the information
        ui->result->setText(result);
        ui->name->setText(name);
        ui->department->setText(department);
        ui->position->setText(position);
        return true;
    }
    else{
        result = "Rejection";
        ui->result->setText(result);
        return false;
    };

}

void Authentication::on_close_clicked()
{
    qDebug() << "Authentication closed.";
    close();
}
