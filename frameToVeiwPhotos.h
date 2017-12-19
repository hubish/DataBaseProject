#ifndef FRAMETOVEIWPHOTOS_H
#define FRAMETOVEIWPHOTOS_H

#include <QMainWindow>

namespace Ui {
class frameToVeiwPhotos;
}

class frameToVeiwPhotos : public QMainWindow
{
    Q_OBJECT

public:
    explicit frameToVeiwPhotos(QWidget *parent = 0);
    ~frameToVeiwPhotos();
    void setPhoto(std::string name);

private:
    Ui::frameToVeiwPhotos *ui;
};

#endif // FRAMETOVEIWPHOTOS_H
