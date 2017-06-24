#include "paowindows.h"
#include "ui_paowindows.h"

paowindows::paowindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paowindows)
{
    ui->setupUi(this);
    cout<<"opened"<<endl;
}

paowindows::~paowindows()
{
    delete ui;
}

void paowindows::on_buttonBox_accepted()
{
    paowuxian fun;
    string function;
    if(ui->lineEdit->text().size()>0){

        function=ui->lineEdit->text().toStdString();
        fun.readpaocan(function);
        cout<<"y  "<<function<<endl;
    }else if(ui->lineEdit_2->text().size()>0){
        function=ui->lineEdit_2->text().toStdString();
        fun.readpaocan(function);
        cout<<"x  "<<function<<endl;
    }
    fun.setMinValue(atof(ui->lineEdit_3->text().toStdString().c_str()));
    fun.setMaxValue(atof(ui->lineEdit_4->text().toStdString().c_str()));
    emit senddata(fun);
}
