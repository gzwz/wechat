#include "user.h"

User::User()
{

}

QString User::getId() const
{
    return id;
}

void User::setId(const QString &value)
{
    id = value;
}

QString User::getName() const
{
    return name;
}

void User::setName(const QString &value)
{
    name = value;
}

QString User::getPwd() const
{
    return pwd;
}

void User::setPwd(const QString &value)
{
    pwd = value;
}

QString User::getNickName() const
{
    return nickName;
}

void User::setNickName(const QString &value)
{
    nickName = value;
}

QString User::getSignature() const
{
    return signature;
}

void User::setSignature(const QString &value)
{
    signature = value;
}

QDate User::getCateTime() const
{
    return cateTime;
}

void User::setCateTime(const QDate &value)
{
    cateTime = value;
}

QString User::getGrade() const
{
    return grade;
}

void User::setGrade(const QString &value)
{
    grade = value;
}

QString User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &value)
{
    email = value;
}

QString User::getPhone() const
{
    return phone;
}

void User::setPhone(const QString &value)
{
    phone = value;
}

QString User::getHeadPicture() const
{
    return headPicture;
}

void User::setHeadPicture(const QString &value)
{
    headPicture = value;
}


