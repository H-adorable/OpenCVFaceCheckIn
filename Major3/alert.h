#ifndef ALERT_H
#define ALERT_H

#include <QDialog>

namespace Ui {
class Alert;
}

class Alert : public QDialog
{
    Q_OBJECT

public:
    explicit Alert(QWidget *parent = 0);
    ~Alert();

private:
    Ui::Alert *ui;
};

#endif // ALERT_H
