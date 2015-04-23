#include "alert.h"
#include "ui_alert.h"

#include <QDebug>

Alert::Alert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alert)
{
    ui->setupUi(this);
}

Alert::~Alert()
{
    qDebug() << "Alert delete.";
    delete ui;
}

void Alert::start(int x, int y, QString s)
{
    switch(x){
    // welcome : no body
    case 1: hint = s + "  不存在！"; break;
    // camera get
    case 2:
        //show = info.get(2);break;
        switch (y){
        // match failed
        case 1: hint = "验证失败！拒绝进入！"; break;
        // get face deadly failed
        case 2: hint = "没有发现人脸！"; break;
        default: break;
        }
        break;

    // admin check : wrong password
    case 5: hint = "授权码错误！请获得授权！"; break;
    // administor tools
    case 6:
        //show = info.get(6);break;
        switch(y){
        // not found
        case 1: hint = s + "  不存在！"; break;
        // exist already
        case 2: hint = s + "  已存在"; break;
        }
        break;
    default:
        hint = "我不应该出现";
    }
    ui->label->setText(hint);
    show();
}

void Alert::on_back_clicked()
{
    emit back(1);
    close();
}

void Alert::on_close_clicked()
{
    close();
}
