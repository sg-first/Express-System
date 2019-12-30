#ifndef TEXT_H
#define TEXT_H

#include <QWidget>

namespace Ui {
class text;
}

class text : public QWidget
{
    Q_OBJECT

public:
    QString txt;
    explicit text(QWidget *parent = nullptr);
    ~text();
    void show(QString txt);

signals:
     //void showpay(); //让父窗口显示结款支付界面

private slots:
    void on_pushButton_clicked();
    void on_pay_clicked();

private:
    void setTXT(QString txt);
    Ui::text *ui;
};

#endif // TEXT_H
