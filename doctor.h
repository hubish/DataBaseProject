#ifndef DOCTOR_H
#define DOCTOR_H
#include "human.h"
#include "string"


using namespace std;
template <typename T>
class doctor:public human
{
private:
    string status, experience, position;

    void arrayToFile(QVector<T> lst);

public:
    doctor();
    doctor(doctor* doctor);
    doctor(string surname, string name, string patronymic, string sex,
           string phoneNumber, string email, string dateOfBirth,
           string description, string medicalCard[2],
           string adress, QVector<string> photos,
           QVector<string> linksToPhotos,
           string status, string experience, string position);
    bool saveIntoFile();
    void print();
    bool downloadFromFile(string fileName);
    bool addFIOToFile();
    int defineChild(){return 2;}
    QVector<T> loadList();
};

#endif // DOCTOR_H
