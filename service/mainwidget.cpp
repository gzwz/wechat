#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>
#include <QHostAddress>
#include <QDataStream>
#include <QByteArray>
#include <db/dbutil.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMapIterator>
#include <QVariant>


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->stopService->setEnabled(false);
}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::on_startService_clicked()
{
    myServer = new MyTcpServer(this);
    myServer->listen(QHostAddress::Any,ui->port->text().toInt());
    ui->status->setText("服务器开启");
    connect(myServer,&MyTcpServer::oneConnected,[=](){
        ui->onlineUserNum->display((ui->onlineUserNum->value())+1);
    });
    connect(myServer,&MyTcpServer::onedisconnect,[=](){
        ui->onlineUserNum->display((ui->onlineUserNum->value())-1);
    });
    connect(myServer,&MyTcpServer::socketSay,this,&MainWidget::socketSay);
    ui->startService->setEnabled(false);
    ui->stopService->setEnabled(true);

}
void MainWidget::on_stopService_clicked()
{
    ui->onlineUserNum->display(0);
    ui->status->setText("服务器关闭");
    ui->onlineUserNum->display(0);
    ui->startService->setEnabled(true);
    ui->stopService->setEnabled(false);
    myServer->close();
    myServer->destroyed();
    delete myServer;
    myServer = NULL;

}

void MainWidget::socketSay(const QByteArray &buf)
{
    ui->logshow->appendPlainText(QString(buf));
    ui->logshow->appendPlainText(QString("----------------------"));
}



