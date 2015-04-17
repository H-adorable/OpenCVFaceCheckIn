#ifndef CAMERAGET_H
#define CAMERAGET_H

#include <QDialog>
#include <QTime>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "face.h"

namespace Ui {
class CameraGet;
}

class CameraGet : public QDialog
{
    Q_OBJECT

public:
    explicit CameraGet(QWidget *parent = 0);
    ~CameraGet();

public slots:
    // Get the information and show it on the 'hint'
    void inform(QString);

    // Start with arguments
    void start(int, QString);

signals:
    // When 'Back' clicked
    void back(int);

    // When face detected, emit with face image
    void getFace(cv::Mat);

    // When face matchs, emit with number
    void confirmed(QString);

    // When face matching failed, emit with number
    void refused(QString);

private:
    Ui::CameraGet *ui;

    // Holds number got slot 'start (int, QString)'
    QString number;

    // Help to get & show the image
    QTimer *timer;

    // Camera Buffer
    cv::Mat cameraBuffer;

    // Display Buffer
    QImage displayBuffer;

    // Face recognization related algorithms
    Face face;

    // Camera cpture stream object
    cv::VideoCapture cap;

};

#endif // CAMERAGET_H
