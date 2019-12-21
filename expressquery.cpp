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
    emit showMain();
}

void expressquery::on_query_clicked()
{
    string code=ui->lineEdit->text().toStdString();
    express* e=dataOperation::queryExpress(code);
    string result=e->getLogisticsInformation();
    //fix:使用只读文本框展示
}
