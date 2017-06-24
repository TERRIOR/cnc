#include "tuowindows.h"
#include "ui_tuowindows.h"

tuowindows::tuowindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tuowindows)
{
    ui->setupUi(this);
    cout<<"tuoopened"<<endl;
}

tuowindows::~tuowindows()
{
    delete ui;
}
void tuowindows::on_buttonBox_accepted()
{
    emit senddata("hi");
}
