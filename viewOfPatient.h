#ifndef VIEWOFPATIENT_H
#define VIEWOFPATIENT_H

#include <QMainWindow>

namespace Ui {
class viewOfPatient;
}

class viewOfPatient : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewOfPatient(QWidget *parent = 0);
    ~viewOfPatient();

private:
    Ui::viewOfPatient *ui;
};

#endif // VIEWOFPATIENT_H
