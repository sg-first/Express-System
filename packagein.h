#ifndef PACKAGEIN_H
#define PACKAGEIN_H

#include <QWidget>
#include"date.h"
namespace Ui {
class packagein;
}

class packagein : public QWidget
{
    Q_OBJECT

public:
    explicit packagein(QWidget *parent = nullptr);
    ~packagein();

private slots:
    void on_pushButton_clicked();
    void on_confirm_clicked();
    void on_pushButton_3_clicked();

signals:
    void showMain();

private:
    Ui::packagein *ui;
};
date refreshTime();

#endif // PACKAGEIN_H
