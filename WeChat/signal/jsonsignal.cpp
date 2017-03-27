#include "jsonsignal.h"
#include <QJsonDocument>


JsonSignal::JsonSignal(QObject *parent) : QObject(parent)
{

}

QByteArray JsonSignal::getUserInfo(const QJsonObject &data)
{
    QJsonDocument doc;
    QJsonObject jo;
    jo.insert("actionType","getUserInfo");
    jo.insert("data",data);
    doc.setObject(jo);
    QByteArray buf = doc.toJson(QJsonDocument::Compact);
    return buf;

}
