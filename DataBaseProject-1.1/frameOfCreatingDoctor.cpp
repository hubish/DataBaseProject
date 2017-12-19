#include "frameOfCreatingDoctor.h"
#include "ui_frameOfCreatingDoctor.h"
#include "doctor.h"
#include "unistd.h" //access (file checks)
#include "QFileDialog"
#include "frameToVeiwPhotos.h"
#include "iostream"
#include "mainWindow.h"

using namespace std;
frameOfCreatingDoctor::frameOfCreatingDoctor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frameOfCreatingDoctor)
{
    ui->setupUi(this);
}

frameOfCreatingDoctor::~frameOfCreatingDoctor()
{
    cout<<"fac"<<endl;
    delete ui;
}

void frameOfCreatingDoctor::on_pushButton_4_clicked()
{
    this->destroy();
}

void frameOfCreatingDoctor::on_pushButton_3_clicked()
{
    if (ui->lineEdit->text().length()!=0 &&
            ui->lineEdit_2->text().length()!=0)
    {
        string medicalCard[2];
        medicalCard[0] = ui->lineEdit_7->text().toStdString();
        medicalCard[1] = ui->lineEdit_8->text().toStdString();
        doctor<string> q(ui->lineEdit->text().toStdString(), //surname
                         ui->lineEdit_2->text().toStdString(), //name
                         ui->lineEdit_3->text().toStdString(), //patro
                         ui->comboBox->currentText().toStdString(), //sex
                         ui->lineEdit_4->text().toStdString(), //number
                         ui->lineEdit_5->text().toStdString(), //email
                         ui->dateEdit->text().toStdString(), //date
                         ui->textEdit->toPlainText().toStdString(), //descr
                         medicalCard, // medical
                         ui->textEdit_4->toPlainText().toStdString(), //adress
                         photos, links, //
                         ui->comboBox_3->currentText().toStdString(), //status
                         ui->textEdit_2->toPlainText().toStdString(), //exp
                         ui->lineEdit_6->text().toStdString()); //occupation
        q.print();
        bool f=q.saveIntoFile();
        photos.clear();
        links.clear();
        this->destroy();
    }
}

void frameOfCreatingDoctor::on_pushButton_clicked()
//adding a photo and its link
{
    QString str = QFileDialog::getOpenFileName(
                0, "Open Dialog", "", "*.png *.jpg");

    string photopath = str.toStdString();
    const char *path = photopath.c_str();
    if(access(path, F_OK)!=-1) // !add a check for the validity!
    {
        //must be done after adding a photo in case
        //the input had been incorrect before
        ui->label_8->setText("Photo: ");
        links.push_back(photopath);
        cout<<"push_back"<<endl;
        int index = photopath.rfind("/");
        string ssss="";
        for (int i=index+1; i<photopath.size(); i++) ssss+=photopath[i];
        cout<<"valid copy "<<ssss<<endl;
        ui->comboBox_2->addItem(QString::fromStdString(ssss));

        photos.push_back(ssss);
        cout<<photos.size()<<endl;
    }
    else
        ui->label_8->setText("Wrong path, try again");
}

void frameOfCreatingDoctor::on_pushButton_2_clicked()
{
    cout<<ui->comboBox_2->currentIndex()<<endl;
    if (ui->comboBox_2->currentIndex()>-1)
    {
        frameToVeiwPhotos* ui1=new frameToVeiwPhotos();
        ui1->setPhoto(links[ui->comboBox_2->currentIndex()]);
        ui1->show();
    }
}
