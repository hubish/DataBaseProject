#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "string"

#include <QMainWindow>
#include <QVector>
#include <doctor.h>

using namespace std;
namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();
    void addListOfDoctorsToComboBox();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public slots:
    void setValue();
private:
    Ui::mainWindow *ui;

};

#endif // MAINWINDOW_H
