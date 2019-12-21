#include "packageout.h"
#include "ui_packageout.h"
#include"dataOperation.h"
#include"express.h"
#include"packagein.h"
#include<QMessageBox>
packageout::packageout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::packageout)
{
    ui->setupUi(this);
}

packageout::~packageout()
{
    delete ui;
}

void packageout::on_pushButton_clicked()
{
    this->hide();
    emit show_2();
}

void packageout::on_pushButton_2_clicked()
{
    string s=ui->lineEdit->text().toStdString();
    package *xr=dataOperation::queryPackage(s);
    string result=xr->display();
    int jj=QMessageBox::information(this,"该包裹信息",QString::fromStdString(result),QMessageBox::Ok|QMessageBox::Cancel);
    if(jj=QMessageBox::Ok)
        {
   refresh();
    xr->outStock(*dataOperation::systemTime);
    }
    else
        return;
}
