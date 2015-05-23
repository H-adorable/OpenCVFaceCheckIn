#include "cameraget.h"
#include "ui_cameraget.h"

#include <QDebug>

// 'n' faces stored
const int nStore = 100;

// 'n' times to check
const int nCheck = 20;

CameraGet::CameraGet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraGet)
  //    check(databaseLocation)
{
    ui->setupUi(this);

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
        tic = nCheck;
        // Initial nFaces
        nFaces = 1;
        ui->hint->setText("请面对摄像头并保持严肃");
        cap = cv::VideoCapture(0);
        timer1->start(20);
        base = cv::imread("../data/base_" + number.toStdString() + ".bmp");
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

    if(isFace && tic != 0 && nFaces <= nStore){
        std::string fileName = "../data/temp/temp_" + (QString::number(nFaces)).toStdString() + ".bmp";
        if(cv::imwrite(fileName, faceBuffer)) qDebug() << "store success";
        --tic;
        ++nFaces;
    }
    else if(tic == 0 || nFaces > nStore){
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

//    if(!faceBuffer.empty())
//        cv::imshow( "face", faceBuffer );

    // If get a face send the signal.

    if(tic == 0){
        close();
        if(isFace){
//            // Do histogram equalization to decrease the infulence of light
//            cv::cvtColor( faceBuffer, grayFace, CV_BGR2GRAY );
//            cv::resize( grayFace, faceBuffer, faceBuffer.size(), 0, 0, cv::INTER_LINEAR );
//            cv::equalizeHist( faceBuffer, faceBuffer );

//            if(cv::imwrite("face5.bmp", faceBuffer)) qDebug() << "success";
//            qDebug() << "getFace signal sent.(cameraGet)";
//            emit getFace(faceBuffer);
        }
        else{
            faceBuffer.release();
            cap.release();
            timer1->stop();
            close();
            qDebug() << "Camera closed.";
//            emit noFace(2, 2, number);
            if(QMessageBox::information(this,
                                     "验证失败",
                                     "验证失败\n返回或关闭",
                                     "返回") == 0){
                emit back(1);
            }
            qDebug() << "noFace signal sent.(cameraGet)";
            ui->camBack->clear();
        }
    }
    else{
        --tic;
        if(tic < nCheck-10 && isFace)
            emit getFace(faceBuffer);
    }

//    std::cout << tic;

    //    QCoreApplication::processEvents();
}

void CameraGet::match()
{
    if(face.imgMatch(faceBuffer,
                     base)){
//    if(face.LoweMatch(base, faceBuffer)){
//    cv::Mat baseDescriptors = cv::imread("../data/base_key_" + number.toStdString() + ".bmp");
//    qDebug() << "load descriptors' channels = " << baseDescriptors.channels();
//    baseDescriptors.convertTo(baseDescriptors, CV_32F);
//    qDebug() << "load descriptors' type = " << baseDescriptors.type();
//    if(face.descriptorMatch(faceBuffer, baseDescriptors)){
//        faceBuffer.release();
//        cap.release();
//        timer1->stop();
//        ui->camBack->clear();
//        close();
//        qDebug() << "Camera closed.";
//        emit confirmed(2, number);
//        qDebug() << "Confirmed signal sent.(cameraGet)";

    }
    else if(tic != 0){
        ////
    }
    else{
        faceBuffer.release();
        cap.release();
        timer1->stop();
        ui->camBack->clear();
        close();
        qDebug() << "Camera closed.";
//        emit refused(2, 1, number);
        if(QMessageBox::critical(this,
                              "拒绝",
                              "验证失败，拒绝进入！",
                              "返回") == 0){
            on_back_clicked();
        }
        qDebug() << "Refused signal sent.(cameraGet)";
    }
}
