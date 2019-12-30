#include "expresspay.h"
#include "ui_expresspay.h"
#include"express.h"
#include"dataOperation.h"
#include<QStandardItem>

expresspay::expresspay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expresspay)
{
    ItemModel=new QStandardItemModel();
    ui->setupUi(this);
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));

    zhifu=new payment();
    connect(zhifu,SIGNAL(showpay()),this,SLOT(_showpay()));
    connect(zhifu,SIGNAL(callpay()),this,SLOT(_callpay()));
}

void expresspay::refresh()
{
    ItemModel->clear();
    QString result;
    allUnpaidExpress=dataOperation::getAllUnpaidExpress();
    for(express* e : allUnpaidExpress)
    {
      QStandardItem* item=new QStandardItem ( QString::fromStdString(e->getExpressBill()));
      ItemModel->appendRow(item);
    }
    ui->listView->setModel(ItemModel);
}

void expresspay::showClick(QModelIndex Index)
{
    list<express*>::iterator iter;
    for (int i=1;i<Index.row();i++)
    {
        iter++;
    }
    this->hide();
    zhifu->selectExpress=*iter;
    zhifu->show();
}

void expresspay::_showpay()
{
    this->show();
}

expresspay::~expresspay()
{
    delete ui;
}

void expresspay::on_pushButton_6_clicked()
{
    this->hide();
    emit showMain();
}
