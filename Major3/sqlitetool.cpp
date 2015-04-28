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

bool SQLiteTool::isExist(QString x)
{
    // Set the connection of database
    begin();
    QSqlQuery query(clients);
    query.exec("SELECT id, name FROM client WHERE id == "+ x);

    bool flag = query.first();
    leave();

    if(flag){
        return true;
    }
    else{
        return false;
    }
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

bool SQLiteTool::addRow(QString n, QString name, QString department, QString positon)
{
    begin();
    QSqlQuery query;
    query.prepare("INSERT INTO client (id, name, department, position)"
                  "VALUES (:id, :name, :department, :position)");
    query.bindValue(":id", n);
    query.bindValue(":name", name);
    query.bindValue(":department", department);
    query.bindValue(":position", positon);
    if(!query.exec()){
        leave();
        return false;
    }
    if(isExist(n)){
        leave();
        return true;
    }
    else{
        leave();
        return false;
    }
}

bool SQLiteTool::initial()
{
    if(begin()){
        leave();
        return true;
    }
    else{
        leave();
        return false;
    }
}

bool SQLiteTool::leave()
{
    //    delete clients;
    clients.close();
    if(clients.isOpen())
        qDebug() << clients.connectionNames();
    qDebug() << "free database";
    return true;
}

bool SQLiteTool::begin()
{
    clients.close();
    clients = QSqlDatabase::addDatabase("QSQLITE", "FaceRec");
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

