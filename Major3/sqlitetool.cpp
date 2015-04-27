#include "sqlitetool.h"

#include <QDebug>

SQLiteTool::SQLiteTool()
{

}

SQLiteTool::~SQLiteTool()
{
    qDebug() << "check delete.";
    clients.close();

}

bool SQLiteTool::isExist(QString)
{
    // Set the connection of database
    begin();

    leave();
    return true;

}

std::string SQLiteTool::faceImg(QString)
{
    // BGR image
    leave();
    return "face.bmp";

}

bool SQLiteTool::search(QString n, QImage &img, QString &name, QString &department, QString &position)
{
    // Set the connection of database
    begin();

    if(n == "10"){
        img = QImage();
        name = "小白";
        department = "学生会";
        position = "主席";

        // clean up the environment
        leave();
        return true;
    }
    leave();
    return false;

}

bool SQLiteTool::leave()
{
    clients.close();
    return true;
}

bool SQLiteTool::begin()
{
    clients = QSqlDatabase::addDatabase("QSQLITE");
    clients.setDatabaseName(databaseLocation);
    if(!clients.open()){
        qDebug() << "Opening database" << databaseLocation << " failed.";
        return false;
    }
    else{
        qDebug() << "Opening database" << databaseLocation << " success.";
        return true;
    }

}

