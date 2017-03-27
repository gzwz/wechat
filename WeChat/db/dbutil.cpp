#include "dbutil.h"

#include <QDebug>

DBUtil::DBUtil(QObject *parent) : QObject(parent)
{

}

QSqlDatabase DBUtil::getQSqlDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
         db.setDatabaseName("../wechatclient.db");

         bool ok = db.open();
        qDebug()<<"数据库链接："<<ok;

//        QSqlQuery query;
//        bool isq = query.exec("SELECT * FROM user;");
//        qDebug()<<"数据库链接："<<isq;
//        while (query.next()) {

//            qDebug()<<query.value(0).toString()
//                    <<query.value(1).toString();

//        }

        return db;

}
