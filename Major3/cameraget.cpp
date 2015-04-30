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
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    // Connect so that camBack could show
    connect(timer1,
            SIGNAL(timeout()),
            this,
            SLOT(getCamera()));

    // Match
    connect(this,
            SIGNAL(getFace(cv::Mat)),
            this,
            SLOT(match()));

    // Catch face
    connect(timer2,
            SIGNAL(timeout()),
            this,
            SLOT(recordClient()));

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
    state = x;
    if(state == 1){
        // First 'tic' face detection do not use.
        tic = 20;
        // Initial nFaces
        nFaces = 1;
        ui->hint->setText("请面对摄像头并保持严肃");
        cap = cv::VideoCapture(0);
        timer1->start(20);
        //        emit camera(1);
    }
    else if(state == 6){
        // First 'tic' face detection do not use.
        tic = 100;
        // Initial nFaces
        nFaces = 1;

        ui->hint->setText("请面对摄像头并保持严肃");
        cap = cv::VideoCapture(0);
        timer2->start(20);
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
        // Initial nFaces
        nFaces = 0;
    }
}

void CameraGet::recordClient()
{
    // Convert number to 'string'
    //    std::string s = number.toStdString();
    bool isFace;
    // 'n' faces stored
    int n = 50;
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

    //    --tic;
    //    if(tic == 0){
    //        cv::imwrite(s+"face.jpg", faceBuffer);
    //    }

    if(isFace && tic != 0 && nFaces <= n){
        std::string fileName = "temp_" + (QString::number(nFaces)).toStdString() + ".jpg";
        if(cv::imwrite(fileName, faceBuffer)) qDebug() << "store success";
        --tic;
        ++nFaces;
    }
    else if(tic == 0 || nFaces > n){
        faceBuffer.release();
        cap.release();
        timer2->stop();
        close();
        emit showFaces(2, number);
    }
    else{
        --tic;
    }

}

void CameraGet::on_back_clicked()
{
    if(timer2->isActive())
        timer2->stop();
    if(timer1->isActive())
        timer1->stop();
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

            if(cv::imwrite("face5.bmp", faceBuffer)) qDebug() << "success";
            qDebug() << "getFace signal sent.(cameraGet)";
            emit getFace(faceBuffer);
        }
        else{
            faceBuffer.release();
            cap.release();
            timer1->stop();
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
        timer1->stop();
        ui->camBack->clear();
        close();
        qDebug() << "Camera closed.";
        emit confirmed(2, number);
        qDebug() << "Confirmed signal sent.(cameraGet)";

    }
    else{
        faceBuffer.release();
        cap.release();
        timer1->stop();
        ui->camBack->clear();
        close();
        qDebug() << "Camera closed.";
        emit refused(2, 1, number);
        qDebug() << "Refused signal sent.(cameraGet)";
    }
}
