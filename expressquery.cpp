#include "expressquery.h"
#include "ui_expressquery.h"
#include "express.h"
#include"dataOperation.h"
#include<QMessageBox>
expressquery::expressquery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expressquery)
{
    ui->setupUi(this);
}

expressquery::~expressquery()
{
    delete ui;
}

void expressquery::on_pushButton_clicked()
{
    this->hide();
    emit show_6();
}

void expressquery::on_pushButton_2_clicked()
{
    string s=ui->lineEdit->text().toStdString();
    express* xr=dataOperation::queryExpress(s);
    string result=xr->getLogisticsInformation();
    QMessageBox::information(this,"物流信息",QString::fromStdString(result));
}
