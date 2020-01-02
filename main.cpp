#include "mainwindow.h"
#include "dataOperation.h"
#include <QApplication>
#include "date.h"
#include <QCoreApplication>
#include <QDebug>

date* date::knowday;
list<package> dataOperation::allPackage;
list<express> dataOperation::allExpress;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dataOperation::init();
    w.path="/data/app/save";
    w.show();
    qDebug()<<w.path;
    return a.exec();
}

