#include "patientChoice.h"
#include "ui_patientChoice.h"
#include "patient.h"
#include "iostream"
#include "frameOfCreatingPatient.h"

patientChoice::patientChoice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::patientChoice)
{
    ui->setupUi(this);
    ui->label->setHidden(true);
    patients=NULL;
    addListOfPatientsToComboBox();
}

void patientChoice::addListOfPatientsToComboBox()
{
    ui->comboBox->clear();
    patient<string> q;
    listOfPatients=q.loadList();

    cout<<"addlistofPAtients - list.size: "<<listOfPatients.size()<<endl;
    for (int i=0; i<listOfPatients.size(); i++)
    {
        //Случилась хрень
        QString str=QString::fromStdString(listOfPatients.at(i));
        this->ui->comboBox->addItem(str);
    }
    cout<<"addlistofPAtients - clear is to run"<<endl;
    patients->clear();
    cout<<"addlistofPAtients - cleared successfully"<<endl;
    patients=NULL;
    for (int i=0; i<listOfPatients.size(); i++)
    {
        q.downloadFromFile(listOfPatients[i]);
        patients=patients->addNode(q);
        cout<<"addlistofPAtients - patients->"<<patients<<endl;
    }
    patients->printTree(0);
    cout<<"addlistofPAtients - ended"<<endl;
}

patientChoice::~patientChoice()
{
    delete ui;
}

void patientChoice::setValue()
{
    this->addListOfPatientsToComboBox();
}

void patientChoice::on_pushButton_2_clicked()
{
    frameOfCreatingPatient *q=new frameOfCreatingPatient(this);
    QObject::connect(q, SIGNAL(destroyed(q)), this, SLOT(setValue()));
    q->show();
}

void patientChoice::on_pushButton_3_clicked()
{
    frameOfCreatingPatient *q=
            new frameOfCreatingPatient(
                static_cast<patient<string>*>
                (patients->findVisitorProb(listOfPatients
                                           [ui->comboBox->currentIndex()])));
    q->show();
}
