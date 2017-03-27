#include "mytcpserver.h"
#include <QDebug>
#include <QThread>
#include "mytcpsocket.h"
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>



MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    clients = new QMap< qint32, QTcpSocket *> ();
}

void MyTcpServer::incomingConnection( qint32 socketDescriptor)
{
    qDebug()<<"有新的链接 -socketDescriptor-"<<socketDescriptor;
    MyTcpSocket *tcptemp = new MyTcpSocket(socketDescriptor);
    QThread *thread = new QThread(tcptemp);
    //收到客户端发送的信息
    connect(tcptemp,&MyTcpSocket::receiveData,this,&MyTcpServer::receiveDataSlot);
    //客户端断开链接
    connect(tcptemp,&MyTcpSocket::socketDisconnect,this,&MyTcpServer::disconnectSlot);
    //客户端断开链接 关闭线程
    connect(tcptemp,&MyTcpSocket::disconnected,thread,&QThread::quit);
    //向socket发送信息
   // connect(this,&MyTcpServer::,tcptemp,&MyTcpSocket::sendData);
    tcptemp->moveToThread(thread);
    thread->start();
    clients->insert(socketDescriptor,tcptemp);

    qDebug()<<clients->size();
}


void MyTcpServer::receiveDataSlot(const qint32 socketDescriptor,const QByteArray &buf)
{
    //根据数据actionType 类型判断客服端行为
    //{\"actionType\":\"login\",\"data\":{\"name\":\"小明\",\"pwd\":\"123456\"}}
    qDebug()<<"客服端说：" <<" buf= "<<QString(buf);
//    QJsonObject json = QJsonDocument::fromJson(buf).object();
//    switch (json.value("actionType")) {
//    case 'login':

//        break;
//    default://命令错误
//        break;
//    }

}

void MyTcpServer::disconnectSlot( qint32 socketDescriptor)
{
    int i = clients->remove(socketDescriptor);
    qDebug()<<"删除客户端   i="<<i;
}

