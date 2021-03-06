#ifndef UNPAIDQUERY_H
#define UNPAIDQUERY_H

#include <QWidget>

namespace Ui {
class unpaidquery;
}

class unpaidquery : public QWidget
{
    Q_OBJECT

public:
    explicit unpaidquery(QWidget *parent = nullptr);
    ~unpaidquery();

signals:
    void showMain();

public slots:
    void refresh();

private slots:
    void on_pushButton_clicked();
    
private:
    Ui::unpaidquery *ui;
};

#endif // UNPAIDQUERY_H
