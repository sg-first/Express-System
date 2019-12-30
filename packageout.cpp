#include "packageout.h"
#include "ui_packageout.h"
#include "dataOperation.h"
#include "express.h"
#include "packagein.h"
#include <QMessageBox>
#include "help.h"

packageout::packageout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::packageout)
{
    this->setWindowTitle("快递驿站系统");
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("请输入取件码");
}

packageout::~packageout()
{
    delete ui;
}

void packageout::on_pushButton_clicked()
{
    this->hide();
    emit showMain();
}

void packageout::on_confirmOut_clicked()
{
    QString qsCode=ui->lineEdit->text();
    string code=qsCode.toStdString();
    package *pack=dataOperation::queryPackage(code);
    if(pack!=nullptr)
    {
        refreshTime();
        pack->outStock(refreshTime());
        help::msgbox(this,"包裹信息",qsCode+"出库成功");
        /*string result=pack->display();
        auto jj=QMessageBox::information(this,"包裹信息",QString::fromStdString(result),QMessageBox::Ok|QMessageBox::Cancel);
        if(jj==QMessageBox::Ok)
        {

        }*/
    }
    else
        help::msgbox(this,"包裹信息","该包裹不存在");
}
