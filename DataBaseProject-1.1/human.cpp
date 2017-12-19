#include "human.h"
#include "string"
#include "iostream"
#include "fstream"
#include "string.h"
#include "QDir"
#include "QFile"

using namespace std;

human::human()
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
}

human::human(human* human)
{
    surname=human->surname;
    name=human->name;
    patronymic=human->patronymic;
    phoneNumber=human->phoneNumber;
    email=human->email;
    dateOfBirth=human->dateOfBirth;
    medicalCard[0]=human->medicalCard[0];
    medicalCard[1]=human->medicalCard[1];
    adress=human->adress;
    description=human->description;
    sex=human->sex;
    for (int i=0;i<human->photos.size();i++)
        photos.push_back(human->photos[i]);
    lastEditing=human->lastEditing;
}

human::human(string surname, string name, string patronymic,
             string sex, string phoneNumber, string email,
             string dateOfBirth, string description,
             string medicalCard[2], string adress, QVector<string> photos,
             QVector<string> linksToPhotos)
{
    this->surname=surname;
    this->name=name;
    this->patronymic=patronymic;
    this->sex=sex;
    this->phoneNumber=phoneNumber;
    this->email=email;
    this->dateOfBirth=dateOfBirth;
    this->medicalCard[0]=medicalCard[0];
    this->medicalCard[1]=medicalCard[1];
    this->description=description;
    this->adress=adress;
    for (int i=0; i<photos.size(); i++)
    {
        this->photos.push_back(photos[i]);
        this->linksToPhotos.push_back(linksToPhotos[i]);
    }
    this->lastEditing=lastEditing;
}

bool human::saveIntoFile()
{
    if (!QDir("human").exists())
        QDir().mkdir("human");

    string mainPath, file;

    mainPath="human/" + surname + "_" + name + "_" + patronymic;
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
        out.close();

        file=mainPath + "/listOfPhotos.txt";
        for (int i=0; i<linksToPhotos.size(); i++)
            copyFile(linksToPhotos[i].c_str(), (mainPath + photos[i]).c_str());

        const char *cstr1 = file.c_str();
        ofstream out2(cstr1, ios_base::app);
        delete(cstr1);
        for (int i=0; i<photos.size(); i++)
            out2<< photos[i] <<endl;
        out2.close();


        this->addFIOToFile();
        return true;
    }
    return false;
}

bool human::downloadFromFile(string fileName)
{
    if (QDir("human").exists())
    {
        string s="human/"+fileName;
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

void human::copyFile(const char* srce_file, const char* dest_file )
{
    std::ifstream srce( srce_file, std::ios::binary ) ;
    std::ofstream dest( dest_file, std::ios::binary ) ;
    dest << srce.rdbuf() ;
}

void human::setPhoto(string name, string fullPath)
{
    photos.push_back(name);
    linksToPhotos.push_back(fullPath);
}

void human::setDescription(string description)
{
    this->description=description;
}

void human::setMedicalCard(string* medicalCard)
{
    this->medicalCard[0]=medicalCard[0];
    this->medicalCard[1]=medicalCard[1];
}

void human::setAdress(string adress)
{
    this->adress=adress;
}

string human::getSurname()
{
    return surname;
}

string human::getName()
{
    return name;
}

string human::getPatronymic()
{
    return patronymic;
}

string human::getPhoneNumber()
{
    return phoneNumber;
}

string human::getEmail()
{
    return email;
}

string human::getDateOfBirth()
{
    return dateOfBirth;
}

string human::getDescription()
{
    return description;
}

string* human::getMedicalCard()
{
    return medicalCard;
}

string human::getAdress()
{
    return adress;
}

QVector<string> human::getPhotos()
{
    return photos;
}

QVector<string> human::getLinksToPhotos()
{
    return linksToPhotos;
}

string human::getSex()
{
    return sex;
}

void human::print()
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

QVector<string> human::loadList()
{
    QVector<string> somevector;
    ifstream infile;
    string s;
    QFile f("human/allHumans.txt");
    if (f.exists())
    {
        infile.open("human/allHumans.txt", ios::in | ios::binary);
        while (infile)
        {
            getline(infile, s);
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

void human::arrayToFile(QVector<string> lst)
//переносим из массива в файл
{
    QFile f("human/allHumans.txt");
    if (f.exists())
    {
        ofstream outfile;
        outfile.open("human/allHumans.txt", ios::out);
        if (!outfile) cout << "Ошибка, файл не найден" << endl;
        for (int i = 0; i < lst.length(); i++)
            outfile << lst.at(i) << endl;
        outfile.close();
    }
    else
    {
        QFile mFile("human/allHumans.txt");
        mFile.open(QIODevice::WriteOnly);
        mFile.close();
        mFile.remove();

        ofstream outfile;
        outfile.open("human/allHumans.txt", ios::out);
        if (!outfile) cout << "Ошибка, файл не найден" << endl;
        for (int i = 0; i < lst.length(); i++)
            outfile << lst.at(i) << endl;
        outfile.close();
    }

}

QVector<string> human::sort(QVector<string> *lst)
//сортируем массив строк по алфавиту
{
    cout<<"---------------------------"<<endl;
    cout<<"     sorting - lst->size: "<<lst->size()<<endl;
    cout<<"     sorting - current lst: "<<endl;
    cout<<"---------------------------"<<endl;
    for(int k = 0; k < lst->size(); k++)
        cout<<(&lst[k])<<endl;
    for (int i = 0; i < lst->size(); i++)
        for (int j = i + 1; j < lst->size(); j++)
            if ((lst->at(i)) > lst->at(j))
            {
                string s;
                s=lst->at(i);
                lst->remove(i);
                lst->insert(i, lst->at(j-1));
                lst->remove(j);
                lst->insert(j, s);
            }
    cout<<"--------------------------"<<endl;
    cout<<"     sorting - sorted lst: "<<endl;
    cout<<"--------------------------"<<endl;
    for(int k = 0; k < lst->size(); k++)
        cout<<(&lst[k])<<endl;
    return *lst;
}

bool human::addFIOToFile()
{
    QVector<string> lst;
    lst=loadList();
    lst.append(surname+"_"+name+"_"+patronymic);
    sort(&lst);
    arrayToFile(lst);
    return true;
}
