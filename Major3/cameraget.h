/*
    Dialog No. = 2
*/

#ifndef CAMERAGET_H
#define CAMERAGET_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>
#include <core/core.hpp>
#include <highgui/highgui.hpp>
#include <imgproc/imgproc.hpp>
#include <string>

#include "face.h"
#include "sqlitetool.h"



using namespace std;

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
//    void inform(QString);

    // Start with arguments
    void start(int, QString);

    // Re-show the dialog
    void reShow(int x);

signals:
    // When 'Back' clicked
    void back(int);

    // When face detected, emit with face image
    void getFace(cv::Mat);

    // When face matchs, emit with number
    void confirmed(int, QString);

    // When face matching failed, emit with number
    void refused(int, int, QString);

    // When 1 frame processed
    void camera(int);

    // When no face detected
    void noFace(int, int, QString);

    // When get 10 faces
    void showFaces(int, QString);

private slots:
    void on_back_clicked();

    void on_cancel_clicked();

    // Show the feed back of camera
    void getCamera();

    // process the match
    void match();

    // Record client's face
    void recordClient();

private:
    Ui::CameraGet *ui;

    // Holds number got slot 'start (int, QString)'
    QString number;

    // Help to get & show the image
    QTimer *timer1;
    QTimer *timer2;

    // Camera Buffer
    cv::Mat cameraBuffer;

    // Color change Buffer
    cv::Mat colorBuffer;

    // Display Buffer
    QImage displayBuffer;

    // Face recognization related algorithms
    Face face;

    // Database checking related algorithm
    SQLiteTool check;

    // Face image
    cv::Mat faceBuffer;

    // Camera cpture stream object
    cv::VideoCapture cap;

    // First 'tic' face detection do not use.
    int tic;

    // Match or catch
    int state;

    // The number of faces camera gets
    int nFaces;

    // Base image
    cv::Mat base;

};

#endif // CAMERAGET_H
