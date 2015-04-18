#include "welcome.h"
#include "cameraget.h"

#include <QApplication>

int main(int argc, char *argv[])
{     
    QApplication a(argc, argv);

    Welcome w;
    CameraGet c;

    w.show();

    QObject::connect(&w, SIGNAL(confirmed(int, QString)), &c, SLOT(start(int, QString)));
    QObject::connect(&c, SIGNAL(back(int)), &w, SLOT(showAgain(int)));
    return a.exec();
}
