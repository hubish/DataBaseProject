#include "viewOfPatient.h"
#include "ui_viewOfPatient.h"

viewOfPatient::viewOfPatient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewOfPatient)
{
    ui->setupUi(this);
}

viewOfPatient::~viewOfPatient()
{
    delete ui;
}
