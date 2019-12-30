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

public slots:
    void refresh();

signals:
    void showMain();

private:
    Ui::expresspay *ui;

private slots:
    void clickItem(QModelIndex index);
    void on_pushButton_clicked();
    void _showpay();

private:
    QStringListModel *Model;
    QStandardItemModel *ItemModel;
    vector<express*> allUnpaidExpress;
    payment* zhifu;
};

#endif // EXPRESSPAY_H
