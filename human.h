#ifndef HUMAN_H
#define HUMAN_H
#include "string.h"


class human
{

private:
    char sex;
    string surname, name, patronymic, phoneNumber, email, dateOfBirth, description[], medicalCard, adress;
    string photo[10];
    int numberOfPhotos;

public:
    human();
    human(human* human);
    human(string surname, string name, string patronymic, char sex, string phoneNumber, string email, string dateOfBirth, string description[], string medicalCard, string adress, string photo[10], int numberOfPhotos);
    void saveIntoFile(string fileName);
    human downloadFromFile(string fileName);
    void setPhoto(string photoName);
    void openPhoto(int number);

    void setDescription(string description[]);
    void setMedicalCard(string medicalCard);
    void setAdress(string adress);
    string getSurname();
};

#endif // human_H
