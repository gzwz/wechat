#include "listwidget_friends.h"

ListWidget_friends::ListWidget_friends(QWidget *parent) : QListWidget(parent)
{

    uList = userDao.getUserList();
    for (int i = 0; i < uList.size(); ++i) {
        QListWidgetItem *nitem = new QListWidgetItem(this);
        nitem->setSizeHint(QSize(0,60));
        ItemInfo *item = new ItemInfo(QString(i),uList.at(i)->getHeadPicture(),uList.at(i)->getNickName(),uList.at(i)->getSignature(),this);
        this->setItemWidget(nitem,item);
    }

    connect(this,&ListWidget_friends::itemClicked,this,&ListWidget_friends::dealItemClicked);
}

void ListWidget_friends::dealItemClicked(QListWidgetItem *item)
{
    //qDebug()<<"子类 item 被点击";
    //设置所有item的css为空
    for (int i = 0; i < this->count(); ++i) {
        this->itemWidget(this->item(i))->setStyleSheet("");
    }
    //设置被点击的item的颜色
    QWidget *info= this->itemWidget(item);
    info->setStyleSheet("background-color:rgb(188,219,198)");

    ItemInfo *iteminfo = qobject_cast<ItemInfo*>(this->itemWidget(item));
    User user;
    user.setNickName(iteminfo->getNiceName());
    user.setId(iteminfo->getId());
    user.setHeadPicture(iteminfo->getHeadPicUrl());
    user.setSignature(iteminfo->getSignName());
    emit oneUserbeClicked(user);
}
