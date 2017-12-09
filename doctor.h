#ifndef DOCTOR_H
#define DOCTOR_H
#include "human.h"
#include "string"

using namespace std;

class doctor:public human
{
private:
    string status, experience, position;

public:
    doctor(doctor* doctor);
    doctor(string surname, string name, string patronymic, char sex,
              string phoneNumber, string email, string dateOfBirth, int numberOfDescription,
              string* description, string medicalCard[2],
              string adress, string* photo, int numberOfPhotos, string* linksToPhotos, string lastEditing, string status, string experience, string position);
    bool saveIntoFile(); //Добавить сохранение в отдельный файл ФИО пациентов для последующего поиска
    void print();
    bool downloadFromFile(string fileName);
};

#endif // DOCTOR_H
