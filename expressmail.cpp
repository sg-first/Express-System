#include "expressmail.h"
#include "ui_expressmail.h"
#include"packagein.h"
#include"express.h"
#include"dataOperation.h"
#include<QMessageBox>

expressmail::expressmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expressmail)
{
    ui->setupUi(this);
}

expressmail::~expressmail()
{
    delete ui;
}

void expressmail::on_pushButton_clicked()
{
    ui->fahuo->clear();
    ui->shouhuo->clear();
    ui->name->clear();
    ui->value->clear();
    ui->volum->clear();
    ui->weight->clear();
}

void expressmail::on_pushButton_3_clicked()
{
    this->hide();
    emit showMain();
}

void expressmail::on_confirm_clicked()
{
    string consigner=ui->fahuo->text().toStdString();
    string consignee=ui->shouhuo->text().toStdString();
    string name=ui->name->text().toStdString();
    float weight=ui->weight->text().toFloat();
    float volume=ui->volum->text().toFloat();
    float value=ui->value->text().toFloat();

    refreshTime();
    express temp=express(consigner,consignee,name, weight,volume,value,*dataOperation::systemTime);
    dataOperation::allExpress.push_back(temp);
    string expbill=temp.getExpressBill();
    //fix:快递单显示到只读文本框
}
