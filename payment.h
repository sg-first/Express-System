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
    express* selectExpress;

signals:
    void showpay();
    void callpay();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::payment *ui;
};

#endif // PAYMENT_H
