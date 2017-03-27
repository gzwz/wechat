#include "titlewindow.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>

TitleWindow::TitleWindow(QWidget *parent) : QWidget(parent)
{

       // 不继承父组件的背景色
       setAutoFillBackground(true);
       //使用 Highlight 作为背景色
       setBackgroundRole(QPalette::Highlight);
       setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);


}
TitleWindow::~TitleWindow()
{
}



void TitleWindow::mousePressEvent(QMouseEvent *e)
{
    if (Qt::LeftButton == e->button()) {
        leftBtnClk = true;
    }
    startPos = e->globalPos();
    clickPos = mapToParent(e->pos());
    e->ignore();
}


void TitleWindow::mouseMoveEvent(QMouseEvent *e)
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
        this->parentWidget()->parentWidget()->move(temp - clickPos);
    }
    e->ignore();
}

void TitleWindow::mouseReleaseEvent(QMouseEvent *e){
    leftBtnClk = false;
    e->ignore();
}

