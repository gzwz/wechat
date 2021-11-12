#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H
#include <QString>


class friendShip
{
public:
    friendShip();

    QString getId() const;
    void setId(const QString &value);

    QString getSelfId() const;
    void setSelfId(const QString &value);

    QString getFirendId() const;
    void setFirendId(const QString &value);

    QString getRemark() const;
    void setRemark(const QString &value);

    QString getOrderBy() const;
    void setOrderBy(const QString &value);

private:
    QString id;
    QString selfId;
    QString firendId;
    QString remark;
    QString orderBy;
};

#endif // FRIENDSHIP_H
