#-------------------------------------------------
#
# Project created by QtCreator 2015-04-15T16:38:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Major3
TEMPLATE = app


SOURCES += main.cpp\
        welcome.cpp \
    cameraget.cpp \
    face.cpp \
    authentication.cpp \
    admincheck.cpp \
    sqlitetool.cpp \
    administor.cpp \
    showfaces.cpp

HEADERS  += welcome.h \
    cameraget.h \
    face.h \
    authentication.h \
    admincheck.h \
    sqlitetool.h \
    environment.h \
    administor.h \
    showfaces.h

FORMS    += welcome.ui \
    cameraget.ui \
    authentication.ui \
    admincheck.ui \
    administor.ui \
    showfaces.ui

QT       += core \
            sql

INCLUDEPATH +=	C:\opencv\2.4.10_in_Qt\install\include\opencv\
                C:\opencv\2.4.10_in_Qt\install\include\opencv2\
                C:\opencv\2.4.10_in_Qt\install\include\

LIBS +=	C:\opencv\2.4.10_in_Qt\lib\libopencv_calib3d2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_contrib2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_core2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_features2d2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_flann2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_gpu2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_highgui2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_imgproc2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_legacy2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_ml2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_objdetect2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_video2410.dll.a\
        C:\opencv\2.4.10_in_Qt\lib\libopencv_nonfree2410.dll.a
