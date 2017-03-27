#ifndef LEFTTOOLBAR_H
#define LEFTTOOLBAR_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>

class LeftToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit LeftToolBar(QWidget *parent = 0);

signals:

public slots:

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPoint startPos;
    QPoint clickPos;
    bool leftBtnClk = false;

    QDesktopWidget *dwsktopwidget = QApplication::desktop();
    QRect deskrect = dwsktopwidget->availableGeometry();
    QRect screenrect = dwsktopwidget->screenGeometry();


};

#endif // LEFTTOOLBAR_H
