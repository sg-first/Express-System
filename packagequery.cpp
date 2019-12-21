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

void packagequery::on_query_clicked()
{
    string code=ui->lineEdit->text().toStdString();
    package* pack=dataOperation::queryPackage(code);
    string result=pack->display();
    //fix:使用只读文本框展示
}
