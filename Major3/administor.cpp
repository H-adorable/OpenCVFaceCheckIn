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

void Administor::on_ok_clicked()
{
    id = ui->id->text();
    name = ui->name->text();
    department = ui->department->text();
    position = ui->position->text();

    if(check.isExist(id))
        ui->hint->setText("已存在，添加失败");
    else{
        if(check.addRow(id, name, department, position))
            ui->hint->setText("添加成功");
        else
            ui->hint->setText("添加失败");
    }

}
