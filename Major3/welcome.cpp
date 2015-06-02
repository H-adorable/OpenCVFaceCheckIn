#include "welcome.h"
#include "ui_welcome.h"

#include <QDebug>

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);

    // Initialize 'check with database location;
//    check(databaseLocation);


    // Install the Event Filter on Line editor 'lineIn'
    //    ui->lineIn->installEventFilter(ui->lineIn);
    //    ui->lineIn->setPlaceholderText("请输入编号");
    qDebug() << "Welcome born.";
}

Welcome::~Welcome()
{
    delete ui;
    qDebug() << "Welcome delete.";
}

// Show Welcome dialog again
void Welcome::reShow(int x)
{   
    // 1 = CameraGet, 2 = Authentication, 3 = Alert
    //    ui->lineIn->setText("请输入编号");
    //    show();
    if(x == 1){
        show();
    }
}

//bool Welcome::eventFilter(QObject *obj, QEvent *event){
//    // If 'lineIn' gets 'FocusIn' then clear it
//    if(obj == ui->lineIn){
//        if(event->type() == QEvent::FocusIn){
//            qDebug() << "Line In cleared";
//            ui->lineIn->clear();
//            return true;
//        }
//    }

//    // The default solution
//    else{
//        return QObject::eventFilter(obj, event);
//    }
//}

void Welcome::on_checkIn_clicked()
{
    number = ui->lineIn->text();
    ui->lineIn->clear();
    qDebug() << "get the number:\t" << number;
    if(check.isExist(number)){
        close();
        qDebug() << "Welcome closed.";
        emit confirmed(1, number);
        qDebug() << "Confirmed signal sent.(welcome)";
    }
    else{
        QMessageBox::information(this,
                                 "提示",
                                 "该编号不存在！",
                                 "返回");
//        emit refused(1, number);
//        qDebug() << "Refused signal sent.";
//        close();
//        qDebug() << "Welcome closed.";

    }
}

void Welcome::on_close_clicked()
{
    close();
}

void Welcome::on_lineIn_returnPressed()
{
    emit ui->checkIn->clicked();
}

void Welcome::on_administer_clicked()
{
    emit administor(5);
    close();
}
