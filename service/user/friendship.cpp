#include "friendship.h"

friendShip::friendShip()
{

}

QString friendShip::getId() const
{
    return id;
}

void friendShip::setId(const QString &value)
{
    id = value;
}

QString friendShip::getSelfId() const
{
    return selfId;
}

void friendShip::setSelfId(const QString &value)
{
    selfId = value;
}

QString friendShip::getFirendId() const
{
    return firendId;
}

void friendShip::setFirendId(const QString &value)
{
    firendId = value;
}

QString friendShip::getRemark() const
{
    return remark;
}

void friendShip::setRemark(const QString &value)
{
    remark = value;
}

QString friendShip::getOrderBy() const
{
    return orderBy;
}

void friendShip::setOrderBy(const QString &value)
{
    orderBy = value;
}
