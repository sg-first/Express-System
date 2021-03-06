#ifndef PACKAGECHECK_H
#define PACKAGECHECK_H

#include <QWidget>

namespace Ui {
class packagecheck;
}

class packagecheck : public QWidget
{
    Q_OBJECT

public:
    explicit packagecheck(QWidget *parent = nullptr);
    ~packagecheck();

signals:
    void showMain();

public slots:
    void refresh();

private slots:
    void on_pushButton_clicked();

private:
    Ui::packagecheck *ui;
};

#endif // PACKAGECHECK_H
