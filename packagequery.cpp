#include "packagequery.h"
#include "ui_packagequery.h"
#include"dataOperation.h"
#include"express.h"
#include"QMessageBox"
packagequery::packagequery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::packagequery)
{
    ui->setupUi(this);
}

packagequery::~packagequery()
{
    delete ui;
}

void packagequery::on_pushButton_clicked()
{
    this->hide();
    emit showMain();
}

void packagequery::on_pushButton_2_clicked()
{
    string s=ui->lineEdit->text().toStdString();
    package* xr=dataOperation::queryPackage(s);
    string result=xr->display();
    QMessageBox::information(this,"该包裹信息",QString::fromStdString(result));
}
