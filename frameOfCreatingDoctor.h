#ifndef FRAMEOFCREATINGDOCTOR_H
#define FRAMEOFCREATINGDOCTOR_H

#include <QMainWindow>

namespace Ui {
class frameOfCreatingDoctor;
}

class frameOfCreatingDoctor : public QMainWindow
{
    Q_OBJECT

public:
    explicit frameOfCreatingDoctor(QWidget *parent = 0);
    ~frameOfCreatingDoctor();

private:
    Ui::frameOfCreatingDoctor *ui;
};

#endif // FRAMEOFCREATINGDOCTOR_H
