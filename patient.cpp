#include "patient.h"
#include "string"
#include "iostream"
#include "fstream"

using namespace std;

void patient::print()
{
    cout<<"Фамилия:         "<<surname<<endl;
    cout<<"Имя:             "<<name<<endl;
    cout<<"Отчество:        "<<patronymic<<endl;
    cout<<"Пол:             "<<sex<<endl;
    cout<<"Номер телефона:  "<<phoneNumber<<endl;
    cout<<"Почта:           "<<email<<endl;
    cout<<"День рождения:   "<<dateOfBirth<<endl;
    cout<<"Страховой полис: "<<medicalCard<<endl;
    cout<<"Адрес:           "<<adress<<endl;
}

string* patient::getDiagnosis()
{
    return diagnosis;
}

string* patient::getMasculine()
{
    return masculine;
}

bool patient::saveIntoFile()
{
    string mainPath, file;
    mainPath="\\" + surname + "_" + name + "_" + patronymic + "\\";
    file=mainPath+"mainInformation.txt";
    const char *cstr = file.c_str();
    ofstream out(cstr, ios_base::app);
    delete(cstr);
    time_t  timev;
    time(&timev);
    out << timev <<endl;
    out << surname << endl;
    out << name <<endl;
    out << patronymic <<endl;
    out << dateOfBirth <<endl;
    out << sex <<endl;
    out << phoneNumber <<endl;
    out << email <<endl;
    out << adress <<endl;
    out << medicalCard[0] << endl;
    out << medicalCard[1] <<endl;
    out.close();

    file=mainPath + "listOfPhotos.txt";
    for (int i=0; i<numberOfPhotos; i++)
        copyFile(linksToPhotos[i].c_str(), (mainPath + photo[i]).c_str());

    const char *cstr1 = file.c_str();
    ofstream out2(cstr1, ios_base::app);
    delete(cstr1);
    for (int i=0; i<numberOfPhotos; i++)
        out2<< photo[i] <<endl;
    out2.close();

    file=mainPath + "description.txt";
    const char *cstr2 = file.c_str();
    ofstream out3(cstr2, ios_base::app);
    delete(cstr2);
    for (int i=0; i<numberOfDescription; i++)
        out3 << description[i] << endl;
    out3.close();

    file=mainPath + "diagnosis.txt";
    const char *cstr3 = file.c_str();
    ofstream out4(cstr3, ios_base::app);
    delete(cstr3);
    for (int i=0; i<numberOfDiagnosis; i++)
        out4 << diagnosis[i] << endl;
    out4.close();

    file=mainPath + "masculine.txt";
    const char *cstr4 = file.c_str();
    ofstream out5(cstr4, ios_base::app);
    delete(cstr4);
    for (int i=0; i<numberOfMasculine; i++)
        out5 << masculine[i] << endl;
    out5.close();
}

void patient::setDiagnosis(string* diagnosis, int n)
{
    numberOfDiagnosis=n;
    for (int i=0;i<n;i++)
        this->diagnosis[i]=diagnosis[i];
}

void patient::setMasculine(string* masculine, int n)
{
    numberOfMasculine=n;
    for (int i=0;i<n;i++)
        this->masculine[i]=masculine[i];
}

bool patient::downloadFromFile(string fileName)
{
    string f3=fileName+"\mainInformation.txt";
    const char *cstr = f3.c_str();
    ifstream in(cstr);
    getline(in, lastEditing);
    getline(in, surname);
    getline(in, name);
    getline(in, patronymic);
    getline(in, dateOfBirth);
    in>>sex;
    getline(in, phoneNumber);
    getline(in, phoneNumber);
    getline(in, email);
    getline(in, adress);
    getline(in, medicalCard[0]);
    getline(in, medicalCard[1]);
    in.close();

    string f2=fileName+"\description.txt";
    const char *cstr2 = f2.c_str();
    ifstream in2(cstr2);
    delete(cstr2);
    numberOfDescription=0;
    while (!in2.eof())
    {
        numberOfDescription++;
        getline(in2, description[numberOfDescription-1]);
    }
    in2.close();

    string f1=fileName+"\description.txt";
    const char *cstr3 = f1.c_str();
    ifstream in3(cstr3);
    delete(cstr3);
    numberOfPhotos=0;
    while (!in3.eof())
    {
        numberOfPhotos++;
        getline(in3, photo[numberOfPhotos-1]);
    }
    in3.close();

    f1=fileName+"\diagnosis.txt";
    const char *cstr4 = f1.c_str();
    ifstream in4(cstr4);
    delete(cstr4);
    numberOfDiagnosis=0;
    while (!in4.eof())
    {
        numberOfDiagnosis++;
        getline(in4, photo[numberOfDiagnosis-1]);
    }
    in4.close();
}
