#ifndef DBUTIL_H
#define DBUTIL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class DBUtil : public QObject
{
    Q_OBJECT
public:
    explicit DBUtil(QObject *parent = 0);
    static QSqlDatabase getQSqlDatabase();
signals:

public slots:

private:

};

#endif // DBUTIL_H
