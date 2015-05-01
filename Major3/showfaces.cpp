#include "showfaces.h"
#include "ui_showfaces.h"

ShowFaces::ShowFaces(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowFaces)
{
    ui->setupUi(this);

    // Image counter initialize, 20 pics show in totalS
    n = 20;

    // Page number initialize
//    page = 0;
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
    QLabel* pic[5] = {NULL, ui->p_1, ui->p_2, ui->p_3, ui->p_4};
    QString filename;
    for(int i = 1; i <= 4; ++i){
        filename = "temp_" + QString::number(i) + ".bmp";
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
        QString oldFilename = "temp_" + QString::number(1 + page) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename))
            ui->hint->setText("已选择第 1 张图像");
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
        QString oldFilename = "temp_" + QString::number(2 + page) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename))
            ui->hint->setText("已选择第 2 张图像");
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
        QString oldFilename = "temp_" + QString::number(3 + page) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename))
            ui->hint->setText("已选择第 3 张图像");
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
        QString oldFilename = "temp_" + QString::number(4 + page) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename))
            ui->hint->setText("已选择第 4 张图像");
    }
    else
        ui->hint->setText("您取消了保存操作");
}

void ShowFaces::on_close_clicked()
{
    close();
}
