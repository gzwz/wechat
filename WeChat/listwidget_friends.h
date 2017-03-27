#ifndef LISTWIDGET_FRIENDS_H
#define LISTWIDGET_FRIENDS_H

#include <QWidget>
#include <QListWidget>
#include <QMouseEvent>
#include <ui/iteminfo.h>
#include <QListWidgetItem>
#include <QList>
#include <user/user.h>
#include <user/userdao.h>

class ListWidget_friends : public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget_friends(QWidget *parent = 0);

signals:
    void oneUserbeClicked(User &user);

public slots:
    void dealItemClicked(QListWidgetItem *item);


private:
    QList <User*> uList;
    UserDao userDao;
    //ItemInfo *item;

};

#endif // LISTWIDGET_FRIENDS_H
