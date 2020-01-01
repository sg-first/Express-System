#include "misinput.h"
#include "ui_misinput.h"
#include "error.h"
#include "help.h"

misinput::misinput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::misinput)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("输入回执单编号");
    ui->lineEdit_2->setPlaceholderText("输入客户姓名");
    ui->lineEdit_3->setPlaceholderText("输入差错类型");
    ui->lineEdit_4->setPlaceholderText("输入货物信息");
}

misinput::~misinput()
{
    delete ui;
}

void misinput::on_pushButton_2_clicked()
{
    this->hide();
}

void misinput::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}

void misinput::on_pushButton_clicked()
{
     errorpackage->error=Error(ui->lineEdit->text().toStdString(),
                               ui->lineEdit_2->text().toStdString(),
                               ui->lineEdit_3->text().toStdString(),
                               ui->lineEdit_4->text().toStdString());
     on_pushButton_3_clicked();
     help::msgbox(this,"错误信息","错误信息已录入");
}
