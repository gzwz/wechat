#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QMap>
#include <QTcpSocket>
#include <QByteArray>


class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);

signals:
    void readData();


public slots:
    void receiveDataSlot(const qint32 socketDescriptor,const QByteArray &buf);
    void disconnectSlot(qint32 socketDescriptor);



protected:
    void incomingConnection(qintptr handle);
private:
    QMap<qint32, QTcpSocket *> *clients ;
};

#endif // MYTCPSERVER_H
