#ifndef RIGHTMSGBOX_H
#define RIGHTMSGBOX_H

#include <QWidget>

namespace Ui {
class RightMsgBox;
}

class RightMsgBox : public QWidget
{
    Q_OBJECT

public:
    explicit RightMsgBox(QWidget *parent = 0);
    ~RightMsgBox();

private:
    Ui::RightMsgBox *ui;
};

#endif // RIGHTMSGBOX_H
