#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QString>

#include <opencv2/core/core.hpp>
//#include <highgui.h>
#include <nonfree/features2d.hpp>
//#include <nonfree/nonfree.hpp>

class CheckList
{
public:
    CheckList();
    ~CheckList();

    // True if number exist
    bool isExist(QString);

    // Return stored face image
    cv::Mat img(QString);

    // SIFT feature of 'img', store in 'key' and 'descriptors'
    bool SIFTFeature(cv::Mat &img, std::vector<cv::KeyPoint> key, cv::Mat descriptors);

    // Detail information searcher
    bool search(QString n, cv::Mat &img, QString &name, QString &department, QString &position);

};

#endif // CHECKLIST_H
