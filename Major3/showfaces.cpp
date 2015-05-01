#include "showfaces.h"
#include "ui_showfaces.h"

#include <QDebug>

ShowFaces::ShowFaces(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowFaces)
{
    ui->setupUi(this);

    // Image counter initialize, 20 pics show in totalS
    n = 20;

    // Page number initialize
    page = 0;

    pic[0] = NULL;
    pic[1] = ui->p_1;
    pic[2] = ui->p_2;
    pic[3] = ui->p_3;
    pic[4] = ui->p_4;
}

ShowFaces::~ShowFaces()
{
    delete ui;
}

void ShowFaces::start(int x, QString n)
{
    // Get info
    //    id = n;

    // Show first four images
    QImage b;
    QString filename;
    for(int i = 1; i <= 4; ++i){
        filename = "temp_" + QString::number(i + page) + ".bmp";
        if(b.load(filename))
            pic[i]->setPixmap(QPixmap::fromImage(b));
    }

    // Set hint
    ui->hint->setText("点击数字键选取图像。\t注意光照，人像角度和表情");

    show();
}

void ShowFaces::on_ok_1_clicked()
{
    if(QMessageBox::question(this,
                             "确认",
                             "是否选择第 1 张图像？",
                             QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok){
        QString oldFilename = "temp_" + QString::number(1 + page*4) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename)){
            ui->hint->setText("已选择第 1 张图像");
            clearTemps();
        }
        else{
            if(QMessageBox::question(this,
                                     "确认",
                                     "此用户已有基准图片，是否更新？",
                                     QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok){
                QFile f(newFilename);
                f.remove();
                f.close();
                if(QFile::rename(oldFilename, newFilename)){
                    ui->hint->setText("已选择第 1 张图像");
                    clearTemps();
                }
                else{
                    ui->hint->setText("失败");
                }
            }
            else
                ui->hint->setText("您取消了保存操作");

        }
    }
    else
        ui->hint->setText("您取消了保存操作");
}

void ShowFaces::on_ok_2_clicked()
{
    if(QMessageBox::question(this,
                             "确认",
                             "是否选择第 2 张图像？",
                             QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok){
        QString oldFilename = "temp_" + QString::number(2 + page*4) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename)){
            ui->hint->setText("已选择第 2 张图像");
            clearTemps();
        }
        else{
            if(QMessageBox::question(this,
                                     "确认",
                                     "此用户已有基准图片，是否更新？",
                                     QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok){
                QFile f(newFilename);
                f.remove();
                f.close();
                if(QFile::rename(oldFilename, newFilename)){
                    ui->hint->setText("已选择第 2 张图像");
                    clearTemps();
                }
                else{
                    ui->hint->setText("失败");
                }
            }
            else
                ui->hint->setText("您取消了保存操作");

        }
    }
    else
        ui->hint->setText("您取消了保存操作");
}

void ShowFaces::on_ok_3_clicked()
{
    if(QMessageBox::question(this,
                             "确认",
                             "是否选择第 3 张图像？",
                             QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok){
        QString oldFilename = "temp_" + QString::number(3 + page*4) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename)){
            ui->hint->setText("已选择第 3 张图像");
            clearTemps();
        }
        else{
            if(QMessageBox::question(this,
                                     "确认",
                                     "此用户已有基准图片，是否更新？",
                                     QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok){
                QFile f(newFilename);
                f.remove();
                f.close();
                if(QFile::rename(oldFilename, newFilename)){
                    ui->hint->setText("已选择第 1 张图像");
                    clearTemps();
                }
                else{
                    ui->hint->setText("失败");
                }
            }
            else
                ui->hint->setText("您取消了保存操作");

        }
    }
    else
        ui->hint->setText("您取消了保存操作");
}

void ShowFaces::on_ok_4_clicked()
{
    if(QMessageBox::question(this,
                             "确认",
                             "是否选择第 4 张图像？",
                             QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok){
        QString oldFilename = "temp_" + QString::number(4 + page*4) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename)){
            ui->hint->setText("已选择第 4 张图像");
            clearTemps();
        }
        else{
            if(QMessageBox::question(this,
                                     "确认",
                                     "此用户已有基准图片，是否更新？",
                                     QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok){
                QFile f(newFilename);
                f.remove();
                f.close();
                if(QFile::rename(oldFilename, newFilename)){
                    ui->hint->setText("已选择第 4 张图像");
                    clearTemps();
                }
                else{
                    ui->hint->setText("失败");
                }
            }
            else
                ui->hint->setText("您取消了保存操作");

        }
    }
    else
        ui->hint->setText("您取消了保存操作");
}

void ShowFaces::on_close_clicked()
{
    close();
}

void ShowFaces::on_fomer_clicked()
{
    if(page > 0){
        --page;

        // Show these four images
        QImage b;
        QString filename;
        for(int i = 1; i <= 4; ++i){
            filename = "temp_" + QString::number(i + page*4) + ".bmp";
            if(b.load(filename))
                pic[i]->setPixmap(QPixmap::fromImage(b));
        }
    }
    else
        QMessageBox::critical(this,
                              "警告",
                              "这是第一页！",
                              QMessageBox::Ok);
}

void ShowFaces::on_latter_clicked()
{
    QFile f("temp_" + QString::number(1 + page*4) + ".bmp");
    if(f.isOpen()){
        ++page;

        // Show these four images
        QImage b;
        QString filename;
        for(int i = 1; i <= 4; ++i){
            filename = "temp_" + QString::number(i + page*4) + ".bmp";
            if(b.load(filename))
                pic[i]->setPixmap(QPixmap::fromImage(b));
        }
    }
    else
        QMessageBox::critical(this,
                              "警告",
                              "这是最后一页！",
                              QMessageBox::Ok);
}

void ShowFaces::on_back_clicked()
{
    emit back(7);
    close();
    for(int i = 1; i <= 4; ++i){
        pic[i]->clear();
    }
    page = 0;
}

bool ShowFaces::clearTemps()
{
    int flag = 2;
    for(int i = 1; i < 50 && flag != 0; ++i){
        if(!QFile::remove("temp_" + QString::number(i) + ".bmp")){
            --flag;
            qDebug() <<"temp_" + QString::number(i) + ".bmp 删除失败";
        }
        else
            qDebug() << "temp_" + QString::number(i) + ".bmp 已删除";
    }
    return true;
}
