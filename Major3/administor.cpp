#include "administor.h"
#include "ui_administor.h"

Administor::Administor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administor),
    isChecked(false)
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
        //        ui->id->clear();
        //        ui->name->clear();
        //        ui->department->clear();
        //        ui->position->clear();
    }

}



void Administor::on_back_clicked()
{
    clearAll();
    emit back(1);
}

void Administor::on_check_clicked()
{
    id = ui->id_2->text();

    // search database
    if(check.search(id, name, department, position)){
        ui->name_2->setText(name);
        ui->department_2->setText(department);
        ui->position_2->setText(position);
    }
    else{
        ui->hint->setText("此人不存在");
    }

}

void Administor::on_close_clicked()
{
    clearAll();
    close();
}

void Administor::on_id_2_returnPressed()
{
    emit ui->check->clicked();
}

void Administor::on_check_2_clicked()
{
    id = ui->id_3->text();

    // search database
    if(check.search(id, name, department, position)){
        ui->name_3->setText(name);
        ui->department_3->setText(department);
        ui->position_3->setText(position);

        // set state
        isChecked = true;
        QString hintText = "编号\t姓名\t部门\t职位\n"
                + id + "\t" + name + "\t" + department + "\t" + position + "\n已找到";
        ui->hint->setText(hintText);
    }
    else{
        ui->hint->setText("此人不存在");
    }
}

void Administor::on_ok_3_clicked()
{
    if(isChecked){
        isChecked = false;

        // Get input
        id = ui->id_3->text();
        name = ui->name_3->text();
        department = ui->department_3->text();
        position = ui->position_3->text();

        // update data
        if(check.updateRow(id, name, department, position)){
            QString hintText = "编号\t姓名\t部门\t职位\n"
                    + id + "\t" + name + "\t" + department + "\t" + position + "\n修改成功";
            ui->hint->setText(hintText);
            ui->id_3->clear();
            ui->name_3->clear();
            ui->department_3->clear();
            ui->position_3->clear();
        }
        else
            ui->hint->setText("修改失败！");
    }
    else
        ui->hint->setText("请先点击[查找]");
}

void Administor::clearAll()
{
    ui->hint->clear();

    ui->id->clear();
    ui->name->clear();
    ui->department->clear();
    ui->position->clear();

    ui->id_2->clear();
    ui->name_2->clear();
    ui->department_2->clear();
    ui->position_2->clear();

    ui->id_3->clear();
    ui->name_3->clear();
    ui->department_3->clear();
    ui->position_3->clear();

    ui->id_4->clear();
    ui->name_4->clear();
    ui->department_4->clear();
    ui->position_4->clear();
}

void Administor::on_check_3_clicked()
{
    id = ui->id_4->text();

    // search database
    if(check.search(id, name, department, position)){
        ui->name_4->setText(name);
        ui->department_4->setText(department);
        ui->position_4->setText(position);

        // set state
        isChecked = true;
        QString hintText = "编号\t姓名\t部门\t职位\n"
                + id + "\t" + name + "\t" + department + "\t" + position + "\n已找到";
        ui->hint->setText(hintText);
    }
    else{
        ui->hint->setText("此人不存在");
    }
}

void Administor::on_ok_4_clicked()
{
    if(isChecked){
        isChecked = false;

        // Get input
        id = ui->id_4->text();
        name = ui->name_4->text();
        department = ui->department_4->text();
        position = ui->position_4->text();

        // update data
        if(check.deleteRow(id)){
            QString hintText = "编号\t姓名\t部门\t职位\n"
                    + id + "\t" + name + "\t" + department + "\t" + position + "\n已删除";
            ui->hint->setText(hintText);
            ui->id_4->clear();
            ui->name_4->clear();
            ui->department_4->clear();
            ui->position_4->clear();
        }
        else
            ui->hint->setText("删除失败！");
    }
    else
        ui->hint->setText("请先点击[查找]");
}

void Administor::on_id_4_returnPressed()
{
    if(!isChecked)
        emit ui->check_3->clicked();
    else
        emit ui->ok_4->clicked();
}

void Administor::on_id_3_returnPressed()
{
    if(!isChecked)
        emit ui->check_2->clicked();
    else
        emit ui->ok_3->clicked();
}
