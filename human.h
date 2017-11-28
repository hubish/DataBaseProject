#ifndef HUMAN_H
#define HUMAN_H
#include "string"

using namespace std;

class human
{

protected:
    char sex;
    string surname, name, patronymic, phoneNumber, email, dateOfBirth, description[255], medicalCard, adress;
    string photo[10];
    int numberOfPhotos;

public:
    human();
    human(human* human);
    human(string surname, string name, string patronymic, char sex, string phoneNumber, string email, string dateOfBirth, string description[], string medicalCard, string adress, string photo[10], int numberOfPhotos);
    virtual void saveIntoFile(string fileName);
    human downloadFromFile(string fileName);
    void setPhoto(string photoName);
    void openPhoto(int number);

    void setDescription(string description[]);
    void setMedicalCard(string medicalCard);
    void setAdress(string adress);
    string getSurname();
    virtual void print();
};

#endif // human_H
