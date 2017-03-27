#include "lefttoolbar.h"
#include <QPalette>

LeftToolBar::LeftToolBar(QWidget *parent) : QWidget(parent)
{

    QPalette palette;
    palette.setColor(QPalette::Background, QColor("#3E3E40"));
    this->setPalette(palette);
}

void LeftToolBar::mousePressEvent(QMouseEvent *e)
{

    if (Qt::LeftButton == e->button()) {
        leftBtnClk = true;
        startPos = e->globalPos();
        clickPos = mapToParent(e->pos());
    }
    e->ignore();

}

void LeftToolBar::mouseMoveEvent(QMouseEvent *e)
{

    //获取屏幕尺寸
    int x = deskrect.width();
    int y = deskrect.height();
    QPoint temp = e->globalPos();
    if (temp.x() >= x-20) {
        temp.setX(x-40);
    }
    if (temp.y() >= y-20) {
        temp.setY(y-20);
    }
    if (temp.x() < 20) {
        temp.setX(20);
    }if (temp.y() < 20) {
        temp.setY(20);
    }
    if (leftBtnClk) {
        this->parentWidget()->move(temp - clickPos);
    }
    e->ignore();
}

void LeftToolBar::mouseReleaseEvent(QMouseEvent *e)
{
    leftBtnClk = false;
    e->ignore();
}
