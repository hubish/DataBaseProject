#ifndef HUMAN_H
#define HUMAN_H
#include "string"
#define LENGTH 255
#define amountOfPhotos 10

using namespace std;

class human
{

protected:
    char sex;
    string surname, name, patronymic, phoneNumber, email, dateOfBirth, description[LENGTH], medicalCard[2], adress, lastEditing;
    string photo[amountOfPhotos], linksToPhotos[amountOfPhotos];
    int numberOfPhotos, numberOfDescription;
    void copyFile(const char* srce_file, const char* dest_file );

public:
    /**/human(human* human);
    /**/human(string surname, string name, string patronymic, char sex,
          string phoneNumber, string email, string dateOfBirth, int numberOfDescription,
          string* description, string medicalCard[2],
          string adress, string* photo, int numberOfPhotos, string* linksToPhotos, string lastEditing);
    /**/virtual bool saveIntoFile();
    /**/virtual bool downloadFromFile(string fileName);
    /**/bool setPhoto(string photoName, string fullPath);

    /**/void setDescription(string* description, int n);
    /**/void setMedicalCard(string* medicalCard);
    /**/void setAdress(string adress);
    /**/string getSurname();
    /**/string getName();
    /**/string getPatronymic();
    /**/string getPhoneNumber();
    /**/string getEmail();
    /**/string getDateOfBirth();
    /**/int getNumberOfDescription();
    /**/string* getDescription();
    /**/string* getMedicalCard();
    /**/string gerAdress();
    /**/int gerNumberOfPhotos();
    /**/string* getPhotos();
    /**/string* getLinksToPhotos();
    /**/virtual void print();
};

#endif // human_H
