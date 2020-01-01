#ifndef ENTRYERROR_H
#define ENTRYERROR_H

#include <QWidget>
#include "misinput.h"
namespace Ui {
class entryerror;
}

class entryerror : public QWidget
{
    Q_OBJECT

public:
    explicit entryerror(QWidget *parent = nullptr);
    ~entryerror();
    misinput* _misinput;
signals:
    void showMain();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::entryerror *ui;
};

#endif // ENTRYERROR_H
