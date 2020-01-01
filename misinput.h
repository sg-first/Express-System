#ifndef MISINPUT_H
#define MISINPUT_H

#include <QWidget>
#include "express.h"
namespace Ui {
class misinput;
}

class misinput : public QWidget
{
    Q_OBJECT

public:
    explicit misinput(QWidget *parent = nullptr);
    ~misinput();
    package* errorpackage;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::misinput *ui;
};

#endif // MISINPUT_H
