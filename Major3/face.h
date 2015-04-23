#ifndef FACE_H
#define FACE_H

#include <core/core.hpp>
#include <highgui/highgui.hpp>
#include <nonfree/features2d.hpp>
#include <nonfree/nonfree.hpp>
#include <imgproc/imgproc.hpp>
#include <objdetect/objdetect.hpp>

#include <cctype>
#include <iostream>
#include <iterator>
#include <stdio.h>

class Face
{
public:
    Face();
    ~Face();

    // Detect & cut the face of input
    cv::Mat detectCut(cv::Mat);

    // Detect & draw the face of input
    cv::Mat detectDraw(cv::Mat);

    // Detect then cut out face and draw a circle around face
    bool detect(cv::Mat input, cv::Mat &cut, cv::Mat draw);

    // Match two image of cut face
    bool imgMatch(cv::Mat, cv::Mat);

    // Match two image with keypoints
    bool keyMatch(cv::Mat, cv::Mat);

private:
    std::string cascadeName;
    float matchThreshold;
    float judgeThreshold;

    // Detect and draw
    bool detectAndDraw(cv::Mat img,
                       cv::Mat &faceSlice,
                       cv::CascadeClassifier& cascade,
                       cv::CascadeClassifier& nestedCascade,
                       double scale,
                       bool tryflip);

};

#endif // FACE_H
