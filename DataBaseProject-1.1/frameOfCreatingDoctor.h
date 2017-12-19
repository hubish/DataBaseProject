#ifndef FRAMEOFCREATINGDOCTOR_H
#define FRAMEOFCREATINGDOCTOR_H

#include <QMainWindow>
#include "QVector"
#include "string"
#include "mainWindow.h"

using namespace std;

namespace Ui {
class frameOfCreatingDoctor;
}

class frameOfCreatingDoctor : public QMainWindow
{
    Q_OBJECT

public:
    explicit frameOfCreatingDoctor(QWidget *parent = 0);
    ~frameOfCreatingDoctor();
    QVector<string> photos,links;

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::frameOfCreatingDoctor *ui;
};

#endif // FRAMEOFCREATINGDOCTOR_H
