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


void Authentication::start(int x, QString n)
{
    number = n;
    show();
    if(check.search(number,
                    standardFace,
                    name,
                    department,
                    position)){
//        emit accepted();
        infoShow();
    }
    else{
        qDebug() << "reject";
        ui->result->setText("Rejection");
        emit rejected();
    }
}

bool Authentication::infoShow()
{
    // Search the database for detail information

        result = "Admission";
        // Show the information
        ui->result->setText(result);
        ui->name->setText(name);
        ui->department->setText(department);
        ui->position->setText(position);

//        QImage img;
//        img.load("../data/coffee.PNG");
//        ui->standardImage->setPixmap(QPixmap::fromImage(img));

        return true;

//        result = "Rejection";
//        ui->result->setText(result);
//        return false;
//    };

}

void Authentication::on_close_clicked()
{
    qDebug() << "Authentication closed.";
    close();
}
