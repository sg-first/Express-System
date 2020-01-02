#pragma once
#include <QMessageBox>
#include <QWidget>
#include <QString>
#include <string>
#include "date.h"
#include <QDateTime>
#include <QPalette>
#include <QPixmap>
#include <QLabel>
using namespace std;

class help
{
public:
    static void msgbox(QWidget* w,QString title,QString content)
    {
        QMessageBox::information(w,title,content,QMessageBox::Ok);
    }

    static QString toQStr(string str) { return QString::fromStdString(str); }

    static date refreshTime()
    {
        QDateTime local(QDateTime::currentDateTime());
        QString year=local.toString("yyyy");
        QString month=local.toString("MM");
        QString day=local.toString("dd");
        QString hour=local.toString("hh");
        QString minute=local.toString("mm");
        return date(year.toInt(),month.toInt(),day.toInt(),hour.toInt(),minute.toInt());
    }

    static void setBackground(QWidget *w,QString path)
    {
        QPalette pal=w->palette();
        QPixmap pix=QPixmap(path);
        pix=pix.scaled(QSize(358,600),Qt::KeepAspectRatio);
        pal.setBrush(QPalette::Background,QBrush(pix));
        w->setPalette(pal);
    }

    static void setBackground(QWidget *w,QColor c)
    {
        QPalette pal=w->palette();
        pal.setBrush(QPalette::Background,c);
        w->setPalette(pal);
    }

    static void setLabelBackground(QLabel *l, QColor bg,QColor text)
    {
        QPalette palette_2;
        palette_2.setColor(QPalette::Background,bg);
        palette_2.setColor(QPalette::WindowText,text);
        l->setAutoFillBackground(true);
        l->setPalette(palette_2);
    }
};
