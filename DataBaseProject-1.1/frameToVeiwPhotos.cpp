#include "frameToVeiwPhotos.h"
#include "ui_frameToVeiwPhotos.h"
#include "iostream"

using namespace std;

frameToVeiwPhotos::frameToVeiwPhotos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frameToVeiwPhotos)
{
    ui->setupUi(this);
}

frameToVeiwPhotos::~frameToVeiwPhotos()
{
    delete ui;
}

void frameToVeiwPhotos::setPhoto(std::string Fullname)
{
    QImage myImage;
    myImage.load(QString::fromStdString(Fullname));

    ui->label->setPixmap(QPixmap::fromImage(myImage));

    ui->label->show();
}
