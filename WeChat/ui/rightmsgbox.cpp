#include "rightmsgbox.h"
#include "ui_rightmsgbox.h"

RightMsgBox::RightMsgBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightMsgBox)
{
    ui->setupUi(this);
}

RightMsgBox::~RightMsgBox()
{
    delete ui;
}
