#ifndef PATIENT_H
#define PATIENT_H
#include "string"
#include "human.h"

using namespace std;
template <typename T>
class patient:public human
{
private:
    string diagnosis, masculine;

    void arrayToFile(QVector<T> lst);

public:
    patient();
    patient(patient* patient);
    patient(string surname, string name, string patronymic, string sex,
            string phoneNumber, string email, string dateOfBirth,
            string description, string medicalCard[2],
            string adress, QVector<string> photos,
            QVector<string> linksToPhotos, string diagnosis, string masculine);
    int defineChild(){return 1;}

    /**/bool saveIntoFile();
    /**/void print();
    /**/bool downloadFromFile(string fileName);
    /**/void setDiagnosis(string diagnosis);
    /**/void setMasculine(string masculine);
    /**/string getDiagnosis();
    /**/string getMasculine();
    bool addFIOToFile();
    QVector<T> loadList();
};

#endif // PATIENT_H
