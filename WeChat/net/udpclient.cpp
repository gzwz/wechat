#include "udpclient.h"

#include <QUdpSocket>

UdpClient::UdpClient()
{

}

void UdpClient::readdata(QUdpSocket *udpSocket)
{

    while (udpSocket->hasPendingDatagrams()) {
        QByteArray buf = udpSocket->read(udpSocket->pendingDatagramSize());
        //udpSocket->receiveDatagram(udpSocket->pendingDatagramSize());
        //QNetworkDatagram datagram = udpSocket->receiveDatagram();
         qDebug()<<" buff = " <<QString(buf);
    }

}
