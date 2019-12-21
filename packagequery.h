#ifndef PACKAGEQUERY_H
#define PACKAGEQUERY_H

#include <QWidget>

namespace Ui {
class packagequery;
}

class packagequery : public QWidget
{
    Q_OBJECT

public:
    explicit packagequery(QWidget *parent = nullptr);
    ~packagequery();

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();
    void on_query_clicked();

private:
    Ui::packagequery *ui;
};

#endif // PACKAGEQUERY_H
