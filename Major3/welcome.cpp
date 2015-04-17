#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);

    // Install the Event Filter on Line editor 'lineIn'
    ui->lineIn->installEventFilter(ui->lineIn);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::showAgain(int)
{

}

bool Welcome::eventFilter(QObject *obj, QEvent *event){
    // If 'lineIn' gets 'FocusIn' then clear it
    if(obj == ui->lineIn){
        if(event->type() == QEvent::FocusIn){
            qDebug() << "Line In cleared";
            ui->lineIn->clear();
            return true
        }
    }

    // The default solution
    else{
        return QObject::eventFilter(obj, event);
    }
}

void Welcome::on_checkIn_clicked()
{
    number = ui->lineIn->text();
    qDebug() << "get the number:\t" << number;
    if(check.isExist(number)){
        emit confirmed(number);
        qDebug() << "Confirmed signal sent";
        hide();
    }
    else{
        emit refused(number);
        qDebug() << "Refused signal sent";
        hide();
    }
}

void Welcome::on_close_clicked()
{
    close();
}
