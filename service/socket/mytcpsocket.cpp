#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket( qint32 socketDescriptor,QObject *parent) : QTcpSocket(parent)
{
    this->setSocketDescriptor(socketDescriptor);

    connect(this,&MyTcpSocket::readyRead,[=](){
        QByteArray b = this->readAll();
        emit receiveData(socketDescriptor,b);
    });
    connect(this,&MyTcpSocket::disconnected,[=](){
       emit socketDisconnect(socketDescriptor);
    });

}
