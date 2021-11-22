#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QUdpSocket>



class UdpClient
{
public:
    UdpClient();


slots
    void readdata(QUdpSocket *udpSocket);
};

#endif // UDPCLIENT_H
