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

    DBUtil::getQSqlDatabase();
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("E:/Qt/wechat/wechat.db");

//    bool ok = db.open();
//    qDebug()<<"数据库链接："<<ok;
    QSqlQuery query;
    bool isq = query.exec("SELECT * FROM user");
    qDebug()<<"查询："<<isq;
    while (query.next()) {
       qDebug()<<query.value("id").toString()
               <<query.value("username").toString();


    }

}

MainWidget::~MainWidget()
{
    delete ui;

}


void MainWidget::on_startService_clicked()
{
    myServer = new MyTcpServer(this);
    myServer->listen(QHostAddress::Any,9999);
    ui->startService->setEnabled(false);
    ui->stopService->setEnabled(true);

}
void MainWidget::on_stopService_clicked()
{
    ui->startService->setEnabled(true);
    ui->stopService->setEnabled(false);
    myServer->destroyed();

}



