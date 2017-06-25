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
    customPlot->setSelectionTolerance(20);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue, 3));
    customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);    ///步骤2 新建一条散点图

    customPlot->addGraph();
    QCPScatterStyle myScatter;
    myScatter.setShape(QCPScatterStyle::ssDisc);
    myScatter.setPen(QPen(Qt::red));
    myScatter.setBrush(QBrush(Qt::white));
    myScatter.setSize(5);
    customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(1)->setScatterStyle(myScatter);

    customPlot->addGraph();
    customPlot->graph(2)->setPen(QPen(Qt::yellow, 2));
    customPlot->graph(2)->setLineStyle(QCPGraph::lsLine);    ///步骤2 新建一条散点图
    ui->pushButton_4->setCheckable(true);
    ui->pushButton_5->setCheckable(true);
    connect(customPlot,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(myMousemove(QMouseEvent*)));
    connect(customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(myMousepressed(QMouseEvent*)));
}

MainWindow::~MainWindow()
{
    delete paowin;
    delete tuowin;
    delete ui;

}
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

void MainWindow::drawpao(paowuxian &pao)
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
    //customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->graph(0)->rescaleAxes(true);
    // set axes ranges, so we see all data:
    //customPlot->xAxis->setRange(pao.MinValue(), pao.MaxValue());
    //customPlot->yAxis->setRange(0, 1);
}

void MainWindow::drawpoint(point &poi)
{
    static QVector<double> x(2),y(2);
    x[1]=x[0];
    y[1]=y[0];
    x[0]=poi.x();
    y[0]=funpao.getresult(poi.x());
    customPlot->graph(1)->setData(x,y);
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
        drawpao(funpao);
    }else if(ui->radioButtont->isChecked()){

    }
}

void MainWindow::myMousemove(QMouseEvent *event)
{
    //获取鼠标坐标点
    if(drawstartpointable||drawendpointable){
        int x_pos = event->pos().x();
        int y_pos = event->pos().y();
        // 把鼠标坐标点 转换为 QCustomPlot 内部坐标值 （pixelToCoord 函数）
        // coordToPixel 函数与之相反 是把内部坐标值 转换为外部坐标点
        x_val = customPlot->xAxis->pixelToCoord(x_pos);
        y_val = customPlot->yAxis->pixelToCoord(y_pos);
        // 然后打印在界面上 设置为三位有效数字
        if(drawstartpointable){
            //funpao.setStartpoint(point(x_val,y_val));
            ui->label_5->setText(tr("x:%1 y:%2").arg(x_val,0,'g',3).arg(y_val,0,'g',3));
        }
        else if(drawendpointable){
            //funpao.setEndpoint(point(x_val,y_val));
            ui->label_6->setText(tr("x:%1 y:%2").arg(x_val,0,'g',3).arg(y_val,0,'g',3));
        }
    }

}

void MainWindow::myMousepressed(QMouseEvent *event)
{
    point poi(x_val,y_val);
    if(drawstartpointable){
        funpao.setStartpoint(poi);
        drawpoint(poi);
        drawstartpointable=false;
        ui->label_5->setText(tr("x:%1 y:%2").arg(x_val,0,'g',3).arg(y_val,0,'g',3));
        ui->pushButton_4->setChecked(false);
    }
    else if(drawendpointable){
        funpao.setEndpoint(poi);
        drawpoint(poi);
        drawendpointable=false;
        ui->label_6->setText(tr("x:%1 y:%2").arg(x_val,0,'g',3).arg(y_val,0,'g',3));
        ui->pushButton_5->setChecked(false);
    }

}

void MainWindow::on_pushButton_4_pressed()
{
    drawstartpointable=!drawstartpointable;//取反
    if(drawstartpointable){
        cout<<"can drawstartpoint"<<endl;
    }

}

void MainWindow::on_pushButton_5_pressed()
{
    drawendpointable=!drawendpointable;
    if(drawendpointable){
        cout<<"can drawendpoint"<<endl;

    }

}

void MainWindow::on_pushButton_3_clicked()
{

    vector<point> vectorpoint= approx.calappropao(funpao,0.001,0.1);
    int count=int(vectorpoint.size());
    cout<<count<<endl;
    QVector<double> x(count),y(count);
    vector<point>::iterator iteratorpoint=vectorpoint.begin();
    int i=0;
    while (iteratorpoint!=vectorpoint.end()) {
        x[i]=(*iteratorpoint).x();
        y[i]=(*iteratorpoint).y();
        cout<<"x:"<<x[i]<<"y:"<<y[i]<<endl;
        i++;
        iteratorpoint++;
    }
    customPlot->graph(2)->setData(x,y);
    ui->label->setText(tr("结果: %1").arg(count));
}
