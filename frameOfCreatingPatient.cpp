#include "frameOfCreatingPatient.h"
#include "ui_frameOfCreatingPatient.h"
#include "patient.h"
#include "QFileDialog"
#include "unistd.h"
#include "iostream"
#include "frameToVeiwPhotos.h"
#include "patient.h"

frameOfCreatingPatient::frameOfCreatingPatient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frameOfCreatingPatient)
{
    ui->setupUi(this);
}

frameOfCreatingPatient::frameOfCreatingPatient(
        patient<string> *pat, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frameOfCreatingPatient)
{
    ui->setupUi(this);
    this->pat=pat;

    ui->lineEdit->setText(QString::fromStdString(pat->getSurname()));
    ui->lineEdit_2->setText(QString::fromStdString(pat->getName())); //name
    ui->lineEdit_3->setText(QString::fromStdString(pat->getPatronymic()));//patro

    int curIndex;
    if (pat->getSex() == "M")
        curIndex = 1;
    else
        curIndex = 2;

    ui->comboBox->setCurrentIndex(curIndex);
    ui->lineEdit_4->setText(QString::fromStdString(pat->getPhoneNumber()));
    ui->lineEdit_7->setText(QString::fromStdString(pat->getEmail()));

    QString date_string_on_db = QString::fromStdString(pat->getDateOfBirth());
    QDate Date = QDate::fromString(date_string_on_db,"dd.mm.yy");

    ui->dateEdit->setDate(Date);
    ui->textEdit_2->setText(QString::fromStdString(pat->getDescription()));
    ui->lineEdit_5->setText(QString::fromStdString((pat->getMedicalCard())[0]));
    ui->lineEdit_6->setText(QString::fromStdString((pat->getMedicalCard())[1]));
    ui->textEdit_4->setText(QString::fromStdString(pat->getAdress()));
    for (int i=0;i<(pat->getPhotos()).size();i++)
        ui->comboBox_2->addItem(
                    QString::fromStdString((pat->getPhotos()).at(i)));
    ui->textEdit_3->setText(QString::fromStdString(pat->getDiagnosis()));
    ui->textEdit->setText(QString::fromStdString(pat->getMasculine()));
}

frameOfCreatingPatient::~frameOfCreatingPatient()
{
    delete ui;
}

void frameOfCreatingPatient::on_pushButton_4_clicked()
{
    this->destroy();
}

void frameOfCreatingPatient::on_pushButton_3_clicked()
{
    if (ui->lineEdit->text().length()!=0 &&
            ui->lineEdit_2->text().length()!=0)
    {
        string medicalCard[2];
        medicalCard[0] = ui->lineEdit_5->text().toStdString();
        medicalCard[1] = ui->lineEdit_6->text().toStdString();


        patient<string> q(ui->lineEdit->text().toStdString(), //surname
                          ui->lineEdit_2->text().toStdString(), //name
                          ui->lineEdit_3->text().toStdString(), //patro
                          ui->comboBox->currentText().toStdString(), //sex
                          ui->lineEdit_4->text().toStdString(), //number
                          ui->lineEdit_7->text().toStdString(), //email
                          ui->dateEdit->text().toStdString(), //date
                          ui->textEdit_2->toPlainText().toStdString(), //descr
                          medicalCard, // medical
                          ui->textEdit_4->toPlainText().toStdString(), //adress
                          photos, links, //
                          ui->textEdit_3->toPlainText().toStdString(),
                          ui->textEdit->toPlainText().toStdString());
        photos.clear();
        links.clear();
        q.print();
        q.saveIntoFile();
        this->destroy();
    }
}

void frameOfCreatingPatient::on_pushButton_2_clicked()
{
    if (ui->comboBox_2->currentIndex()>-1)
    {
        frameToVeiwPhotos* ui1=new frameToVeiwPhotos();
        ui1->setPhoto(links[ui->comboBox_2->currentIndex()]);
        ui1->show();
    }
}

void frameOfCreatingPatient::on_pushButton_clicked()
//adding a photo and its link
{
    QString str = QFileDialog::getOpenFileName(
                0, "Open Dialog", "", "*.png *.jpg"); //was txt
    //QString photoname = QFileDialog::selectedFiles();// !check for a validity

    string photopath = str.toStdString();
    const char *path = photopath.c_str();
    if(access(path, F_OK)!=-1) // !add a check for the validity!
    {
        //must be done after adding a photo in case
        //the input had been incorrect before
        ui->label_8->setText("Photo: ");
        photos.push_back(photopath);
        int index = photopath.rfind("/");
        string ssss="";
        for (int i=index+1; i<photopath.size(); i++) ssss+=photopath[i];

        links.push_back(ssss);
    }
    else
        ui->label_8->setText("Wrong path, try again");
}
