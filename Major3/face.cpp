#include "face.h"

Face::Face()
{

}

Face::~Face()
{

}

bool Face::detect(cv::Mat input, cv::Mat &cut, cv::Mat &draw)
{
    cut = input;
    draw = input;

}

