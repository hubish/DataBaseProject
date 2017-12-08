#include "human.h"
#include "string"
#include "iostream"

using namespace std;

human::human()
{
    surname="No surname";
    name="No name";
    patronymic="No patronymic";
    phoneNumber="No phone number";
    email="No email";
    dateOfBirth="No date of birth";
    medicalCard="No medical card";
    adress="No adress";
    for (int i=0;i<255;i++)
        description[i]="";
    sex="No sex";
    numberOfPhotos=0;
    numberOfDescription=0;
}

human::human(human* human)
{
    surname=human->surname;
    name=human->name;
    patronymic=human->patronymic;
    phoneNumber=human->phoneNumber;
    email=human->email;
    dateOfBirth=human->dateOfBirth;
    medicalCard=human->medicalCard;
    adress=human->adress;
    numberOfDescription=human->numberOfDescription;
    for (int i=0;i<numberOfDescription;i++)
        description[i]=human->description[i];
    sex=human->sex;
    numberOfPhotos=human->numberOfPhotos;
    for (int i=0;i<numberOfPhotos;i++)
        photo[i]=human->photo[i];
}

human::human(string surname, string name, string patronymic,
             char sex, string phoneNumber, string email,
             string dateOfBirth, int numberOfDescription, string description[lengthOfDescription],
             string medicalCard[2], string adress, string photo[amountOfPhotos],
             int numberOfPhotos, string linksToPhotos[amountOfPhotos])
{
    this->surname=surname;
    this->name=name;
    this->patronymic=patronymic;
    this->sex=sex;
    this->phoneNumber=phoneNumber;
    this->email=email;
    this->dateOfBirth=dateOfBirth;
    this->description=description;
    this->medicalCard=medicalCard;
    this->adress=adress;
    this->photo=photo;
    this->numberOfPhotos=numberOfPhotos;
    this->linksToPhotos=linksToPhotos;
    this->numberOfDescription=numberOfDescription;
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
    for (i=0; i<numberOfPhotos; i++)
        copyFile(linksToPhotos[i].c_str(), (mainPath + photo[i]).c_str());

    *cstr = file.c_str();
    out(cstr, ios_base::app);
    delete(cstr);
    time(&timev);
    out << timev <<endl;
    for (i=0; i<numberOfPhotos; i++)
        out << photo[i] <<endl;
    out.close();

    file=mainPath + "description.txt";
    *cstr = file.c_str();
    out(cstr, ios_base::app);
    delete(cstr);
    time(&timev);
    out << timev << endl;
    for (i=0; i<numberOfDescription; i++)
        out << description[i] << endl;
    out.close();
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
    ShellExecute (NULL, "open", "[b]"+photo[number]+"[/b]",NULL, NULL, SW_SHOWNORMAL);
}

void human::setDescription(string* description)
{
    numberOfDescription=sizeof(description)/sizeof(string);
    this->description=description;
}

void human::setMedicalCard(string* medicalCard)
{
    this->medicalCard=medicalCard;
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
