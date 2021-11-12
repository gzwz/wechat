#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QMap>
#include <socket/mytcpsocket.h>
#include <QByteArray>
#include <user/user.h>
#include <user/friendship.h>
#include <QList>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);

signals:
    void readData();
    void onedisconnect();
    void oneConnected();
    void socketSay(const QByteArray &buf);

public slots:
    void receiveDataSlot(const qint32 socketDescriptor,const QByteArray &buf);
    void disconnectSlot(qint32 socketDescriptor);
public:
    bool loginHandle(User &user,QList<friendShip> &friendList);
    QJsonObject toJson(User &user,QList<friendShip>  &friendList);
    QJsonObject toBackFailedJson();


protected:
    void incomingConnection(qintptr handle);
private:
    QMap<qint32, MyTcpSocket *> *clients = NULL;
    User *user = nullptr;
    QList<friendShip> *friends = NULL;
    friendShip *fs = NULL;
};

#endif // MYTCPSERVER_H
