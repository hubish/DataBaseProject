#include "patient.h"
#include "string"
#include "iostream"
#include "fstream"
#include "QDir"
#include "QFile"

using namespace std;

template <typename T>
patient<T>::patient()
{
    this->surname = "No surname";
    this->name="No name";
    this->patronymic="No patronymic";
    this->sex="N";
    this->phoneNumber="No phoneNumber";
    this->email="No email";
    this->dateOfBirth="No dateOfBirth";
    this->medicalCard[0]="No medicalCard[0]";
    this->medicalCard[1]="No medicalCard[1]";
    this->adress="No adress";
    this->lastEditing= "No lastEditing";
    this->diagnosis="No diagnosis";
    this->masculine="No masculine";
}

template <typename T>
patient<T>::patient(patient *patient)
{
    surname = patient->surname;
    name=patient->name;
    patronymic=patient->patronymic;
    sex=patient->sex;
    phoneNumber=patient->phoneNumber;
    email=patient->email;
    dateOfBirth=patient->dateOfBirth;
    description=patient->description;
    medicalCard[0]=patient->medicalCard[0];
    medicalCard[1]=patient->medicalCard[1];
    adress=patient->adress;
    for (int i=0;i<patient->photos.size();i++)
    {
        photos.push_back(patient->photos[i]);
        linksToPhotos.push_back(patient->linksToPhotos[i]);
    }
    diagnosis=patient->diagnosis;
    masculine=patient->masculine;
    lastEditing=patient->lastEditing;
}

template <typename T>
patient<T>::patient(string surname, string name, string patronymic, string sex,
                    string phoneNumber, string email, string dateOfBirth,
                    string description, string medicalCard[2],
string adress,QVector<string> photos,
QVector<string> linksToPhotos, string diagnosis, string masculine)
{
    this->surname = surname;
    this->name=name;
    this->patronymic=patronymic;
    this->sex=sex;
    this->phoneNumber=phoneNumber;
    this->email=email;
    this->dateOfBirth=dateOfBirth;
    this->description=description;
    this->medicalCard[0]=medicalCard[0];
    this->medicalCard[1]=medicalCard[1];
    this->adress=adress;
    for (int i=0;i<photos.size();i++)
    {
        this->photos.push_back(photos[i]);
        this->linksToPhotos.push_back(linksToPhotos[i]);
    }
    this->diagnosis= diagnosis;
    this->masculine= masculine;
    this->lastEditing= lastEditing;
}

template <typename T>
string patient<T>::getDiagnosis()
{
    return diagnosis;
}

template <typename T>
string patient<T>::getMasculine()
{
    return masculine;
}

template <typename T>
void patient<T>::setDiagnosis(string diagnosis)
{
    this->diagnosis=diagnosis;
}

template <typename T>
void patient<T>::setMasculine(string masculine)
{
    this->masculine=masculine;
}

template <typename T>
void patient<T>::print()
{
    cout<<"Фамилия:         "<<surname<<endl;
    cout<<"Имя:             "<<name<<endl;
    cout<<"Отчество:        "<<patronymic<<endl;
    cout<<"Пол:             "<<sex<<endl;
    cout<<"Номер телефона:  "<<phoneNumber<<endl;
    cout<<"Почта:           "<<email<<endl;
    cout<<"День рождения:   "<<dateOfBirth<<endl;
    cout<<"Страховой полис: "<<medicalCard[0]<<endl;
    cout<<"Страховой полис: "<<medicalCard[1]<<endl;
    cout<<"Адрес:           "<<adress<<endl;
}

template <typename T>
QVector<T> patient<T>::loadList()
{
    QVector<T> somevector;

    ifstream infile;
    string s;
    QFile f("patient/allPatients.txt");
    if (f.exists())
    {
        infile.open("patient/allPatients.txt", ios::in | ios::binary);
        while (infile)
        {
            getline(infile, s);
            cout<<s<<endl;
            somevector.push_back(s);
        }
        infile.close();
        if (somevector.size()>0)
            somevector.remove(somevector.size()-1);
    }
    else
        cout<<"Нет файла"<<endl;
    return somevector;
}

template <typename T>
void patient<T>::arrayToFile(QVector<T> lst) //переносим из массива в файл
{
    QFile f("patient/allPatients.txt");
    if (f.exists())
    {
        ofstream outfile;
        outfile.open("patient/allPatients.txt", ios::out);
        if (!outfile) cout << "Ошибка, файл не найден" << endl;
        for (int i = 0; i < lst.size(); i++)
            outfile << lst.at(i) << endl;
        outfile.close();
    }
    else
    {
        QFile mFile("patient/allPatients.txt");
        mFile.open(QIODevice::WriteOnly);
        mFile.close();
        mFile.remove();

        ofstream outfile;
        outfile.open("patient/allPatients.txt", ios::out);
        if (!outfile) cout << "Ошибка, файл не найден" << endl;
        for (int i = 0; i < lst.size(); i++)
            outfile << lst.at(i) << endl;
        outfile.close();
    }
}

