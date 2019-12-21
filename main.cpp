#include "mainwindow.h"
#include"dataOperation.h"
#include <QApplication>
#include"date.h"

date* date::knowday;
date* dataOperation::systemTime;
list<package> dataOperation::allPackage;
list<express> dataOperation::allExpress;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dataOperation::init();
    dataOperation::systemTime=new date(2019,12,17,12,12);
    w.show();
    return a.exec();
}

