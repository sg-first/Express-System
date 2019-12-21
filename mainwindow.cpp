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
    zt=new packagein ();
    xyt=new packageout ();
     xr=new packagequery ();
      xx=new packagecheck ();
       jj=new expressmail ();
       kk=new expressquery ();
       ll=new unpaidquery ();
    connect(zt,SIGNAL(show()),this,SLOT(showMainshow()));
    connect(xyt,SIGNAL(show_2()),this,SLOT(showMainshow()));
    connect(xr,SIGNAL(show_3()),this,SLOT(showMainshow()));
    connect(xx,SIGNAL(show_4()),this,SLOT(showMainshow()));
    connect(jj,SIGNAL(show_5()),this,SLOT(showMainshow()));
    connect(kk,SIGNAL(show_6()),this,SLOT(showMainshow()));
    connect(ll,SIGNAL(show_7()),this,SLOT(showMainshow()));

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
            zt->show();
        }
    }
    if(obj==ui->label_4)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            xyt->show();
        }
    }
    if(obj==ui->label_3)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            xr->show();
        }
    }
    if(obj==ui->label_5)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
           this->hide();
           xx->show();
        }
    }
    if(obj==ui->label_6)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            jj->show();
        }
    }
    if(obj==ui->label_7)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            kk->show();
        }
    }
    if(obj==ui->label_8)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->hide();
            ll->show();
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
