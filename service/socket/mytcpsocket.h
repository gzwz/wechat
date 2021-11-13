#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MyTcpSocket( qint64 socketDescriptor,QObject *parent = 0);

signals:
    void receiveData(qint64 socketDescriptor,const QByteArray &buf);

    void socketDisconnect( qint64 socketDescriptor);

public slots:

protected:
};

#endif // MYTCPSOCKET_H
