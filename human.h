#ifndef HUMAN_H
#define HUMAN_H
#include "string"
#define lengthOfDescription 255
#define amountOfPhotos 10

using namespace std;

class human
{

protected:
    char sex;
    string surname, name, patronymic, phoneNumber, email, dateOfBirth, description[lengthOfDescription], medicalCard[2], adress;
    string photo[amountOfPhotos], linksToPhotos[amountOfPhotos];
    int numberOfPhotos;
    void copyFile(const char* srce_file, const char* dest_file );

public:
    /**/human();
    /**/human(human* human);
    /**/human(string surname, string name, string patronymic, char sex,
          string phoneNumber, string email, string dateOfBirth,
          string description[lengthOfDescription], string medicalCard[2],
          string adress, string photo[amountOfPhotos], int numberOfPhotos, string linksToPhotos[amountOfPhotos]);
    /**/virtual bool saveIntoFile();
    /**/virtual human downloadFromFile(string fileName);
    /**/bool setPhoto(string photoName, string fullPath);
    /**/void openPhoto(int number);

    void setDescription(string description[]);
    void setMedicalCard(string medicalCard);
    void setAdress(string adress);
    string getSurname();
    /**/virtual void print();
};

#endif // human_H
