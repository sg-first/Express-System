#include "packagecheck.h"
#include "ui_packagecheck.h"
#include"dataOperation.h"
packagecheck::packagecheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::packagecheck)
{
    ui->setupUi(this);
    auto tup=dataOperation::packageStockTaking();
    int yi;
    int wei;
    tie(yi,wei)=tup;
    ui->lcdNumber->display(yi);
    ui->lcdNumber_2->display(wei);
}

packagecheck::~packagecheck()
{
    delete ui;

}

void packagecheck::on_pushButton_clicked()
{
    this->hide();
    emit show_4();
}
