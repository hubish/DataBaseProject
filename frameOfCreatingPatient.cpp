#include "frameOfCreatingPatient.h"
#include "ui_frameOfCreatingPatient.h"

frameOfCreatingPatient::frameOfCreatingPatient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frameOfCreatingPatient)
{
    ui->setupUi(this);
}

frameOfCreatingPatient::~frameOfCreatingPatient()
{
    delete ui;
}
