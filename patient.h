#ifndef PATIENT_H
#define PATIENT_H
#include "string"
#include "human.h"

using namespace std;

class patient:public human
{
private:
    string diagnosis[LENGTH], masculine[LENGTH];
    int numberOfDiagnosis, numberOfMasculine;

public:
    patient(patient* patient);
    patient(string surname, string name, string patronymic, char sex,
              string phoneNumber, string email, string dateOfBirth, int numberOfDescription,
              string* description, string medicalCard[2],
              string adress, string* photo, int numberOfPhotos,
              string* linksToPhotos, int numberOfDiagnosis, string* diagnosis, int numberOfMasculine, string* masculine, string lastEditing);

    /**/bool saveIntoFile();
    /**/void print();
    /**/bool downloadFromFile(string fileName);
    /**/void setDiagnosis(string* diagnosis, int n);
    /**/void setMasculine(string* masculine, int n);
    /**/string* getDiagnosis();
    /**/string* getMasculine();
};

#endif // PATIENT_H
