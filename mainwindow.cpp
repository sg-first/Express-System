#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QDebug"
#include "express.h"
#include"packagein.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->installEventFilter(this);
    ui->label_4->installEventFilter(this);
    ui->label_3->installEventFilter(this);
    ui->label_5->installEventFilter(this);
    ui->label_6->installEventFilter(this);
    ui->label_7->installEventFilter(this);
    ui->label_8->installEventFilter(this);
    ui->label_9->installEventFilter(this);
    _packagein=new packagein();
    _packageout=new packageout();
    _packagequery=new packagequery();
    _packagecheck=new packagecheck();
    _expressmail=new expressmail();
    _expressquery=new expressquery();
    _unpaidquery=new unpaidquery();
    connect(_packagein,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_packageout,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_packagequery,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_packagecheck,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_expressmail,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_expressquery,SIGNAL(showMain()),this,SLOT(showMainshow()));
    connect(_unpaidquery,SIGNAL(showMain()),this,SLOT(showMainshow()));

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
        }
    }
    if(obj==ui->label_4)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _packageout->show();
        }
    }
    if(obj==ui->label_3)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _packagequery->show();
        }
    }
    if(obj==ui->label_5)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _packagecheck->refresh();
            _packagecheck->show();
        }
    }
    if(obj==ui->label_6)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _expressmail->show();
        }
    }
    if(obj==ui->label_7)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _expressquery->show();
        }
    }
    if(obj==ui->label_8)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            _unpaidquery->show();
        }
    }
    if(obj==ui->label_9)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {

        }
    }
}

void MainWindow::showMainshow()
{
    this->show();
}
