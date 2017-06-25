#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <paowindows.h>
#include <tuowindows.h>
#include <QMainWindow>
#include "qcustomplot.h"
#include <iostream>
#include "approxima.h"
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
    void drawpoint(point &poi);
    bool drawstartpointable=false;
    bool drawendpointable=false;
    approxima approx;
    paowuxian funpao;
    paowindows *paowin;
    tuowindows *tuowin;
    Ui::MainWindow *ui;
    QCustomPlot *customPlot;
    QAction *actionfullScreen;
    float x_val,y_val;
private slots:
    void fullscreen();
    void on_pushButtonf_clicked();
    void receivedatapao(paowuxian fun);
    void receivedatatuo(string str);
    void on_pushButton_7_clicked();
    void myMousemove(QMouseEvent *event);
    void myMousepressed(QMouseEvent *event);
    void on_pushButton_4_pressed();
    void on_pushButton_5_pressed();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
