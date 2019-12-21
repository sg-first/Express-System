#pragma once
#include <QMessageBox>
#include <QWidget>
#include <QString>
#include <string>
using namespace std;

class help
{
public:
    static void msgbox(QWidget* w,QString title,QString content)
    {
        QMessageBox::information(w,title,content,QMessageBox::Ok);
    }

    /*static void msgbox(QWidget* w,string title,string content)
    {
        msgbox(w,QString::fromStdString(title),QString::fromStdString(content));
    }*/

    static QString toQStr(string str) { return QString::fromStdString(str); }
};
