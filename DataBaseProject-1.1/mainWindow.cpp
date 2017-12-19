#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "string"
#include "doctor.h"
#include "patientChoice.h"
#include "iostream"
#include "frameOfCreatingDoctor.h"
#include "QDir"
#include "QFile"

using namespace std;

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    if (!QDir("doctor").exists())
        QDir().mkdir("doctor");
    if (!QDir("patient").exists())
        QDir().mkdir("patient");
    if (!QFile("patient/allPatients.txt").exists())
    {
        QFile mFile("patient/allPatients.txt");
        mFile.open(QIODevice::WriteOnly);
        mFile.close();
        mFile.remove();
    }
    if (!QFile("doctor/allDoctors.txt").exists())
    {
        QFile mFile("doctor/allDoctors.txt");
        mFile.open(QIODevice::WriteOnly);
        mFile.close();
        mFile.remove();
    }
    addListOfDoctorsToComboBox();
}

void mainWindow::addListOfDoctorsToComboBox()
{
    ui->comboBox->clear();
    doctor<string> *t=new doctor<string>();
    QVector<string> listOfDoctors=t->loadList();
    cout<<"addListOfDoctorsToComboBox"<<endl;
    cout<<listOfDoctors.size()<<endl;
    for (int i=0; i<listOfDoctors.size(); i++)
    {
        //Случилась хрень
        QString str=QString::fromStdString(listOfDoctors.at(i));
        this->ui->comboBox->addItem(str);
    }
    cout<<ui->comboBox->count()<<endl;
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_pushButton_clicked()
//Подтвердить выбор
{
    patientChoice *q=new patientChoice();
    q->show();
}

void mainWindow::setValue()
{
    this->addListOfDoctorsToComboBox();
    this->setVisible(true);
}

void mainWindow::on_pushButton_2_clicked()
//Добавить профиль
{
    frameOfCreatingDoctor *q=new frameOfCreatingDoctor();
    QObject::connect(q, SIGNAL(), this, SLOT(setValue()));
    q->show();
    //this->setVisible(false);
}
