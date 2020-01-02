#include "mainwindow.h"
#include "dataOperation.h"
#include <QApplication>
#include "date.h"
#include <QCoreApplication>

date* date::knowday;
list<package> dataOperation::allPackage;
list<express> dataOperation::allExpress;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dataOperation::init();
    w.path=QCoreApplication::applicationDirPath()+"/save";
    w.show();
    return a.exec();
}

