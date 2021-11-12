#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <QObject>
#include <QTcpSocket>

class SocketManager : public QTcpSocket
{
    Q_OBJECT
public:
    explicit SocketManager(QObject *parent = 0);

signals:
    void receiveData(const QByteArray &buf);
    void socketDisconnect();

public slots:

private:

};

#endif // SOCKETMANAGER_H
