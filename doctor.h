#ifndef DOCTOR_H
#define DOCTOR_H
#include "human.h"
#include "string"

using namespace std;

class doctor:public human
{
private:
    string status, experience, position;

public:
    doctor(doctor* doctor);
    bool saveIntoFile();
    void print();
    bool downloadFromFile(string fileName);
};

#endif // DOCTOR_H
