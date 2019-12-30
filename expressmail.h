#ifndef EXPRESSMAIL_H
#define EXPRESSMAIL_H

#include <QWidget>
#include "payment.h"
#include "text.h"
namespace Ui {
class expressmail;
}

class expressmail : public QWidget
{
    Q_OBJECT

public:
    explicit expressmail(QWidget *parent = nullptr);
    ~expressmail();

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_confirm_clicked();
    //void _showpay(); //显示结款支付界面

private:
    payment* zhifu;
    text* displayBill;
    Ui::expressmail *ui;
};

#endif // EXPRESSMAIL_H
