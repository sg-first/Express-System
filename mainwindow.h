#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"packagein.h"
#include"packageout.h"
#include"packagequery.h"
#include"packagecheck.h"
#include"expressmail.h"
#include"expressquery.h"
#include"unpaidquery.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool eventFilter(QObject *obj,QEvent *ev);
    ~MainWindow();
    packagein* zt;
    packageout* xyt;
    packagequery* xr;
    packagecheck* xx;
    expressmail* jj;
    expressquery* kk;
    unpaidquery* ll;

signals:
    void show_2();
    //void show();
    void show_3();
    void show_4();
    void show_5();
    void show_6();
    void show_7();
    
public slots:
    void showMainshow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
