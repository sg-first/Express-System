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
    ui->lineEdit->setPlaceholderText("请输入取件码");
    this->setWindowTitle("快递驿站系统");
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
    if(e==nullptr)
    {
        QMessageBox::information(this,"提示","没查到指定物流");
        return;
    }
    else{
    string result=e->getLogisticsInformation();
    //fix:使用只读文本框展示
    ui->textEdit->setText(QString::fromStdString(result));
    }
}
