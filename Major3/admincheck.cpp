#include "admincheck.h"
#include "ui_admincheck.h"

#include <QDebug>

AdminCheck::AdminCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminCheck)
{
    ui->setupUi(this);
    password = "10";
}

AdminCheck::~AdminCheck()
{
    delete ui;
}

void AdminCheck::start(int)
{
    show();
}

void AdminCheck::reShow(int x)
{
    if(x == 5)
        show();
}

void AdminCheck::on_password_returnPressed()
{
    emit ui->ok->clicked();
}

void AdminCheck::on_ok_clicked()
{
//    qDebug() << ui->password->text();

    if(ui->password->text() == password){
        emit confirmed(5, "");
        close();
    }
    else{
        qDebug() << "Administor check failed.";
        emit refused(5, 0, "");
        close();
    }
}

void AdminCheck::on_back_clicked()
{
    emit back(1);
    close();
}

void AdminCheck::on_close_clicked()
{
    close();
}
