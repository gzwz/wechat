#include "userdao.h"
#include <db/dbutil.h>
#include <QDebug>

UserDao::UserDao(QObject *parent) : QObject(parent)
{
    DBUtil::getQSqlDatabase();
}
 //获取所有好友的列表
QList<User *> UserDao::getUserList()
{

    QSqlQuery query  ;
    bool isq = query.exec("SELECT id,userName,password,"
                          "nickName,createTime,phone,"
                          "email,signature,headPicture,"
                          "grade FROM user;");
    qDebug()<<"user查询："<<isq;
    QList <User*> uList;
    User *user;
    while (query.next()) {
        user = new User();
        user->setId(query.value(0).toString());
        user->setName(query.value(1).toString());
        user->setPwd(query.value(2).toString());
        user->setNickName(query.value(3).toString());
        user->setCateTime(query.value(4).toDate());
        user->setPhone(query.value(5).toString());
        user->setEmail(query.value(6).toString());
        user->setSignature(query.value(7).toString());
        user->setHeadPicture(query.value(8).toString());
        user->setGrade(query.value(9).toString());
        uList.append(user);
    }
    return uList;
}

//获取正在聊天的列表
QList<User *> UserDao::getChatNowUserList()
{
    QSqlQuery query;
    bool isq = query.exec("SELECT u.id, u.userName,u.password,"
                          "u.nickName,u.createTime,u.phone,"
                          "u.email,u.signature,u.headPicture,u.grade "
                          "FROM "
                          "user u JOIN chat_now_user"
                          " cnu ON u.id = cnu.userId");
    qDebug()<<"chat_now_user查询"<<isq;
    QList <User*> uList;
    User *user;
    while (query.next()) {
        user = new User();
        user->setId(query.value(0).toString());
        user->setName(query.value(1).toString());
        user->setPwd(query.value(2).toString());
        user->setNickName(query.value(3).toString());
        user->setCateTime(query.value(4).toDate());
        user->setPhone(query.value(5).toString());
        user->setEmail(query.value(6).toString());
        user->setSignature(query.value(7).toString());
        user->setHeadPicture(query.value(8).toString());
        user->setGrade(query.value(9).toString());
        uList.append(user);
    }
    return uList;
}
