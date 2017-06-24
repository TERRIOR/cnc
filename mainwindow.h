#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    Ui::MainWindow *ui;
    QCustomPlot *customPlot;
    QAction *actionfullScreen;
private slots:
    void fullscreen();
};

#endif // MAINWINDOW_H
