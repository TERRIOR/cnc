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
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i];  // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(0, 1);
    customPlot->yAxis->setRange(0, 1);
    //customPlot->setWindowFlags (Qt::Window);
    //customPlot->showFullScreen ();
    cout<<"dasd"<<endl;
}

MainWindow::~MainWindow()
{
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
    cout<<"dasddd"<<endl;
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
void MainWindow::fullscreen()
{
    customPlot->setWindowFlags(Qt::Dialog);
    customPlot->showFullScreen();
    //customPlot->setWindowFlags (Qt::SubWindow);
    cout<<"fullscreen"<<endl;
}
