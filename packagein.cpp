#include "packagein.h"
#include "ui_packagein.h"
#include "express.h"
#include <QDebug>
#include <ctime>
#include "date.h"
#include "dataOperation.h"
#include <QMessageBox>
#include "help.h"

packagein::packagein(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::packagein)
{
    ui->setupUi(this);
}

packagein::~packagein()
{
    delete ui;
}

void packagein::on_pushButton_clicked()
{
    ui->number->clear();
    ui->fahuo->clear();
    ui->shouhuo->clear();
    ui->name->clear();
    ui->value->clear();
    ui->weight->clear();
    ui->volume->clear();
}

void packagein::on_confirm_clicked()
{
    string courierNumber=ui->number->text().toStdString();
    string consigner=ui->fahuo->text().toStdString();
    string consignee=ui->shouhuo->text().toStdString();
    string name=ui->name->text().toStdString();
    float weight=ui->weight->text().toFloat();
    float volume=ui->volume->text().toFloat();
    float value=ui->value->text().toFloat();
    refreshTime();
    package temp=package(courierNumber,consigner,consignee,name, weight,volume,value,*dataOperation::systemTime);
    dataOperation::allPackage.push_back(temp);
    help::msgbox(this,"取件码",help::toQStr(temp.getPickupCode()));
}

void refreshTime()
{
    //fix:获取系统时间建议改成QT形式
    time_t timer;
    time(&timer);
    tm *t_tm=localtime(&timer);
    int year=t_tm->tm_year+1900;
    int month=t_tm->tm_mon+1;
    int day=t_tm->tm_mday;
    int hour=t_tm->tm_hour;
    int minute=t_tm->tm_min;
    dataOperation::systemTime->reSet(year,month,day,hour,minute);
}

void packagein::on_pushButton_3_clicked()
{
    this->hide();
    emit show();
}
