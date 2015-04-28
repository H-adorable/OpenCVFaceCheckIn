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

void Administor::start(int, QString)
{
    show();
}

void Administor::reShow(int)
{
    ui->hint->clear();
    show();

}

void Administor::on_ok_clicked()
{
    id = ui->id->text();
    name = ui->name->text();
    department = ui->department->text();
    position = ui->position->text();

    if(check.isExist(id))
        ui->hint->setText("已存在，添加失败");
    else{
        if(check.addRow(id, name, department, position)){
            QString hintText = "编号\t姓名\t部门\t职位\n"
                    + id + "\t" + name + "\t" + department + "\t" + position + "\n添加成功";
            ui->hint->setText(hintText);
            emit catchFace(6, id);
            close();
        }
        else
            ui->hint->setText("添加失败");
        ui->id->clear();
        ui->name->clear();
        ui->department->clear();
        ui->position->clear();
    }

}

void Administor::on_pushButton_2_clicked()
{
    close();
}

void Administor::on_back_clicked()
{
    emit back(1);
}
