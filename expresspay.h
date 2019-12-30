#ifndef EXPRESSPAY_H
#define EXPRESSPAY_H

#include <QWidget>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include "express.h"
#include "payment.h"
namespace Ui {
class expresspay;
}

class expresspay : public QWidget
{
    Q_OBJECT

public:
    explicit expresspay(QWidget *parent = nullptr);
    ~expresspay();
    QStringListModel *Model;
    QStandardItemModel *ItemModel;
    list<express*> allUnpaidExpress;
    payment* zhifu;
    void refresh();

signals:
    void showMain();

public slots:
    void _callpay();

private:
    Ui::expresspay *ui;

private slots:
    void showClick(QModelIndex index);
    void on_pushButton_6_clicked();
    void _showpay();

};

#endif // EXPRESSPAY_H
