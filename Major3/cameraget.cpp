#include "cameraget.h"
#include "ui_cameraget.h"

#include <QDebug>

CameraGet::CameraGet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraGet)
{
    ui->setupUi(this);

    // Timer to control the rate of camera capture (?)
    timer = new QTimer(this);

    // Connect so that camBack could show
//    connect(this,
//            SIGNAL(camera(int)),
//            this,
//            SLOT(getCamera(int)));
}

CameraGet::~CameraGet()
{
    cap.release();
    delete ui;
}

void CameraGet::start(int x, QString s)
{
    number = s;
    if(x == 1){
        ui->hint->setText("请面对摄像头并保持严肃");
        cap = cv::VideoCapture(0);
//        timer->start(33);
//        emit camera(1);
        show();
    }
//    ulong n = 25*60*0.02;
//    for(ulong i=0; i<n; ++i)
//        getCamera(0);
}

void CameraGet::on_back_clicked()
{
    close();
    qDebug() << "Camera closed. Back sent";
    emit back(1);
}

void CameraGet::on_cancel_clicked()
{
    qDebug() << "Camera closed.";
    close();
}

void CameraGet::getCamera(int)
{
    // Get image
    cap >> cameraBuffer;

    face.detect(cameraBuffer, faceBuffer, cameraBuffer);
    cv::cvtColor(cameraBuffer, cameraBuffer, CV_BGR2RGB);
    displayBuffer = QImage((const uchar*)(cameraBuffer.data),
                           cameraBuffer.cols,
                           cameraBuffer.rows,
                           QImage::Format_RGB888);
    ui->camBack->setPixmap(QPixmap::fromImage(displayBuffer));

    QCoreApplication::processEvents();

    // Send the signal
//    emit camera(2);
}
