/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QLabel *label;
    QLineEdit *lineIn;
    QPushButton *checkIn;
    QPushButton *administer;
    QPushButton *close;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QStringLiteral("Welcome"));
        Welcome->resize(500, 300);
        Welcome->setMinimumSize(QSize(500, 300));
        Welcome->setMaximumSize(QSize(500, 300));
        label = new QLabel(Welcome);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 400, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        label->setFont(font);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Sunken);
        label->setLineWidth(3);
        label->setMidLineWidth(3);
        label->setAlignment(Qt::AlignCenter);
        lineIn = new QLineEdit(Welcome);
        lineIn->setObjectName(QStringLiteral("lineIn"));
        lineIn->setGeometry(QRect(150, 170, 200, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(11);
        lineIn->setFont(font1);
        lineIn->setMouseTracking(false);
        lineIn->setFocusPolicy(Qt::StrongFocus);
        lineIn->setFrame(true);
        checkIn = new QPushButton(Welcome);
        checkIn->setObjectName(QStringLiteral("checkIn"));
        checkIn->setGeometry(QRect(200, 215, 100, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        checkIn->setFont(font2);
        checkIn->setFlat(false);
        administer = new QPushButton(Welcome);
        administer->setObjectName(QStringLiteral("administer"));
        administer->setGeometry(QRect(20, 260, 80, 25));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        administer->setFont(font3);
        close = new QPushButton(Welcome);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(400, 260, 80, 25));
        close->setFont(font3);

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "\346\254\242\350\277\216", 0));
        label->setText(QApplication::translate("Welcome", "\344\272\272\350\204\270\351\252\214\350\257\201", 0));
        checkIn->setText(QApplication::translate("Welcome", "\351\252\214\350\257\201", 0));
        administer->setText(QApplication::translate("Welcome", "\347\256\241\347\220\206\345\221\230", 0));
        close->setText(QApplication::translate("Welcome", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
