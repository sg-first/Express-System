#include "text.h"
#include "ui_text.h"
text::text(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::text)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    this->setWindowTitle("快递驿站系统");
}

void text::setTXT(QString txt)
{
    ui->textEdit->setText(txt);
}

text::~text()
{
    delete ui;
}

void text::on_pushButton_clicked()
{
    this->close();
}

void text::on_pushButton_2_clicked()
{
    this->close();
    emit showpay();
}
