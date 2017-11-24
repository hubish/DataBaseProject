#ifndef FRAMEOFCREATINGPATIENT_H
#define FRAMEOFCREATINGPATIENT_H

#include <QMainWindow>

namespace Ui {
class frameOfCreatingPatient;
}

class frameOfCreatingPatient : public QMainWindow
{
    Q_OBJECT

public:
    explicit frameOfCreatingPatient(QWidget *parent = 0);
    ~frameOfCreatingPatient();

private:
    Ui::frameOfCreatingPatient *ui;
};

#endif // FRAMEOFCREATINGPATIENT_H
