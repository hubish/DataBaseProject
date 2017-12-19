#ifndef FRAMEOFCREATINGPATIENT_H
#define FRAMEOFCREATINGPATIENT_H

#include <QMainWindow>
#include "QVector"
#include "string"
#include "patientChoice.h"
#include "patient.h"

using namespace std;

namespace Ui {
class frameOfCreatingPatient;
}

class frameOfCreatingPatient : public QMainWindow
{
    Q_OBJECT

public:
    explicit frameOfCreatingPatient(QWidget *parent = 0);
    explicit frameOfCreatingPatient(patient<string> *patient, QWidget *parent = 0);
    ~frameOfCreatingPatient();
    QVector<string> photos,links;
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::frameOfCreatingPatient *ui;
    patient<string> pat;
};

#endif // FRAMEOFCREATINGPATIENT_H

