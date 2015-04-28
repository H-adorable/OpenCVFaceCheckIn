#include "welcome.h"
#include "cameraget.h"
#include "authentication.h"
#include "alert.h"
#include "admincheck.h"
#include "sqlitetool.h"

#include <QApplication>

int main(int argc, char *argv[])
{     

    QApplication a(argc, argv);

    SQLiteTool sq;
    sq.initial();
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("../data/first.db");
//    if(db.open())
//        std::cout << "dddddd" << std::endl;
//    db.close();

    Welcome w;
    CameraGet c;
    Authentication au;
    Alert al;
    AdminCheck ac;

    w.setWindowFlags(Qt::FramelessWindowHint);
    //    c.setWindowFlags(Qt::FramelessWindowHint);
    au.setWindowFlags(Qt::FramelessWindowHint);

    w.show();

    // Alert back to welcome all the time
    QObject::connect(&al, SIGNAL(back(int)), &w, SLOT(reShow(int)));

    // Connect welcome and cameraget
    QObject::connect(&w, SIGNAL(confirmed(int, QString)), &c, SLOT(start(int, QString)));
    QObject::connect(&c, SIGNAL(back(int)), &w, SLOT(reShow(int)));

    // Connect cameraget and authentication
    QObject::connect(&c, SIGNAL(confirmed(int, QString)), &au, SLOT(start(int, QString)));
    //    QObject::connect(&a, SIGNAL())

    // Connect everything and alert
    QObject::connect(&c, SIGNAL(noFace(int,int,QString)), &al, SLOT(start(int,int,QString)));
    QObject::connect(&c, SIGNAL(refused(int,int,QString)), &al, SLOT(start(int,int,QString)));
    QObject::connect(&ac, SIGNAL(refused(int,int,QString)), &al, SLOT(start(int,int,QString)));

    // Connect welcome and admincheck
    QObject::connect(&w, SIGNAL(administor(int)), &ac, SLOT(start(int)));
    QObject::connect(&ac, SIGNAL(back(int)), &w, SLOT(reShow(int)));

    return a.exec();
}
