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
    ui->lineEdit->setPlaceholderText("请输入取件码");
    this->setWindowTitle("快递驿站系统");
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

void packagequery::on_query_clicked()
{
    string code=ui->lineEdit->text().toStdString();
    package* pack=dataOperation::queryPackage(code);
    if(pack==nullptr)
    {
        QMessageBox::information(this,"提示","没查到指定包裹");
    }
    else
    {
        string result=pack->display();
        ui->textEdit->setText(QString::fromStdString(result));
    }
}
