#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <paowindows.h>
#include <tuowindows.h>
#include <QMainWindow>
#include "qcustomplot.h"
#include <iostream>
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
    void printpao(paowuxian &pao);
    paowuxian funpao;
    paowindows *paowin;
    tuowindows *tuowin;
    Ui::MainWindow *ui;
    QCustomPlot *customPlot;
    QAction *actionfullScreen;
private slots:
    void fullscreen();
    void on_pushButtonf_clicked();
    void receivedatapao(paowuxian fun);
    void receivedatatuo(string str);
    void on_pushButton_7_clicked();
};

#endif // MAINWINDOW_H
