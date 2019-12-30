#include "payment.h"
#include "ui_payment.h"

payment::payment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payment)
{
    ui->setupUi(this);
    this->setWindowTitle("快递驿站系统");
}

payment::~payment()
{
    delete ui;
}

void payment::on_pushButton_clicked()
{
    this->hide();

}

void payment::on_confirm_clicked()
{
    this->selectExpress->pay();
    emit fresh();
    this->hide();
}

void payment::show(express* selectExpress)
{
    this->selectExpress=selectExpress;
    this->QWidget::show();
}
