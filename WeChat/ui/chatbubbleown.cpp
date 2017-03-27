#include "chatbubbleown.h"
#include "ui_chatbubbleown.h"

ChatBubbleOwn::ChatBubbleOwn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatBubbleOwn)
{
    ui->setupUi(this);
}

ChatBubbleOwn::~ChatBubbleOwn()
{
    delete ui;
}
