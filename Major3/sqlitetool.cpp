#include "sqlitetool.h"

#include <QDebug>
#include <iostream>

SQLiteTool::SQLiteTool()
{

}

SQLiteTool::~SQLiteTool()
{
    qDebug() << "check delete.";

}

bool SQLiteTool::isExist(QString x)
{
    bool flag = false;

    // Database connection
    QSqlDatabase clients;
    // Open a database
    clients = QSqlDatabase::database("FaceRec");
    clients.setDatabaseName(databaseLocation);
    if(clients.open()){
        qDebug() << "Opening database" << databaseLocation << " success.";

        // Search the table
        QSqlQuery query(clients);
        query.exec("SELECT id, name FROM client WHERE id == "+ x);
        flag = query.first();
    }
    else{
        qDebug() << "Opening database" << databaseLocation << " failed.";
        return false;
    }
    // Close a database
    clients.close();
    if(clients.isOpen())
        qDebug() << clients.connectionNames();
    else
        qDebug() << "close database";

    // If exist?
    if(flag){
        return true;
    }
    else{
        return false;
    }

}

std::string SQLiteTool::faceImg(QString n)
{
    // BGR image
    leave();
    return "face.bmp";



}

bool SQLiteTool::search(QString n, QImage &img, QString &name, QString &department, QString &position)
{
    bool flag = false;

    // Database connection
    QSqlDatabase clients;
    // Open a database
    clients = QSqlDatabase::database("FaceRec");
    clients.setDatabaseName(databaseLocation);
    if(clients.open()){
        qDebug() << "Opening database" << databaseLocation << " success.";

        // Search the table
        QSqlQuery query(clients);
        QString order = "SELECT id, name, department, position FROM client WHERE id = '"+ n + "';";
        qDebug() << order;
        query.exec(/*"SELECT id, name FROM client WHERE id = "+ n*/order);
        flag = query.next();
        name = query.value(1).toString();
        department = query.value(2).toString();
        position = query.value(3).toString();
    }
    else{
        qDebug() << "Opening database" << databaseLocation << " failed.";
        return false;
    }
    // Close a database
    clients.close();
    if(clients.isOpen())
        qDebug() << clients.connectionNames();
    else
        qDebug() << "close database";

    QString imageName = "../data/std_" + n + ".jpg";
    img.load(imageName);

    // If exist?
    if(flag){
        return true;
    }
    else{
        return false;
    }


    // Set the connection of database
//    begin();

//    if(n == "10"){
//        img = QImage();
//        name = "小白";
//        department = "学生会";
//        position = "主席";

//        // clean up the environment
//        leave();
//        return true;
//    }
//    leave();
//    return false;

}

bool SQLiteTool::addRow(QString n, QString name, QString department, QString positon)
{
    bool flag = false;
    // Database connection
    QSqlDatabase clients;
    // Open a database
    clients = QSqlDatabase::database("FaceRec");
    clients.setDatabaseName(databaseLocation);
    qDebug() << clients.connectionNames();
    bool ok = clients.open();
    if(ok){
        qDebug() << "Opening database" << databaseLocation << " success.";

        QSqlQuery query(clients);
        query.prepare("INSERT INTO client (id, name, department, position)"
                      "VALUES (:id, :name, :department, :position)");
        query.bindValue(":id", n);
        query.bindValue(":name", name);
        query.bindValue(":department", department);
        query.bindValue(":position", positon);
        flag = query.exec();

    }
    else{
        qDebug() << "Opening database" << databaseLocation << " failed.";
        return false;
    }


    // Close a database
    clients.close();
    qDebug() << "close database";
    if(flag){
        return true;
    }
    else
        return false;

}

bool SQLiteTool::initial()
{

    // Database connection
    QSqlDatabase clients;
    // Open a database
    clients = QSqlDatabase::addDatabase("QSQLITE", "FaceRec");
    clients.setDatabaseName(databaseLocation);
    if(clients.open()){

        // Close a database
        qDebug() << "Opening database" << databaseLocation << " success.";

        QSqlQuery q(clients);
        bool ok =q.exec("CREATE TABLE client("
                        "ID INT PRIMARY KEY NOT NULL,"
                        "NAME TEXT NOT NULL,"
                        "DEPARTMENT TEXT NOT NULL,"
                        "POSITION TEXT NOT NULL);");

        clients.close();
        if(ok){
            std::cout << "table created." << std::endl;
            return true;
        }
        else{
            std::cout << "table create failed." << std::endl;
            return false;
        }

    }
    else{
        qDebug() << "Opening database" << databaseLocation << " failed.";
        return false;
    }



}

bool SQLiteTool::leave()
{
    //    //    delete clients;
    //    if(clients.isOpen())
    //        qDebug() << clients.connectionNames();
    //    qDebug() << "close database";
    return true;
}

bool SQLiteTool::begin()
{
    //    clients.close();
    //    clients = QSqlDatabase::addDatabase("QSQLITE", "FaceRec");
    //    clients.setDatabaseName(databaseLocation);
    //    if(!clients.open()){
    //        qDebug() << "Opening database" << databaseLocation << " failed.";
    //        return false;
    //    }
    //    else{
    //        qDebug() << "Opening database" << databaseLocation << " success.";
    //        return true;
    //    }

}

