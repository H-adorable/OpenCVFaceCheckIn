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
    if(ui->password->text() == password){
        emit confirmed(5, "");
        ui->password->clear();
        close();
    }
    else{
        qDebug() << "Administor check failed.";
        if(QMessageBox::critical(this,
                              "警告",
                              "验证码错误！",
                              QMessageBox::Close) == QMessageBox::Close){
            ui->password->clear();
            emit back(1);
            close();
        }
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
