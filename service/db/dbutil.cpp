#include "dbutil.h"

#include <QDebug>

DBUtil::DBUtil(QObject *parent) : QObject(parent)
{

}

QSqlDatabase DBUtil::getQSqlDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
         db.setDatabaseName("../wechat.db");
         bool ok = db.open();
        qDebug()<<"数据库链接："<<ok;
        return db;
}
