#include "mainwindow.h"
#include"dataOperation.h"
#include <QApplication>
#include"date.h"

date* date::knowday;
list<package> dataOperation::allPackage;
list<express> dataOperation::allExpress;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dataOperation::init();
    w.show();
    return a.exec();
}

