#ifndef LISTWIDGET_CHATMSGCONTENT_H
#define LISTWIDGET_CHATMSGCONTENT_H

#include <QWidget>
#include <QListWidget>

class listWidget_chatMsgContent : public QListWidget
{
    Q_OBJECT
public:
    explicit listWidget_chatMsgContent(QWidget *parent = 0);

signals:

public slots:
};

#endif // LISTWIDGET_CHATMSGCONTENT_H
