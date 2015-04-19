#include "checklist.h"

CheckList::CheckList()
{

}

CheckList::~CheckList()
{

}

bool CheckList::isExist(QString)
{
    return true;

}

cv::Mat CheckList::faceImg(QString)
{
    return cv::Mat();

}

bool CheckList::search(QString n, QImage &img, QString &name, QString &department, QString &position)
{
    if(n == "10"){
        img = QImage();
        name = "小白";
        department = "学生会";
        position = "主席";
        return true;
    }
    return false;

}

