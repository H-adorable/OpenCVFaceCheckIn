#include "cameraget.h"
#include "ui_cameraget.h"

#include <QDebug>

CameraGet::CameraGet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraGet)
//    check(databaseLocation)
{
    ui->setupUi(this);

//    check("./data/first.db");

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

}

CameraGet::~CameraGet()
{
    cap.release();
    delete ui;
    qDebug() << "CameraGet delete.";
}

void CameraGet::start(int x, QString s)
{
    // First 'tic' face detection do not use.
    tic = 20;

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
    if(x == 2){
        show();
        // First 'tic' face detection do not use.
        tic = 20;
    }
}

void CameraGet::recordClient()
{
    // Convert number to 'string'
    std::string s = number.toStdString();
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

    --tic;
    if(tic == 0){
        cv::imwrite(s+"face.jpg", faceBuffer);
    }


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

    cv::Mat grayFace;
    cv::Mat litghtBuffer;

//    cv::cvtColor(cameraBuffer, grayCamera, CV_BGR2GRAY);

//    // Do histogram equalization to decrease the infulence of light
//    cv::equalizeHist(grayCamera, litghtBuffer);

//    cv::imshow("dd", litghtBuffer);

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

    if(!faceBuffer.empty())
        cv::imshow( "face", faceBuffer );

    // If get a face send the signal.
    if(tic == 0){
        if(isFace){
            // Do histogram equalization to decrease the infulence of light
            cv::cvtColor( faceBuffer, grayFace, CV_BGR2GRAY );
            cv::resize( grayFace, faceBuffer, faceBuffer.size(), 0, 0, cv::INTER_LINEAR );
            cv::equalizeHist( faceBuffer, faceBuffer );

//            if(cv::imwrite("face5.bmp", faceBuffer)) qDebug() << "success";
            qDebug() << "getFace signal sent.(cameraGet)";
            emit getFace(faceBuffer);
        }
        else{
            faceBuffer.release();
            cap.release();
            timer->stop();
            close();
            qDebug() << "Camera closed.";
            emit noFace(2, 2, number);
            qDebug() << "noFace signal sent.(cameraGet)";
            ui->camBack->clear();
        }
    }
    else{
        --tic;
//        if(tic < 15)
//            emit getFace(faceBuffer);
    }
    std::cout << tic;

    //    QCoreApplication::processEvents();
}

void CameraGet::match()
{
    cv::Mat base = cv::imread(check.faceImg(number));
    if(face.imgMatch(faceBuffer,
                     base)){
        faceBuffer.release();
        cap.release();
        timer->stop();
        ui->camBack->clear();
        close();
        qDebug() << "Camera closed.";
        emit confirmed(2, number);
        qDebug() << "Confirmed signal sent.(cameraGet)";

    }
    else{
        faceBuffer.release();
        cap.release();
        timer->stop();
        ui->camBack->clear();
        close();
        qDebug() << "Camera closed.";
        emit refused(2, 1, number);
        qDebug() << "Refused signal sent.(cameraGet)";
    }
}
