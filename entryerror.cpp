#include "entryerror.h"
#include "ui_entryerror.h"
#include "express.h"
#include "dataOperation.h"
#include <QMessageBox>
entryerror::entryerror(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::entryerror)
{
    ui->setupUi(this);
    _misinput=new misinput ();
}

entryerror::~entryerror()
{
    delete ui;
}

void entryerror::on_pushButton_clicked()
{
    string code=ui->lineEdit->text().toStdString();
    package* pack=dataOperation::queryPackage(code);
    if(pack==nullptr)
    {
        QMessageBox::information(this,"提示","没找到指定包裹");
    }
    else
    {
        _misinput->errorpackage=pack;
        _misinput->show();
    }
}

void entryerror::on_pushButton_2_clicked()
{
    this->hide();
    emit showMain();
}
