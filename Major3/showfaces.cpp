#include "showfaces.h"
#include "ui_showfaces.h"

#include <QDebug>

const int nStore = 100;
ShowFaces::ShowFaces(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowFaces)
{
    ui->setupUi(this);

    // Image counter initialize, 20 pics show in totalS
    n = 20;

    // Page number initialize
    page = 0;

    // Initial picture labels array
    pic[0] = NULL;
    pic[1] = ui->p_1;
    pic[2] = ui->p_2;
    pic[3] = ui->p_3;
    pic[4] = ui->p_4;

    // Initial push puttoms array
    ok[0] = NULL;
    ok[1] = ui->ok_1;
    ok[2] = ui->ok_2;
    ok[3] = ui->ok_3;
    ok[4] = ui->ok_4;

    header = "../data/temp/temp_";
}

ShowFaces::~ShowFaces()
{
    delete ui;
}

void ShowFaces::start(int x, QString n)
{
    // Get info
    id = n;

    // Show first four images
    QImage b;
    QString filename;
    for(int i = 1; i <= 4; ++i){
        filename = header + QString::number(i + page) + ".bmp";
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
        QString oldFilename = header + QString::number(1 + page*4) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename)){
            ui->hint->setText("已选择第 1 张图像");
            if(newDes(newFilename))
                qDebug() << "Descriptors stored." ;
            clearTemps();
            goBack();
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
                    if(newDes(newFilename))
                        qDebug() << "Descriptors stored." ;
                    clearTemps();
                    goBack();
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
        QString oldFilename = header + QString::number(2 + page*4) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename)){
            ui->hint->setText("已选择第 2 张图像");
            if(newDes(newFilename))
                qDebug() << "Descriptors stored." ;
            clearTemps();
            goBack();
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
                    if(newDes(newFilename))
                        qDebug() << "Descriptors stored." ;
                    clearTemps();
                    goBack();
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
        QString oldFilename = header + QString::number(3 + page*4) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename)){
            ui->hint->setText("已选择第 3 张图像");
            if(newDes(newFilename))
                qDebug() << "Descriptors stored." ;
            clearTemps();
            goBack();
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
                    ui->hint->setText("已选择第 3 张图像");
                    if(newDes(newFilename))
                        qDebug() << "Descriptors stored." ;
                    clearTemps();
                    goBack();
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
        QString oldFilename = header + QString::number(4 + page*4) + ".bmp";
        QString newFilename = "../data/base_" + id + ".bmp";
        if(QFile::rename(oldFilename, newFilename)){
            ui->hint->setText("已选择第 4 张图像");
            if(newDes(newFilename))
                qDebug() << "Descriptors stored." ;
            clearTemps();
            goBack();
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
                    if(newDes(newFilename))
                        qDebug() << "Descriptors stored." ;
                    clearTemps();
                    goBack();
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
            filename = header + QString::number(i + page*4) + ".bmp";
            if(b.load(filename)){
                pic[i]->setPixmap(QPixmap::fromImage(b));
                ok[i]->setEnabled(true);
            }
            else{
                pic[i]->clear();
                ok[i]->setEnabled(false);
            }

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
    QImage b;
    QString filename;
    ++page;
    filename = header + QString::number(1 + page*4) + ".bmp";
    if(!b.load(filename)){
        --page;
        QMessageBox::critical(this,
                              "警告",
                              "这是最后一页！",
                              QMessageBox::Ok);
    }
    else{
        pic[1]->setPixmap(QPixmap::fromImage(b));
        for(int i = 2; i <= 4; ++i){
            filename = header + QString::number(i + page*4) + ".bmp";
            if(b.load(filename)){
                pic[i]->setPixmap(QPixmap::fromImage(b));
                ok[i]->setEnabled(true);
            }
            else{
                pic[i]->clear();
                ok[i]->setEnabled(false);
            }
        }
    }

}

void ShowFaces::on_back_clicked()
{
    if(QMessageBox::question(this,
                             "确认",
                             "放弃保存" + id + " 的所有信息并返回",
                             QMessageBox::Ok,
                             QMessageBox::Cancel) == QMessageBox::Ok){
        emit back(6);
        close();
        for(int i = 1; i <= 4; ++i){
            pic[i]->clear();
        }
        clearTemps();
        page = 0;
        check.deleteRow(id);
    }
}

bool ShowFaces::clearTemps()
{
    int flag = 2;
    for(int i = 1; i <= nStore && flag != 0; ++i){
        if(!QFile::remove(header + QString::number(i) + ".bmp")){
            --flag;
            qDebug() <<header + QString::number(i) + ".bmp 删除失败";
        }
        else
            qDebug() << header + QString::number(i) + ".bmp 已删除";
    }
    return true;
}

bool ShowFaces::goBack()
{
    if(QMessageBox::information(this,
                                "提示",
                                "保存"+id+"的基准图像成功！",
                                QMessageBox::Ok) == QMessageBox::Ok){
        emit back(6);
        close();
        return true;
    }
    return false;
}

bool ShowFaces::newDes(QString &filename)
{
    cv::Mat img = cv::imread(filename.toStdString(), CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat descriptors = face.generateDescriptors(img);
    std::string desName = "../data/base_key_" + id.toStdString() + ".bmp";
    if(cv::imwrite(desName, descriptors))
        return true;
    else
        return false;
}
