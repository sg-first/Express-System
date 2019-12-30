#include "expresspay.h"
#include "ui_expresspay.h"
#include"express.h"
#include"dataOperation.h"
#include<QStandardItem>

expresspay::expresspay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expresspay)
{
    zhifu=new payment();
    ItemModel=new QStandardItemModel();
    ui->setupUi(this);
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(clickItem(QModelIndex)));
    connect(zhifu,SIGNAL(fresh()),this,SLOT(refresh()));
    connect(zhifu,SIGNAL(showpay()),this,SLOT(_showpay()));
    this->setWindowTitle("快递驿站系统");
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

void expresspay::clickItem(QModelIndex Index)
{
    zhifu->show(allUnpaidExpress[Index.row()]);
}

void expresspay::_showpay()
{
    this->show();
}

expresspay::~expresspay()
{
    delete ui;
}

void expresspay::on_pushButton_clicked()
{
    this->hide();
    emit showMain();
}
