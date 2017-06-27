#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <paowindows.h>
#include <tuowindows.h>
#include <QMainWindow>
#include "qcustomplot.h"
#include <iostream>
#include "approxima.h"
#include "aboutme.h"
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *object, QEvent *event);
    //void keyPressEvent(QKeyEvent *event);
private:
    void drawpao(paowuxian &pao);
    void drawtuo(tuoyuan &tuo);
    void drawpoint(point &poi);
    bool drawstartpointable=false;
    bool drawendpointable=false;
    bool paoortuo;//true is pao false is tuo
    void printcode(vector<string> &vecstr);
    vector<point> vectorpoint;
    vector<string> vectorstring;
    approxima approx;
    paowuxian funpao;
    tuoyuan funtuo;
    aboutme *am;
    paowindows *paowin;
    tuowindows *tuowin;
    Ui::MainWindow *ui;
    QCustomPlot *customPlot;
    QAction *actionfullScreen;
    float x_val,y_val;
    QCPCurve *fermatSpiral1;
    QCPCurve *fermatSpiral2;
    bool ellispedir=true;
private slots:
    void fullscreen();
    void openaboutme();
    void on_pushButtonf_clicked();
    void receivedatapao(paowuxian fun);
    void receivedatatuo(tuoyuan tuo);
    void on_pushButton_7_clicked();
    void myMousemove(QMouseEvent *event);
    void myMousepressed(QMouseEvent *event);
    void savedata();
    void on_pushButton_4_pressed();
    void on_pushButton_5_pressed();
    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
