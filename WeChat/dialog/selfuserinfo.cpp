#include "selfuserinfo.h"
#include <QLabel>


SelfUserInfo::SelfUserInfo(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("微聊");
    this->setGeometry(parent->geometry().x()+50,parent->geometry().y()+35,200,250);
    this->setMinimumSize(200,250);
    this->setMaximumSize(200,250);
    QLabel *head = new QLabel(this);
    head->setPixmap(QPixmap(":/images/img/tx.jpg"));
    head->setMinimumSize(100,100);
    head->setMaximumSize(200,200);
    QLabel *info = new QLabel(this);
    info->setText("ID：WY568602044 \n地区： 贵州 贵阳");
    info->setGeometry(10,200,200,50);


}

SelfUserInfo::~SelfUserInfo()
{

}
