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
    QString fileName = "face_" + n + ".bmp";
    return fileName.toStdString();



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
        if(flag){
            name = query.value(1).toString();
            department = query.value(2).toString();
            position = query.value(3).toString();
        }
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
}

bool SQLiteTool::search(QString n, QString &name, QString &department, QString &position)
{
    bool flag = false;

    // Database connection
    QSqlDatabase clients;
    // Open a database
    clients = QSqlDatabase::database("FaceRec");
    clients.setDatabaseName(databaseLocation);
    if(clients.open()){
        qDebug() << "Check-Opening database" << databaseLocation << " success.";

        // Search the table
        QSqlQuery query(clients);
        QString order = "SELECT id, name, department, position FROM client WHERE id = '"+ n + "';";
        qDebug() << order;
        query.exec(/*"SELECT id, name FROM client WHERE id = "+ n*/order);
        flag = query.next();
        if(flag){
            name = query.value(1).toString();
            department = query.value(2).toString();
            position = query.value(3).toString();
        }
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

bool SQLiteTool::search(QString n)
{
    bool flag = false;

    // Database connection
    QSqlDatabase clients;
    // Open a database
    clients = QSqlDatabase::database("FaceRec");
    clients.setDatabaseName(databaseLocation);
    if(clients.open()){
        qDebug() << "Check-Opening database" << databaseLocation << " success.";

        // Search the table
        QSqlQuery query(clients);
        QString order = "SELECT id, name, department, position FROM client WHERE id = '"+ n + "';";
        qDebug() << order;
        query.exec(/*"SELECT id, name FROM client WHERE id = "+ n*/order);
        flag = query.next();
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

bool SQLiteTool::deleteRow(QString n)
{
    // Database connection
    QSqlDatabase clients;
    bool flag;
    // Open a database
    clients = QSqlDatabase::addDatabase("QSQLITE", "FaceRec");
    clients.setDatabaseName(databaseLocation);
    if(clients.open()){

        // Close a database
        qDebug() << "Opening database" << databaseLocation << " success.";

        QSqlQuery q(clients);
        QString order = "DELETE FROM client WHERE id = '" + n + "';";
        qDebug() << order;
        flag = q.exec(order);
    }
    else{
        qDebug() << "Opening database" << databaseLocation << " failed.";
        return false;
    }
    // Close a database
    clients.close();
    qDebug() << "close database";
    if(flag){
        if(!search(n))
            return true;
    }
    else
        return false;
    return false;
}

bool SQLiteTool::updateRow(QString n, QString name, QString department, QString positon)
{
    // Database connection
    QSqlDatabase clients;
    bool flag;
    // Open a database
    clients = QSqlDatabase::addDatabase("QSQLITE", "FaceRec");
    clients.setDatabaseName(databaseLocation);
    if(clients.open()){

        // Close a database
        qDebug() << "Opening database" << databaseLocation << " success.";

        QSqlQuery q(clients);
        QString order = "UPDATE client SET name = '" + name
                + "', department = '" + department
                + "', position = '" + positon
                + "' WHERE id = '" + n + "';";
        qDebug() << order;
        flag = q.exec(order);
    }
    else{
        qDebug() << "Opening database" << databaseLocation << " failed.";
        return false;
    }
    // Close a database
    clients.close();
    qDebug() << "close database";
    if(flag){
        if(search(n, name, department, positon))
            return true;
    }
    else
        return false;
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



