#include "socketmanager.h"

SocketManager::SocketManager(QObject *parent) : QTcpSocket(parent)
{

    connect(this,&SocketManager::readyRead,[=](){
        QByteArray b = this->readAll();
        emit receiveData(b);
    });
    connect(this,&SocketManager::disconnected,[=](){
        emit socketDisconnect();
    });
}
