#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QDebug"
#include "express.h"
#include "packagein.h"
#include "help.h"
#include "binarySerialize.h"
#include "dataOperation.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    help::setBackground(this,QString(":/bg_.png"));
    this->setWindowTitle("快递驿站系统");
    ui->setupUi(this);
    help::setLabelBackground(ui->label_2,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_3,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_4,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_5,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_6,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_7,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_8,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_9,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_10,QColor(41,147,204),Qt::white);
    help::setLabelBackground(ui->label_11,QColor(41,147,204),Qt::white);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    ui->express->setPalette(pe);
    ui->package_2->setPalette(pe);
    ui->label_2->installEventFilter(this);
    ui->label_4->installEventFilter(this);
    ui->label_3->installEventFilter(this);
    ui->label_5->installEventFilter(this);
    ui->label_6->installEventFilter(this);
    ui->label_7->installEventFilter(this);
    ui->label_8->installEventFilter(this);
    ui->label_9->installEventFilter(this);
    ui->label->installEventFilter(this);\
    ui->label_10->installEventFilter(this);
    ui->label_11->installEventFilter(this);
    _packagein=new packagein();
    _packageout=new packageout();
    _packagequery=new packagequery();
    _packagecheck=new packagecheck();
    _expressmail=new expressmail();
    _expressquery=new expressquery();
    _unpaidquery=new unpaidquery();
    _expresspay=new expresspay () ;
    _entryerror=new entryerror ();
    connect(_packagein,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_packageout,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_packagequery,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_packagecheck,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_expressmail,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_expressquery,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_unpaidquery,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_expresspay,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_entryerror,SIGNAL(showMain()),this,SLOT(showMainshow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj==ui->label_2)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _packagein->show();
            return true;
        }
    }
    else if(obj==ui->label_4)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _packageout->show();
            return true;
        }
    }
    else if(obj==ui->label_3)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _packagequery->show();
            return true;
        }
    }
    else if(obj==ui->label_5)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _packagecheck->refresh();
            _packagecheck->show();
            return true;
        }
    }
    else if(obj==ui->label_6)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _expressmail->show();
            return true;
        }
    }
    else if(obj==ui->label_7)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _expressquery->show();
            return true;
        }
    }
    else if(obj==ui->label_8)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _unpaidquery->refresh();
            _unpaidquery->show();
            return true;
        }
    }
    else if(obj==ui->label_9)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
           this->hide();
            _expresspay->refresh();
            _expresspay->show();
            return true;
        }
    }
    else if(obj==ui->label)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
           this->hide();
           _entryerror->show();
            return true;
        }
    }
    else if(obj==ui->label_10)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            bool save=binarySerialize::saveSTLObject<list<package>, package>(path.toStdString(), dataOperation::allPackage);
            bool save2=binarySerialize::saveSTLObject<list<express>, express>(path.toStdString()+"2", dataOperation::allExpress);
            if(save&&save2)
                QMessageBox::information(this,"提示","未保存成功");
            else
                QMessageBox::information(this,"提示","保存成功");
            return true;
        }
    }
    else if(obj==ui->label_11)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            bool read=binarySerialize::loadSTLObject<list<package>, package>(path.toStdString(), dataOperation::allPackage);
            bool read2=binarySerialize::loadSTLObject<list<express>, express>(path.toStdString()+"2", dataOperation::allExpress);
            if(read&&read2)
                QMessageBox::information(this,"提示","未读取成功");
            else
                QMessageBox::information(this,"提示","读取成功");
            return true;
        }
    }
    return false;
}

void MainWindow::showMainshow()
{
    this->show();
}
