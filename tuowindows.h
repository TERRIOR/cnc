#ifndef TUOWINDOWS_H
#define TUOWINDOWS_H

#include <QDialog>
#include <iostream>
#include "tuoyuan.h"
using namespace std;
namespace Ui {
class tuowindows;
}

class tuowindows :   public QDialog
{
    Q_OBJECT

public:
    explicit tuowindows(QWidget *parent = 0);
    ~tuowindows();
signals:
    void senddata(tuoyuan);
private slots:
    void on_buttonBox_accepted();
private:
    Ui::tuowindows *ui;
};

#endif // TUOWINDOWS_H
