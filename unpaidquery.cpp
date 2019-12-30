#include "unpaidquery.h"
#include "ui_unpaidquery.h"
#include "dataOperation.h"
#include <list>
#include "express.h"
unpaidquery::unpaidquery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::unpaidquery)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

unpaidquery::~unpaidquery()
{
    delete ui;
}

void unpaidquery::on_pushButton_clicked()
{
    this->hide();
    emit showMain();
}

void unpaidquery::refresh()
{
    QString result;
    vector<express*> l1=dataOperation::getAllUnpaidExpress();
    for(express* e : l1)
    {
       result=result+( QString::fromStdString(e->getExpressBill())+"\n");
    }
    ui->textEdit->setText(result);
    //fix:查询所有未支付快递，显示在文本框中
}