template <typename T>
bool patient<T>::addFIOToFile()
{
    QVector<string> lst;
    lst=loadList();
    if (lst.indexOf(surname+"_"+name+"_"+patronymic)==-1)
    {
        lst.push_back(surname+"_"+name+"_"+patronymic);
        sort(&lst);
        arrayToFile(lst);
        return true;
    }
    return false;

}

template <typename T>
bool patient<T>::saveIntoFile()
{
    if (!QDir("patient").exists())
        QDir().mkdir("patient");

    string mainPath, file;

    mainPath="patient/" + surname + "_" + name + "_" + patronymic;
    if (!QDir(QString::fromStdString(mainPath)).exists())
    {
        QDir().mkdir(QString::fromStdString(mainPath));
        file=mainPath+"/Information.txt";
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
        out << description << endl;
        out << diagnosis << endl;
        out << masculine << endl;
        out.close();

        string file2=mainPath + "/listOfPhotos.txt";
        for (int i=0; i<linksToPhotos.size(); i++)
            copyFile(linksToPhotos[i].c_str(),
                     (mainPath + "/" + photos[i]).c_str());

        cout<<"Size of photos: "<<photos.size()<<endl;
        const char *cstr1 = file2.c_str();
        ofstream out2(cstr1, ios_base::app);
        delete(cstr1);
        for (int i=0; i<photos.size(); i++)
            out2 << photos[i] << endl;
        out2.close();

        this->addFIOToFile();

        return true;
    }
    else
    {
        QDir().mkdir(QString::fromStdString(mainPath));
        file=mainPath+"/Information.txt";
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
        out << description << endl;
        out << diagnosis << endl;
        out << masculine << endl;
        out.close();

        string file2=mainPath + "/listOfPhotos.txt";
        for (int i=0; i<linksToPhotos.size(); i++)
            copyFile(linksToPhotos[i].c_str(),
                     (mainPath + "/" + photos[i]).c_str());

        cout<<"Size of photos: "<<photos.size()<<endl;
        const char *cstr1 = file2.c_str();
        ofstream out2(cstr1, ios_base::app);
        delete(cstr1);
        for (int i=0; i<photos.size(); i++)
            out2 << photos[i] << endl;
        out2.close();

        this->addFIOToFile();
        return true;
    }

}

template <typename T>
bool patient<T>::downloadFromFile(string fileName)
{
    if (QDir("patient").exists())
    {
        string s="patient/"+fileName;
        if (QDir(QString::fromStdString(s)).exists())
        {
            string f3=s+"/Information.txt";
            if (QFile(QString::fromStdString(f3)).exists())
            {
                const char *cstr = f3.c_str();
                ifstream in(cstr);
                getline(in, lastEditing);
                getline(in, surname);
                getline(in, name);
                getline(in, patronymic);
                getline(in, dateOfBirth);
                getline(in, sex);
                getline(in, phoneNumber);
                getline(in, email);
                getline(in, adress);
                getline(in, medicalCard[0]);
                getline(in, medicalCard[1]);
                getline(in, description);
                getline(in, diagnosis);
                getline(in, masculine);
                in.close();
            }
            else
            {
                this->surname="No surname";
                this->name="No name";
                this->patronymic="No patronymic";
                this->sex="N";
                this->phoneNumber="No phoneNumber";
                this->email="No email";
                this->dateOfBirth="No dateOfBirth";
                this->medicalCard[0]="No medicalCard[0]";
                this->medicalCard[1]="No medicalCard[1]";
                this->description=description;
                this->adress= "No adress";
                this->lastEditing= "No lastEditing";
                this->diagnosis="No diagnosis";
                this->masculine="No masculine";
            }

            string f1=s + "/listOfPhotos.txt";
            if (QFile(QString::fromStdString(f1)).exists())
            {
                const char *cstr3 = f1.c_str();
                ifstream in3(cstr3);
                delete(cstr3);
                while (!in3.eof())
                {
                    string sssss;
                    getline(in3, sssss);
                    photos.push_back(sssss);
                    linksToPhotos.push_back(s+"/"+sssss);
                }
                in3.close();
            }
            return true;
        }
    }
    return false;
}

template class patient<string>;
