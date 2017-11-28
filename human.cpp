#include "human.h"
#include "string"
#include "iostream"
using namespace std;

human::human()
{

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
    for (int i=0;i<255;i++)
        description[i]=human->description[i];
    sex=human->sex;
    numberOfPhotos=human->numberOfPhotos;
    for (int i=0;i<numberOfPhotos;i++)
        photo[i]=human->photo[i];
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
