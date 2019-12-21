#include "packagein.h"
#include "ui_packagein.h"
#include "express.h"
#include <QDebug>
#include <ctime>
#include "date.h"
#include "dataOperation.h"
#include <QMessageBox>
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
    ui->lineEdit_7->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
}

void packagein::on_pushButton_2_clicked()
{
string courierNumber=ui->lineEdit_7->text().toStdString();
string consigner=ui->lineEdit->text().toStdString();
string consignee=ui->lineEdit_2->text().toStdString();
string name=ui->lineEdit_3->text().toStdString();
float weight=ui->lineEdit_4->text().toFloat();
float volume=ui->lineEdit_5->text().toFloat();
float value=ui->lineEdit_6->text().toFloat();
refreshTime();
package temp=package(courierNumber,consigner,consignee,name, weight,volume,value,*dataOperation::systemTime);
dataOperation::allPackage.push_back(temp);
string pkup=temp.getPickupCode();
QMessageBox::information(this,"取件码",QString::fromStdString(pkup));
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
