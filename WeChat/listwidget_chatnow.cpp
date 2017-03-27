#include "listwidget_chatnow.h"
#include <QDebug>
#include <QBrush>



ListWidget_chatNow::ListWidget_chatNow(QWidget *parent) : QListWidget(parent)
{
    chatnowList = userDao.getChatNowUserList();
    //初始化当前ListView
    for (int i = 0; i < chatnowList.size(); ++i) {
        QListWidgetItem *nitem = new QListWidgetItem(this);
        nitem->setSizeHint(QSize(0,60));
        ItemInfo *item = new ItemInfo(QString(i),chatnowList.at(i)->getHeadPicture(),chatnowList.at(i)->getNickName(),chatnowList.at(i)->getSignature(),this);
        this->setItemWidget(nitem,item);
    }
    connect(this,&ListWidget_chatNow::itemClicked,this,&ListWidget_chatNow::dealItemClicked);

}

void ListWidget_chatNow::dealItemClicked(QListWidgetItem *item)
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




