/********************************************************************************
** Form generated from reading UI file 'authentication.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICATION_H
#define UI_AUTHENTICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Authentication
{
public:
    QPushButton *close;
    QLabel *standardImage;
    QWidget *infoBox;
    QLabel *name;
    QLabel *department;
    QLabel *position;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line;
    QLabel *result;

    void setupUi(QDialog *Authentication)
    {
        if (Authentication->objectName().isEmpty())
            Authentication->setObjectName(QStringLiteral("Authentication"));
        Authentication->resize(700, 400);
        close = new QPushButton(Authentication);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(580, 340, 100, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        close->setFont(font);
        standardImage = new QLabel(Authentication);
        standardImage->setObjectName(QStringLiteral("standardImage"));
        standardImage->setGeometry(QRect(50, 50, 150, 180));
        standardImage->setFrameShape(QFrame::Box);
        infoBox = new QWidget(Authentication);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(300, 50, 300, 210));
        name = new QLabel(infoBox);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 20, 150, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        name->setFont(font1);
        department = new QLabel(infoBox);
        department->setObjectName(QStringLiteral("department"));
        department->setGeometry(QRect(130, 90, 150, 40));
        department->setFont(font1);
        position = new QLabel(infoBox);
        position->setObjectName(QStringLiteral("position"));
        position->setGeometry(QRect(130, 160, 150, 40));
        position->setFont(font1);
        label = new QLabel(infoBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 100, 40));
        label->setFont(font);
        label_2 = new QLabel(infoBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 100, 40));
        label_2->setFont(font);
        label_3 = new QLabel(infoBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 160, 100, 40));
        label_3->setFont(font);
        line_2 = new QFrame(infoBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 60, 280, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(infoBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 130, 280, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(infoBox);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 200, 280, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line = new QFrame(Authentication);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 290, 680, 10));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::HLine);
        result = new QLabel(Authentication);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(40, 320, 300, 40));
        result->setFont(font1);

        retranslateUi(Authentication);

        QMetaObject::connectSlotsByName(Authentication);
    } // setupUi

    void retranslateUi(QDialog *Authentication)
    {
        Authentication->setWindowTitle(QApplication::translate("Authentication", "\351\211\264\346\235\203\347\273\223\346\236\234", 0));
        close->setText(QApplication::translate("Authentication", "\345\205\263\351\227\255", 0));
        standardImage->setText(QString());
        name->setText(QApplication::translate("Authentication", "No", 0));
        department->setText(QApplication::translate("Authentication", "No", 0));
        position->setText(QApplication::translate("Authentication", "No", 0));
        label->setText(QApplication::translate("Authentication", "\345\247\223\345\220\215", 0));
        label_2->setText(QApplication::translate("Authentication", "\351\203\250\351\227\250", 0));
        label_3->setText(QApplication::translate("Authentication", "\350\201\214\344\275\215", 0));
        result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Authentication: public Ui_Authentication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICATION_H
