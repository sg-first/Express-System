#ifndef PACKAGEOUT_H
#define PACKAGEOUT_H

#include <QWidget>

namespace Ui {
class packageout;
}

class packageout : public QWidget
{
    Q_OBJECT

public:
    explicit packageout(QWidget *parent = nullptr);
    ~packageout();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void show_2();
private:
    Ui::packageout *ui;
};

#endif // PACKAGEOUT_H
