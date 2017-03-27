#ifndef USER_H
#define USER_H
#include <QString>
#include <QDate>
#include <QString>
#include <QDate>


class User
{
public:
    User();




    QString getId() const;
    void setId(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getPwd() const;
    void setPwd(const QString &value);

    QString getNickName() const;
    void setNickName(const QString &value);

    QString getSignature() const;
    void setSignature(const QString &value);

    QDate getCateTime() const;
    void setCateTime(const QDate &value);

    QString getGrade() const;
    void setGrade(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getPhone() const;
    void setPhone(const QString &value);

    QString getHeadPicture() const;
    void setHeadPicture(const QString &value);

private:
    QString id;         //  id
    QString name;       //  用户名 登陆
    QString pwd;        //  密码
    QString nickName;   //  昵称
    QString signature;  //  签名
    QDate cateTime;     //  创建时间
    QString grade;      //  等级
    QString email;      //  邮箱
    QString phone;      //  电话
    QString headPicture;//  头像



};

#endif // USER_H
