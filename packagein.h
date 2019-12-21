#ifndef PACKAGEIN_H
#define PACKAGEIN_H

#include <QWidget>

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
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

signals:
    void show();
private:
    Ui::packagein *ui;
};
void refresh();

#endif // PACKAGEIN_H
