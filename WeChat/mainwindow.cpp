#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <widget.h>
#include <QByteArray>
#include <QHostAddress>
#include <QIODevice>
#include <QMessageBox>
#include <QThread>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <signal/jsonsignal.h>
#include <QDialog>
#include <QLabel>
#include <dialog/selfuserinfo.h>
#include <QIcon>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <db/dbutil.h>

#include <QNetworkDatagram>




MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->b_chatNow->setIcon(QPixmap(":/images/img/chatNow02.png"));
    //初始化ListView 打开就显示chatnow页面
    ui->stackedWidget->setCurrentIndex(0);
    //
    initSocket();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost,2425);
    udpSocket->connectToHost("127.0.0.1",2425,QIODevice::ReadWrite);
    QString str = "1:100:WINDX-PC:WINDX-PC:32:AAAAAA~~";
    qDebug()<< str;
    udpSocket->write(str.toUtf8());
    udpSocket->flush();
//    connect(udpSocket, SIGNAL(readyRead()),
//                  this, SLOT(readPendingDatagrams()));
}

void MainWindow::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
             QNetworkDatagram datagram = udpSocket->receiveDatagram();
    }
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
    this->destroy();

}
void MainWindow::on_headportrait_clicked()
{
    SelfUserInfo info(this);
    info.show();
    info.exec();
}


void MainWindow::initbuttons()
{
 ui->b_chatNow->setIcon(QPixmap(":/images/img/chatNow01.png"));
 ui->b_friendList->setIcon(QPixmap(":/images/img/friend01.png"));
}

void MainWindow::on_b_chatNow_clicked()
{
    ui->b_chatNow->setIcon(QIcon(":/images/img/chatNow02.png"));
    ui->stackedWidget->setCurrentWidget(ui->chat_now);
}


void MainWindow::on_b_friendList_clicked()
{
    initbuttons();
    ui->b_friendList->setIcon(QPixmap(":/images/img/friend02.png"));
    ui->stackedWidget->setCurrentWidget(ui->friends);

}

void MainWindow::oneUserbeClicked(User &user)
{
    qDebug()<<"主界面获取user"<<user.getNickName();
    ui->titlelabel->setText(user.getNickName());

}

//消息发送按钮
void MainWindow::on_sendMessageButton_clicked()
{
    ui->msgContentEditArea->setText("");
}
