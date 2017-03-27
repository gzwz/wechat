#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <user/user.h>

class NetWorker : public QObject
{
    Q_OBJECT
public:
    explicit NetWorker(QObject *parent = 0);
    ~NetWorker();
   static NetWorker*  getInstance();
   // static void get(const QString &url);
    void loginPost(const QString &url,const QByteArray &data);
signals:
 void httpPostBack(const QByteArray &buf);
public slots:

private:

    QNetworkAccessManager *manager;
    QNetworkRequest request;

};

#endif // NETWORKER_H
