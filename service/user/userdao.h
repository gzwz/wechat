#ifndef USERDAO_H
#define USERDAO_H

#include <QObject>

class UserDao : public QObject
{
    Q_OBJECT
public:
    explicit UserDao(QObject *parent = 0);

signals:

public slots:
};

#endif // USERDAO_H