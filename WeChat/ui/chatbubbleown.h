#ifndef CHATBUBBLEOWN_H
#define CHATBUBBLEOWN_H

#include <QWidget>

namespace Ui {
class ChatBubbleOwn;
}

class ChatBubbleOwn : public QWidget
{
    Q_OBJECT

public:
    explicit ChatBubbleOwn(QWidget *parent = 0);
    ~ChatBubbleOwn();

private:
    Ui::ChatBubbleOwn *ui;
};

#endif // CHATBUBBLEOWN_H
