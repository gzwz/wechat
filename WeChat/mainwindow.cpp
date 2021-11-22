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
#include <net/udpclient.h>
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

    QUdpSocket client ;
    client.connectToHost(QHostAddress::Broadcast,2425,QIODevice::ReadWrite);
    QString login = "1:100:wlz:wlz:IPMSG_BR_ENTRY:";
    login = "1:100:xm:xiaoming:32:Hello";
    client.write(login.toUtf8());
    client.flush();


    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Broadcast,2425);


    connect(udpSocket,
        SIGNAL(&QUdpSocket::readyRead), this, SLOT(&MainWindow::readdata(udpSocket)));


    QString msg = ui->msgContentEditArea->toPlainText();
//     qDebug()<<"发送的内容：" << msg;
//   // login = login.arg(msg);

//    qDebug()<< "登陆：" <<login;


//    char *buf = new char[1024];
//    QByteArray *result = new QByteArray();
//    qint64 len = 0;
//    while ( (len = udpSocket->read(buf,udpSocket->pendingDatagramSize())) != -1) {
//        result->append(buf);
//    }
//    QString str = QString(*result);

//    qDebug()<< "收到报文："<<str;
//
//     QObject::connect(udpSocket, SIGNAL(&QUdpSocket::readyRead),
//                  this, SLOT((&UdpClient::readdata(udpSocket))));

    ui->msgContentEditArea->setText("");
    ui->listWidget_chatMsgContent->addItem(msg);

}

 void MainWindow::readdata(QUdpSocket *client){
      qDebug() <<" QString(data)";
         char* data = new char[1024];
          client->readDatagram(data,client->pendingDatagramSize());
         qDebug() << QString(data);



}
