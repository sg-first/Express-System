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
#include"expresspay.h"
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

public slots:
    void showMainshow();

private:
    Ui::MainWindow *ui;
    packagein* _packagein;
    packageout* _packageout;
    packagequery* _packagequery;
    packagecheck* _packagecheck;
    expressmail* _expressmail;
    expressquery* _expressquery;
    unpaidquery* _unpaidquery;
    expresspay* _expresspay;
};
#endif // MAINWINDOW_H
