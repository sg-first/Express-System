#include "expressmail.h"
#include "ui_expressmail.h"
#include "packagein.h"
#include "express.h"
#include "dataOperation.h"
#include <QMessageBox>
#include "payment.h"
#include "text.h"
#include "help.h"

expressmail::expressmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expressmail)
{
    displayBill=new text;
    zhifu=new payment;
    ui->setupUi(this);
    connect(displayBill,SIGNAL(showpay()),this,SLOT(_showpay()));

    ui->fahuo->setPlaceholderText("输入发货人");
    ui->shouhuo->setPlaceholderText("输入收货人");
    ui->name->setPlaceholderText("输入名字");
    ui->value->setPlaceholderText("输入价格");
    ui->volum->setPlaceholderText("输入体积");
    ui->weight->setPlaceholderText("输入重量");
    this->setWindowTitle("快递驿站系统");
}

expressmail::~expressmail()
{
    delete ui;
}

void expressmail::on_clear_clicked()
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
    if(ui->fahuo->text()==""||ui->shouhuo->text()==""||ui->name->text()==""||ui->weight->text()==""||ui->volum->text()==""||ui->value->text()=="")
    {
        QMessageBox::information(this,"提示","请填写信息",QMessageBox::Ok);
        return;
    }

    string consigner=ui->fahuo->text().toStdString();
    string consignee=ui->shouhuo->text().toStdString();
    string name=ui->name->text().toStdString();
    float weight=ui->weight->text().toFloat();
    float volume=ui->volum->text().toFloat();
    float value=ui->value->text().toFloat();
    dataOperation::allExpress.push_back(express(consigner,consignee,name, weight,volume,value,help::refreshTime()));
    on_clear_clicked();

    express *e=&dataOperation::allExpress.back();
    zhifu->show(e);
    string expbill=e->getExpressBill();
    displayBill->show(QString::fromStdString(expbill));
}

