#include "welcome.h"
#include "cameraget.h"
#include "authentication.h"

#include <QApplication>

int main(int argc, char *argv[])
{     
    QApplication a(argc, argv);

    Welcome w;
    CameraGet c;
    Authentication au;

    w.setWindowFlags(Qt::FramelessWindowHint);
//    c.setWindowFlags(Qt::FramelessWindowHint);
    au.setWindowFlags(Qt::FramelessWindowHint);

    w.show();

    // Connect welcome and cameraget
    QObject::connect(&w, SIGNAL(confirmed(int, QString)), &c, SLOT(start(int, QString)));
    QObject::connect(&c, SIGNAL(back(int)), &w, SLOT(reShow(int)));

    // Connect cameraget and authentication
    QObject::connect(&c, SIGNAL(confirmed(int, QString)), &au, SLOT(start(int, QString)));
//    QObject::connect(&a, SIGNAL())

    return a.exec();
}
