#ifndef PAOWINDOWS_H
#define PAOWINDOWS_H

#include <QDialog>
#include <iostream>
#include <paowuxian.h>
using namespace std;
namespace Ui {
class paowindows;
}

class paowindows : public QDialog
{
    Q_OBJECT

public:
    explicit paowindows(QWidget *parent = 0);
    ~paowindows();
signals:
    void senddata(paowuxian);
private slots:
    void on_buttonBox_accepted();
private:
    Ui::paowindows *ui;
};

#endif // PAOWINDOWS_H
