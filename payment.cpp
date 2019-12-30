#include "payment.h"
#include "ui_payment.h"

payment::payment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payment)
{
    ui->setupUi(this);
}

payment::~payment()
{
    delete ui;
}

void payment::on_pushButton_clicked()
{
    this->hide();

}

void payment::on_pushButton_2_clicked()
{
    this->selectExpress->pay();
}
