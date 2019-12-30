#include "packagein.h"
#include "ui_packagein.h"
#include "express.h"
#include <QDebug>
#include <QDateTime>
#include "date.h"
#include "dataOperation.h"
#include <QMessageBox>
#include "help.h"

packagein::packagein(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::packagein)
{
    ui->setupUi(this);
    ui->number->setPlaceholderText("请输入快递单号");
    ui->fahuo->setPlaceholderText("请输入发货人");
    ui->shouhuo->setPlaceholderText("请输入收货人");
    ui->name->setPlaceholderText("请输入名字");
    ui->value->setPlaceholderText("请输入价格");
    ui->weight->setPlaceholderText("请输入重量");
    ui->volume->setPlaceholderText("请输入体积");
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
    package temp=package(courierNumber,consigner,consignee,name, weight,volume,value,refreshTime());
    dataOperation::allPackage.push_back(temp);
    ui->number->clear();
    ui->fahuo->clear();
    ui->shouhuo->clear();
    ui->name->clear();
    ui->value->clear();
    ui->weight->clear();
    ui->volume->clear();
    help::msgbox(this,"取件码",help::toQStr(temp.getPickupCode()));
}

date refreshTime()
{
    //fix:获取系统时间建议改成QT形式
    QDateTime local(QDateTime::currentDateTime());
    QString year=local.toString("yyyy");
    QString month=local.toString("MM");
    QString day=local.toString("dd");
    QString hour=local.toString("hh");
    QString minute=local.toString("mm");
    return date(year.toInt(),month.toInt(),day.toInt(),hour.toInt(),minute.toInt());
}

void packagein::on_pushButton_3_clicked()
{
    this->hide();
    emit showMain();
}
