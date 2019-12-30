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
    void setTXT(QString txt);
signals:
     void showpay();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::text *ui;
};

#endif // TEXT_H
