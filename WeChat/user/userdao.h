#ifndef USERDAO_H
#define USERDAO_H

#include <QObject>
#include <user/user.h>
#include <QList>

class UserDao : public QObject
{
    Q_OBJECT
public:
    explicit UserDao(QObject *parent = 0);
    QList<User *> getUserList();
    QList<User *> getChatNowUserList();

signals:

public slots:

private:

};

#endif // USERDAO_H
