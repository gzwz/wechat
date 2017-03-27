#include "networker.h"
#include <QNetworkReply>
#include <QDebug>
#include <QByteArray>



NetWorker::~NetWorker()
{

}


void NetWorker::loginPost(const QString &url,const QByteArray &data)
{

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    manager->post(request,data);
    connect(manager,&QNetworkAccessManager::finished,[=](QNetworkReply *reply){
        if (QNetworkReply::NoError != reply->error()) {
            qDebug()<<"reply->errorString()=="<<reply->errorString();
        }
        emit httpPostBack(reply->readAll());
    });
}

NetWorker::NetWorker(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}
