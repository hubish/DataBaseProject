#ifndef PATIENT_H
#define PATIENT_H
#include "string"
#include "human.h"

using namespace std;

class patient:public human
{
private:
    string diagnosis[255], masculine[255];

public:
    patient();
    patient(patient* patient);
    void saveIntoFile(string fileName);
    void print();
    patient downloadFromFile(string fileName);
    void setDiagnosis(string diagnosis[]);
    void changeDiagnosis(string diagnosis[]);
    void setMasculine(string masculine[]);
    void changeMasculine(string masculine[]);
};

#endif // PATIENT_H
