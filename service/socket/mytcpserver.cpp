#include "mytcpserver.h"
#include <QDebug>
#include <QThread>
#include "mytcpsocket.h"
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <db/dbutil.h>


MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    clients = new QMap< qint32, MyTcpSocket *> ();
}

void MyTcpServer::incomingConnection( qint32 socketDescriptor)
{
    qDebug()<<"有新的链接 -socketDescriptor-"<<socketDescriptor;
    MyTcpSocket *tcptemp = new MyTcpSocket(socketDescriptor);
    //QThread *thread = new QThread(tcptemp);
    //收到客户端发送的信息
    connect(tcptemp,&MyTcpSocket::receiveData,this,&MyTcpServer::receiveDataSlot);
    //客户端断开链接
    connect(tcptemp,&MyTcpSocket::socketDisconnect,this,&MyTcpServer::disconnectSlot);
    //客户端断开链接 关闭线程
    //connect(tcptemp,&MyTcpSocket::disconnected,thread,&QThread::quit);
    //向socket发送信息
   // connect(this,&MyTcpServer::,tcptemp,&MyTcpSocket::sendData);

    //tcptemp->moveToThread(thread);
    //thread->start();
    clients->insert(socketDescriptor,tcptemp);
    emit oneConnected();
    qDebug()<<clients->size();
}


void MyTcpServer::receiveDataSlot(const qint32 socketDescriptor,const QByteArray &buf)
{
    //根据数据actionType 类型判断客服端行为
    //{\"actionType\":\"login\",\"data\":{\"name\":\"小明\",\"pwd\":\"123456\"}}
    qDebug()<<"客服端说：" <<" buf= "<<QString(buf);
    emit socketSay(buf);
    QJsonObject json = QJsonDocument::fromJson(buf).object();
    if (json.value("actionType").toString() == QString("login")) {
        //这里可以处理客户端逻辑 验证能否登陆
        json = json.value("data").toObject();
        user = new User();
        user->setName(json.value("name").toString());
        user->setPwd(json.value("pwd").toString());
        friends = new QList<friendShip>();
        MyTcpSocket *tcptemp = clients->value(socketDescriptor);
        if (loginHandle(*user,*friends)) {

            QByteArray ba = QJsonDocument(toJson(*user,*friends)).toJson(QJsonDocument::Indented);
            //QJsonObject json = QJsonDocument::fromJson(ba).object();
            //qDebug() << "服务器处理即将返回  json =" <<json;
            tcptemp->write(ba);
        }else {
            tcptemp->write(QJsonDocument(toBackFailedJson()).toJson());
        }
        delete user;
        user = nullptr;

    }
}
void MyTcpServer::disconnectSlot( qint32 socketDescriptor)
{
    int i = clients->remove(socketDescriptor);
    qDebug()<<"删除客户端   i="<<i;
    emit onedisconnect();
}

bool MyTcpServer::loginHandle(User &user,QList<friendShip> &friendList)
{
        DBUtil::getQSqlDatabase();

        QSqlQuery query;
        QString sql = QString("SELECT id,userName,password,"
                   "nickName,createTime,phone,email,signature,headPicture,"
                   "grade FROM user WHERE userName ='%1' AND password ='%2' ")
                .arg(user.getName()).arg(user.getPwd());
        bool isq = query.exec(sql);

        //qDebug()<<"查询："<<isq ;
        while (query.next()) {
           //qDebug() <<query.value("userName").toString();
           user.setId(query.value("id").toString());
           user.setName(query.value("userName").toString());
           //user.setPwd(query.value("password").toString());
           user.setNickName(query.value("createTime").toString());
           user.setCateTime(query.value("nickName").toString());
           user.setPhone(query.value("phone").toString());
           user.setEmail(query.value("email").toString());
           user.setSignature(query.value("signature").toString());
           user.setHeadPicture(query.value("headPicture").toString());
           user.setNickName(query.value("grade").toString());
           user.setGrade(query.value("nickName").toString());
        }
        if (user.getId().isEmpty()) {
            return false;
        }else{
          QString sql1 = QString("SELECT id, selfId, firendId, remark, "
                   "orderBy FROM friendShip WHERE selfId = '%1'")
                   .arg(user.getId());
           query.exec(sql1);
           while (query.next()) {
               fs = new friendShip();
               fs->setId(query.value("id").toString());
               fs->setSelfId(query.value("selfId").toString());
               fs->setFirendId(query.value("firendId").toString());
               fs->setRemark(query.value("remark").toString());
               fs->setOrderBy(query.value("orderBy").toString());
               friendList.append((*fs));
           }
        }
        return true;
}

QJsonObject MyTcpServer::toJson(User &user,QList<friendShip> &friendList)
{
    QJsonObject rootjson;
    rootjson.insert("flag",true);
    QJsonObject datajson ;
    QJsonObject userjson ;
    QJsonObject friendsjson;
    userjson.insert("id",user.getId());
    userjson.insert("name",user.getName());
    //userjson.insert("password",user.getPwd());
    userjson.insert("createTime",user.getCateTime());
    userjson.insert("nickName",user.getNickName());
    userjson.insert("phone",user.getPhone());
    userjson.insert("email",user.getEmail());
    userjson.insert("signature",user.getSignature());
    userjson.insert("headPicture",user.getHeadPicture());
    userjson.insert("grade",user.getGrade());
    userjson.insert("nickName",user.getName());
    foreach (friendShip fs, friendList) {
        QJsonObject fsjson ;
        fsjson.insert("id",fs.getId());
        fsjson.insert("selfId",fs.getSelfId());
        fsjson.insert("firendId",fs.getFirendId());
        fsjson.insert("orderBy",fs.getOrderBy());
        fsjson.insert("remark",fs.getRemark());
        friendsjson.insert(fs.getFirendId(),fsjson);
    }
    datajson.insert("user",userjson);
    datajson.insert("friends",friendsjson);
    rootjson.insert("data",datajson);
    return rootjson;
}

QJsonObject MyTcpServer::toBackFailedJson()
{
    QJsonObject rootjson;
    rootjson.insert("flag",false);
    rootjson.insert("data","");
    return rootjson;
}

