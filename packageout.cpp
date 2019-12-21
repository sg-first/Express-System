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
    ui->setupUi(this);
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
        pack->outStock(*dataOperation::systemTime);
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
