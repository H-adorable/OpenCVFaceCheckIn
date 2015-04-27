#include "sqlitetool.h"

#include <QDebug>

SQLiteTool::SQLiteTool()
{
    clients = QSqlDatabase::addDatabase("QSQLITE");
    clients.setDatabaseName(databaseLocation);
    if(!clients.open()){
        qDebug() << "Opening database" << databaseLocation << " failed.";
//        clients.close();
    }

}

SQLiteTool::~SQLiteTool()
{
    qDebug() << "check delete.";
    clients.close();

}

bool SQLiteTool::isExist(QString)
{
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
    if(n == "10"){
        img = QImage();
        name = "小白";
        department = "学生会";
        position = "主席";
        leave();
        return true;
    }
    leave();
    return false;

}

bool SQLiteTool::leave()
{
    clients.close();
}

