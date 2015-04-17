#ifndef FACE_H
#define FACE_H

#include <core/core.hpp>
#include <highgui.h>
#include <nonfree/features2d.hpp>
#include <nonfree/nonfree.hpp>

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
    bool detect(cv::Mat input, cv::Mat &cut, cv::Mat &draw);

    // Match two image of cut face
    bool imgMatch(cv::Mat, cv::Mat);

    // Match two image with keypoints
    bool keyMatch(cv::Mat, cv::Mat);

};

#endif // FACE_H
