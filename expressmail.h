#ifndef EXPRESSMAIL_H
#define EXPRESSMAIL_H

#include <QWidget>

namespace Ui {
class expressmail;
}

class expressmail : public QWidget
{
    Q_OBJECT

public:
    explicit expressmail(QWidget *parent = nullptr);
    ~expressmail();
signals:
    void show_5();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::expressmail *ui;
};

#endif // EXPRESSMAIL_H
