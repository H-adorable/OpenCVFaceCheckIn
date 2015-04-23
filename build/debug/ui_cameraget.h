/********************************************************************************
** Form generated from reading UI file 'cameraget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAGET_H
#define UI_CAMERAGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CameraGet
{
public:
    QLabel *hint;
    QLabel *camBack;
    QPushButton *back;
    QPushButton *cancel;

    void setupUi(QDialog *CameraGet)
    {
        if (CameraGet->objectName().isEmpty())
            CameraGet->setObjectName(QStringLiteral("CameraGet"));
        CameraGet->resize(700, 700);
        CameraGet->setMinimumSize(QSize(700, 700));
        CameraGet->setMaximumSize(QSize(700, 700));
        hint = new QLabel(CameraGet);
        hint->setObjectName(QStringLiteral("hint"));
        hint->setGeometry(QRect(100, 50, 500, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        hint->setFont(font);
        hint->setFrameShape(QFrame::WinPanel);
        hint->setFrameShadow(QFrame::Sunken);
        hint->setLineWidth(1);
        hint->setAlignment(Qt::AlignCenter);
        camBack = new QLabel(CameraGet);
        camBack->setObjectName(QStringLiteral("camBack"));
        camBack->setGeometry(QRect(30, 120, 640, 480));
        camBack->setFrameShape(QFrame::Box);
        camBack->setLineWidth(2);
        camBack->setAlignment(Qt::AlignCenter);
        back = new QPushButton(CameraGet);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(30, 650, 100, 40));
        cancel = new QPushButton(CameraGet);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(590, 650, 100, 40));

        retranslateUi(CameraGet);

        QMetaObject::connectSlotsByName(CameraGet);
    } // setupUi

    void retranslateUi(QDialog *CameraGet)
    {
        CameraGet->setWindowTitle(QApplication::translate("CameraGet", "\346\215\225\350\216\267", 0));
        hint->setText(QString());
        camBack->setText(QString());
        back->setText(QApplication::translate("CameraGet", "\350\277\224\345\233\236", 0));
        cancel->setText(QApplication::translate("CameraGet", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class CameraGet: public Ui_CameraGet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAGET_H
