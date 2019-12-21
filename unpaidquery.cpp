#include "unpaidquery.h"
#include "ui_unpaidquery.h"

unpaidquery::unpaidquery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::unpaidquery)
{
    ui->setupUi(this);
}

unpaidquery::~unpaidquery()
{
    delete ui;
}

void unpaidquery::on_pushButton_clicked()
{
    this->hide();
    emit show_7();
}
