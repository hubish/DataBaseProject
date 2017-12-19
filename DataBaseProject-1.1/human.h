#ifndef HUMAN_H
#define HUMAN_H
#include "string"
#define LENGTH 255
#define amountOfPhotos 10
#include "QVector"


using namespace std;
class human
{

protected:
    string surname,sex, name, patronymic, phoneNumber, email, dateOfBirth, description, medicalCard[2], adress, lastEditing;
    QVector<string> photos,linksToPhotos;

    void copyFile(const char* srce_file, const char* dest_file );
    QVector<string> sort(QVector<string> *lst);
    virtual void arrayToFile(QVector<string> lst);

public:
    human();
    /**/human(human* human);
    /**/human(string surname, string name, string patronymic, string sex,
              string phoneNumber, string email, string dateOfBirth,
              string description, string medicalCard[2],
              string adress, QVector<string> photos, QVector<string> linksToPhotos);
    /**/virtual bool saveIntoFile();
    /**/virtual bool downloadFromFile(string fileName);
    /**/void setPhoto(string photoName, string fullPath);
    virtual int defineChild(){return 0;}
    /**/void setDescription(string description);
    /**/void setMedicalCard(string* medicalCard);
    /**/void setAdress(string adress);
    /**/string getSurname();
    /**/string getName();
    /**/string getPatronymic();
    /**/string getPhoneNumber();
    /**/string getEmail();
    /**/string getDateOfBirth();
    /**/string getDescription();
    /**/string* getMedicalCard();
    string getSex();
    /**/string getAdress();
    /**/QVector<string> getPhotos();
    /**/QVector<string> getLinksToPhotos();
    /**/virtual void print();
    /**/virtual bool addFIOToFile();
    virtual QVector<string> loadList();
};

#endif // human_H
