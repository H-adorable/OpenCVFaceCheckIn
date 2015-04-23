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
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(getCamera()));

    // Match
    connect(this,
            SIGNAL(getFace(cv::Mat)),
            this,
            SLOT(match()));

    // First 'tic' face detection do not use.
    tic = 20;

}

CameraGet::~CameraGet()
{
    cap.release();
    delete ui;
    qDebug() << "CameraGet delete.";
}

void CameraGet::start(int x, QString s)
{
    show();
    number = s;
    if(x == 1){
        ui->hint->setText("请面对摄像头并保持严肃");
        cap = cv::VideoCapture(0);
        timer->start(20);
//        emit camera(1);
    }
//    ulong n = 25*60*0.02;
//    for(ulong i=0; i<n; ++i)
    //        getCamera(0);
}

void CameraGet::reShow(int x)
{
    if(x == 2)
        show();
}

void CameraGet::on_back_clicked()
{
    timer->stop();
    cap.release();
    close();
    qDebug() << "Camera closed. Back sent";
    emit back(1);
}

void CameraGet::on_cancel_clicked()
{
    qDebug() << "Camera closed.";
    close();
}

void CameraGet::getCamera()
{
    bool isFace;
    // Get image
    cap >> cameraBuffer;

    // Detect wheather face exists
    isFace = face.detect(cameraBuffer,
                         faceBuffer,
                         cameraBuffer);

    // Show the camera feedback first
    cv::cvtColor(cameraBuffer, colorBuffer, CV_BGR2RGB);
    displayBuffer = QImage((const uchar*)(colorBuffer.data),
                           colorBuffer.cols,
                           colorBuffer.rows,
                           QImage::Format_RGB888);
    ui->camBack->setPixmap(QPixmap::fromImage(displayBuffer));

    cv::imshow( "face", faceBuffer );

    // If get a face send the signal.
    if(isFace && (!tic)){
//        if(cv::imwrite("face.bmp", faceBuffer)) qDebug() << "success";
        qDebug() << "getFace signal sent.(cameraGet)";
        emit getFace(faceBuffer);
    }
    else
        --tic;

//    QCoreApplication::processEvents();
}

void CameraGet::match()
{
    if(face.imgMatch(faceBuffer,
                     check.faceImg(number))){
        cap.release();
        timer->stop();
        close();
        qDebug() << "Camera closed.";
        emit confirmed(2, number);
        qDebug() << "Confirmed signal sent.(cameraGet)";

    }
    else{
        cap.release();
        timer->stop();
        close();
        qDebug() << "Camera closed.";
        emit refused(2, number);
        qDebug() << "Confirmed signal sent.(cameraGet)";
    }
}
