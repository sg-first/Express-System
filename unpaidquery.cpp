#include "unpaidquery.h"
#include "ui_unpaidquery.h"

unpaidquery::unpaidquery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::unpaidquery)
{
    ui->setupUi(this);
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
    //fix:查询所有未支付快递，显示在文本框中
}
