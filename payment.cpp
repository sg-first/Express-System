#include "payment.h"
#include "ui_payment.h"
#include "help.h"

payment::payment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payment)
{
    ui->setupUi(this);
    help::setBackground(this,Qt::white);
    this->setWindowTitle("快递驿站系统");
    QPixmap pixmap(":/1577930582632.jpg");
    pixmap.scaled(ui->label->size());
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pixmap);
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

void payment::setSelectExpress(express* selectExpress)
{
    this->selectExpress=selectExpress;
}
