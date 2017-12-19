#ifndef PATIENTCHOICE_H
#define PATIENTCHOICE_H

#include <QMainWindow>
#include <QVector>
#include <patient.h>
#include <avlTree.h>
namespace Ui {
class patientChoice;
}

class patientChoice : public QMainWindow
{
    Q_OBJECT

public:
    explicit patientChoice(QWidget *parent = 0);
    ~patientChoice();
    void addListOfPatientsToComboBox();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void setValue();

private:
    Ui::patientChoice *ui;
    avlTree<human>* patients;
    QVector<string> listOfPatients;
};

#endif // PATIENTCHOICE_H
