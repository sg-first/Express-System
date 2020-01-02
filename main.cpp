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
    w.path="/storage/emulated/0/save"; //android保存
    //w.path=QCoreApplication::applicationDirPath()+"/save"; //Windows保存
    w.show();
    return a.exec();
}

