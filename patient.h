#ifndef PATIENT_H
#define PATIENT_H
#include "string"
#include "human.h"

using namespace std;

class patient:public human
{
private:
    string diagnosis[LENGTH], masculine[LENGTH];

public:
    patient(patient* patient);
    patient(string surname, string name, string patronymic, char sex,
              string phoneNumber, string email, string dateOfBirth, int numberOfDescription,
              string description[LENGTH], string medicalCard[2],
              string adress, string photo[amountOfPhotos], int numberOfPhotos,
              string linksToPhotos[amountOfPhotos], string lastEditing, string diagnosis[LENGTH], string masculine[LENGTH]);

    bool saveIntoFile(string fileName);
    /**/void print();
    bool downloadFromFile(string fileName);
    void setDiagnosis(string diagnosis[]);
    void changeDiagnosis(string diagnosis[]);
    void setMasculine(string masculine[]);
    void changeMasculine(string masculine[]);
};

#endif // PATIENT_H
