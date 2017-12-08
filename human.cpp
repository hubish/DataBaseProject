#include "human.h"
#include "string"
#include "iostream"
#include "fstream"

using namespace std;

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
    numberOfDescription=human->numberOfDescription;
    for (int i=0;i<numberOfDescription;i++)
        description[i]=human->description[i];
    sex=human->sex;
    numberOfPhotos=human->numberOfPhotos;
    for (int i=0;i<numberOfPhotos;i++)
        photo[i]=human->photo[i];
    lastEditing=this->lastEditing;
}

human::human(string surname, string name, string patronymic,
             char sex, string phoneNumber, string email,
             string dateOfBirth, int numberOfDescription, string description[LENGTH],
             string medicalCard[2], string adress, string photo[amountOfPhotos],
int numberOfPhotos, string linksToPhotos[amountOfPhotos], string lastEditing)
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
    for (int i=0; i<numberOfDescription; i++)
        this->description[i]=description[i];
    this->adress=adress;
    for (int i=0; i<numberOfPhotos; i++)
        this->photo[i]=photo[i];
    this->numberOfPhotos=numberOfPhotos;
    for (int i=0; i<numberOfPhotos; i++)
        this->linksToPhotos[i]=linksToPhotos[i];
    this->numberOfDescription=numberOfDescription;
    this->lastEditing=lastEditing;
}

bool human::saveIntoFile()
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
    time(&timev);
    out2 << timev <<endl;
    for (int i=0; i<numberOfPhotos; i++)
        out2<< photo[i] <<endl;
    out2.close();

    file=mainPath + "description.txt";
    const char *cstr2 = file.c_str();
    ofstream out3(cstr2, ios_base::app);
    delete(cstr2);
    time(&timev);
    out3 << timev << endl;
    for (int i=0; i<numberOfDescription; i++)
        out3 << description[i] << endl;
    out3.close();
}

bool human::downloadFromFile(string fileName)
//Считываем пациента из папки fileName
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

    //Написать добавление ФИО в отдельный файл со списком всех ФИО пациенито и врачей
}

void human::copyFile(const char* srce_file, const char* dest_file )
{
    std::ifstream srce( srce_file, std::ios::binary ) ;
    std::ofstream dest( dest_file, std::ios::binary ) ;
    dest << srce.rdbuf() ;
}

bool human::setPhoto(string name, string fullPath)
{
    if (numberOfPhotos+1>amountOfPhotos)
        return false;
    else
    {
        numberOfPhotos++;
        photo[numberOfPhotos]=name;
        linksToPhotos[numberOfPhotos]=fullPath;
        return true;
    }
}

void human::openPhoto(int number)
{
    //system("Warface_sample.jpg");
    //ShellExecute (NULL, "open", "[b]"+photo[number]+"[/b]",NULL, NULL, SW_SHOWNORMAL);
}

void human::setDescription(string* description)
{
    numberOfDescription=sizeof(description)/sizeof(string);
    for (int i=0; i<numberOfDescription; i++)
        this->description[i]=description[i];
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

int human::getNumberOfDescription()
{
    return numberOfDescription;
}

string* human::getDescription()
{
    return description;
}

string* human::getMedicalCard()
{
    return medicalCard;
}

string human::gerAdress()
{
    return adress;
}

int human::gerNumberOfPhotos()
{
    return numberOfPhotos;
}

string* human::getPhotos()
{
    return photo;
}

string* human::getLinksToPhotos()
{
    return linksToPhotos;
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
    cout<<"Страховой полис: "<<medicalCard<<endl;
    cout<<"Адрес:           "<<adress<<endl;
}
