#ifndef PATIENT_H
#define PATIENT_H
#include "string.h"
#include "human.h"


class patient:public human
{
private:
    string diagnosis[], masculine[];

public:
    patient();
    patient(patient* patient);
    void saveIntoFile(string fileName);
    patient downloadFromFile(string fileName);
    void setDiagnosis(string diagnosis[]);
    void changeDiagnosis(string diagnosis[]);
    void setMasculine(string masculine[]);
    void changeMasculine(string masculine[]);
};

#endif // PATIENT_H
