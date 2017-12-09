#include "frameToVeiwPhotos.h"
#include "ui_frameToVeiwPhotos.h"

frameToVeiwPhotos::frameToVeiwPhotos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frameToVeiwPhotos)
{
    //ui->setupUi(this);
}

frameToVeiwPhotos::~frameToVeiwPhotos()
{
    delete ui;
}

void frameToVeiwPhotos::setPhoto(std::string Fullname)
{
    ui->setupUi(this);
    Fullname=":"+Fullname;

    ui->label->setPixmap(QPixmap (Fullname.c_str()));
}
