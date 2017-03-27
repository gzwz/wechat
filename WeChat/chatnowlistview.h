#ifndef CHATNOWLISTVIEW_H
#define CHATNOWLISTVIEW_H

#include <QWidget>
#include <QListView>

class ChatNowListView : public QListView
{
    Q_OBJECT
public:
    explicit ChatNowListView(QWidget *parent = 0);

signals:

public slots:
};

#endif // CHATNOWLISTVIEW_H
