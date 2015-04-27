#ifndef ADMINISTOR_H
#define ADMINISTOR_H

#include <QDialog>

namespace Ui {
class Administor;
}

class Administor : public QDialog
{
    Q_OBJECT

public:
    explicit Administor(QWidget *parent = 0);
    ~Administor();

private:
    Ui::Administor *ui;
};

#endif // ADMINISTOR_H
