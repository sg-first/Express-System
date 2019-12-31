#ifndef PAYMENT_H
#define PAYMENT_H

#include <QWidget>
#include "express.h"
namespace Ui {
class payment;
}

class payment : public QWidget
{
    Q_OBJECT

public:
    explicit payment(QWidget *parent = nullptr);
    ~payment();
    void show(express* selectExpress);
    void setSelectExpress(express *selectExpress);

signals:
    void fresh(); //触发刷新未付款列表

private slots:
    void on_pushButton_clicked();
    void on_confirm_clicked();

private:
    express* selectExpress;
    Ui::payment *ui;
};

#endif // PAYMENT_H
