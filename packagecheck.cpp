#include "packagecheck.h"
#include "ui_packagecheck.h"
#include"dataOperation.h"

packagecheck::packagecheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::packagecheck)
{
    ui->setupUi(this);
}

packagecheck::~packagecheck()
{
    delete ui;

}

void packagecheck::on_pushButton_clicked()
{
    this->hide();
    emit showMain();
}

void packagecheck::refresh()
{
    auto tup=dataOperation::packageStockTaking();
    int yi,wei;
    tie(yi,wei)=tup;
    ui->lcdNumber->display(yi);
    ui->lcdNumber_2->display(wei);
}
