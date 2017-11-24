#ifndef DOCTOR_H
#define DOCTOR_H
#include "human.h"

class doctor:public human
{
private:
    string status, experience, position;

public:
    doctor();
    doctor(doctor* doctor);
    void saveIntoFile(string fileName);
    doctor downloadFromFile(string fileName);
};

#endif // DOCTOR_H
