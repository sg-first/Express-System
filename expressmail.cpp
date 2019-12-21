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
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
}

void expressmail::on_pushButton_3_clicked()
{
    this->hide();
    emit show_5();
}

void expressmail::on_pushButton_2_clicked()
{
    string consigner=ui->lineEdit->text().toStdString();
    string consignee=ui->lineEdit_2->text().toStdString();
    string name=ui->lineEdit_3->text().toStdString();
    float weight=ui->lineEdit_4->text().toFloat();
    float volume=ui->lineEdit_5->text().toFloat();
    float value=ui->lineEdit_6->text().toFloat();
    refreshTime();
    express temp=express(consigner,consignee,name, weight,volume,value,*dataOperation::systemTime);
    dataOperation::allExpress.push_back(temp);
    string expbill=temp.getExpressBill();
    QMessageBox::information(this,"快递单",QString::fromStdString(expbill));
}
