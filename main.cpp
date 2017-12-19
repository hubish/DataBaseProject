#include "mainWindow.h"
#include "patientChoice.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Rus");
    QApplication a(argc, argv);
    mainWindow w;
    w.show();
    return a.exec();
}
