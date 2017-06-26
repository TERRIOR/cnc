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
    tuoyuan fun;
    string function;
    function=ui->lineEdit->text().toStdString();
    fun.readtuocan(function);
    cout<<"y  "<<function<<endl;
    fun.setMinValue(atof(ui->lineEdit_5->text().toStdString().c_str()));
    fun.setMaxValue(atof(ui->lineEdit_6->text().toStdString().c_str()));
    emit senddata(fun);
    //emit senddata("hi");
}
