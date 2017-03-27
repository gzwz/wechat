#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MyTcpSocket( qint32 socketDescriptor,QObject *parent = 0);

signals:
    void receiveData(qint32 socketDescriptor,const QByteArray &buf);

    void socketDisconnect( qint32 socketDescriptor);

public slots:

protected:
};

#endif // MYTCPSOCKET_H
