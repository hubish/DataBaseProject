#include "frameOfCreatingDoctor.h"
#include "ui_frameOfCreatingDoctor.h"

frameOfCreatingDoctor::frameOfCreatingDoctor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frameOfCreatingDoctor)
{
    ui->setupUi(this);
}

frameOfCreatingDoctor::~frameOfCreatingDoctor()
{
    delete ui;
}
