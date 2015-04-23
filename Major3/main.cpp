#include "welcome.h"
#include "cameraget.h"
#include "authentication.h"
#include "alert.h"

#include <QApplication>

int main(int argc, char *argv[])
{     
    QApplication a(argc, argv);

    Welcome w;
    CameraGet c;
    Authentication au;
    Alert al;

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

    // Connect cameraget and alert
    QObject::connect(&c, SIGNAL(noFace(int,int,QString)), &al, SLOT(start(int,int,QString)));

    return a.exec();
}
