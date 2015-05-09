#ifndef SQLITETOOL_H
#define SQLITETOOL_H

#include <QString>
#include <QImage>
#include <QtSql>

#include <opencv2/core/core.hpp>
#include <highgui.h>
#include <nonfree/features2d.hpp>
//#include <nonfree/nonfree.hpp>
//#include "environment.h"

const QString databaseLocation = "../data/first.db";


class SQLiteTool
{
public:
    SQLiteTool();
    ~SQLiteTool();

    // True if number exist
    bool isExist(QString x);

    // Return stored face image location
    std::string faceImg(QString);

    // Retrun standard image location
    std::string img(QString);

    // SIFT feature of 'img', store in 'key' and 'descriptors'
    bool SIFTFeature(/*input*/  cv::Mat img,
                     /*output*/ std::vector<cv::KeyPoint> key, cv::Mat descriptors);

    // Detail information searcher
    bool search(/*input*/  QString n,
                /*output*/ QImage& img, QString &name, QString &department, QString &position);

    bool search(/*input*/  QString n,
                /*output*/ QString &name, QString &department, QString &position);

    bool search(/*input*/  QString n);

    // Add a row
    bool addRow(/*input*/ QString n, QString name, QString department, QString positon);

    // Delete a row
    bool deleteRow(QString n);

    // Update a row
    bool updateRow(/*input*/ QString n, QString name, QString department, QString positon);

    // Initialize, if there is no database, then build one
    bool initial();

private:
//    // Database connection
//    QSqlDatabase clients;

//    // When a method is complete, 'leave()' should be called
//    bool leave();

//    // When a method begins, 'begin()' should be called
//    bool begin();

    // Where the base and standrad image store
    QString header;

};

#endif // SQLITETOOL_H
