#ifndef EXPRESSQUERY_H
#define EXPRESSQUERY_H

#include <QWidget>

namespace Ui {
class expressquery;
}

class expressquery : public QWidget
{
    Q_OBJECT

public:
    explicit expressquery(QWidget *parent = nullptr);
    ~expressquery();

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();
    void on_query_clicked();

private:
    Ui::expressquery *ui;
};

#endif // EXPRESSQUERY_H
