#ifndef JSONSIGNAL_H
#define JSONSIGNAL_H

#include <QObject>
#include <QByteArray>
#include <QJsonObject>

class JsonSignal : public QObject
{
    Q_OBJECT
public:
    explicit JsonSignal(QObject *parent = 0);
    static QByteArray getUserInfo(const QJsonObject &data);

signals:

public slots:

};

#endif // JSONSIGNAL_H
