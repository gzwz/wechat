#ifndef LISTWIDGET_CHATNOW_H
#define LISTWIDGET_CHATNOW_H

#include <QWidget>
#include <QListWidget>
#include <QMouseEvent>
#include <ui/iteminfo.h>
#include <QListWidgetItem>
#include <QList>
#include <user/user.h>
#include <user/userdao.h>

class ListWidget_chatNow : public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget_chatNow(QWidget *parent = 0);

signals:
    void oneUserbeClicked(User &user);

public slots:
    void dealItemClicked(QListWidgetItem *item);


protected:

private:
    //ItemInfo item;
    QList <User*> chatnowList;
    UserDao userDao;
};

#endif // LISTWIDGET_CHATNOW_H
