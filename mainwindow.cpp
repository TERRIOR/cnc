#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionfullScreen=ui->actionFullScreen;
    connect(actionfullScreen,SIGNAL(triggered()),this,SLOT(fullscreen()));

    customPlot=ui->customPlot;
    customPlot->installEventFilter(this);
    customPlot->setSelectionTolerance(5);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);
    cout<<"dasd"<<endl;
    ui->pushButton_4->setCheckable(true);
    ui->pushButton_5->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete paowin;
    delete tuowin;
    delete ui;

}
/*void MainWindow::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
    case Qt::Key_Escape:
        customPlot->setWindowFlags (Qt::SubWindow);
        customPlot->showNormal ();
        cout<<"normal"<<endl;
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}*/
bool MainWindow::eventFilter(QObject *object, QEvent *event){
    //cout<<"dasddd"<<endl;
    if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->key() == Qt::Key_Escape)
            {
                customPlot->setWindowFlags(Qt::SubWindow);
                customPlot->showNormal();
                return true;
            }
            else
                return false;
        }
        else
        return false;
}

void MainWindow::printpao(paowuxian &pao)
{
    int pointnumber=(pao.MaxValue()-pao.MinValue())*100;
    double step=0.01;
    QVector<double> x(pointnumber), y(pointnumber); // initialize with entries 0..100
    if(pao.getDir()){
        x[0]=pao.MinValue();
        for (int i=0; i<pointnumber-1; ++i)
        {
            y[i] = pao.getresult(x[i]);  // let's plot a quadratic function
            x[i+1]=x[i]+step;
        }
        y[pointnumber-1]=pao.getresult(x[pointnumber-1]);
    }else{
        y[0]=pao.MinValue();
        for (int i=0; i<pointnumber-1; ++i)
        {
            x[i] = pao.getresult(y[i]);  // let's plot a quadratic function
            y[i+1]=y[i]+step;
        }
        x[pointnumber-1]=pao.getresult(y[pointnumber-1]);
    }

    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->graph(0)->rescaleAxes(true);
    // set axes ranges, so we see all data:
    //customPlot->xAxis->setRange(pao.MinValue(), pao.MaxValue());
    //customPlot->yAxis->setRange(0, 1);
}
void MainWindow::fullscreen()
{
    customPlot->setWindowFlags(Qt::Dialog);
    customPlot->showFullScreen();
    //customPlot->setWindowFlags (Qt::SubWindow);
    cout<<"fullscreen"<<endl;
}

void MainWindow::on_pushButtonf_clicked()
{
    cout<<"xin"<<endl;
    if(ui->radioButtonp->isChecked()){
        paowin=new paowindows();
        connect(paowin,SIGNAL(senddata(paowuxian)),this,SLOT(receivedatapao(paowuxian)));
        paowin->show();
    }else if(ui->radioButtont->isChecked()){
        tuowin=new tuowindows();
        connect(tuowin,SIGNAL(senddata(string)),this,SLOT(receivedatatuo(string)));
        tuowin->show();
    }

}

void MainWindow::receivedatapao(paowuxian fun)
{
    funpao=fun;
    cout<<"pao:"<<fun.getA()<<" "<<fun.getB()<<" "<<fun.getC()<<" "<<fun.getDir()<<endl;
}
void MainWindow::receivedatatuo(string str)
{
    cout<<"tuo:"<<str<<endl;
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->radioButtonp->isChecked()){
        printpao(funpao);
    }else if(ui->radioButtont->isChecked()){

    }
}
