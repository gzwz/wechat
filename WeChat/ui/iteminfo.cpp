#include "iteminfo.h"
#include "ui_iteminfo.h"
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPalette>

ItemInfo::ItemInfo(QString id,QString headPicUrl,QString niceName,QString signName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemInfo)
{
    ui->setupUi(this);
    ui->label_pic->setPixmap(QPixmap(headPicUrl));
    ui->label_name->setText(niceName);
    ui->label_signal->setText(signName);

    this->id = id;
    this->headPicUrl = headPicUrl;
    this->niceName = niceName;
    this->signName = signName;

  //  connect(this,&ItemInfo::beClickedMe,this,&ItemInfo::initStyle);

}

ItemInfo::~ItemInfo()
{
    delete ui;
}




void ItemInfo::enterEvent(QEvent *)
{

    //this->setStyleSheet("background-color:rgb(216,219,222)");
}

void ItemInfo::leaveEvent(QEvent *)
{

   //this->setStyleSheet("background-color:rgb(188,219,198)");
}

QString ItemInfo::getSignName() const
{
    return signName;
}

void ItemInfo::setSignName(const QString &value)
{
    signName = value;
}

QString ItemInfo::getHeadPicUrl() const
{
    return headPicUrl;
}

void ItemInfo::setHeadPicUrl(const QString &value)
{
    headPicUrl = value;
}

QString ItemInfo::getId() const
{
    return id;
}

void ItemInfo::setId(const QString &value)
{
    id = value;
}

QString ItemInfo::getNiceName() const
{
    return niceName;
}

void ItemInfo::setNiceName(const QString &value)
{
    niceName = value;
}




