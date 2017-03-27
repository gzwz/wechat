#ifndef MAINTITLEWINDOW_H
#define MAINTITLEWINDOW_H

#include <QWidget>
#include <QRect>
#include <QDesktopWidget>
#include <QApplication>

class MainTitleWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainTitleWindow(QWidget *parent = 0);

protected:
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

signals:

public slots:

private:
      QPoint startPos;
      QPoint clickPos;
      bool leftBtnClk = false;

      QDesktopWidget *dwsktopwidget = QApplication::desktop();
      QRect deskrect = dwsktopwidget->availableGeometry();
      QRect screenrect = dwsktopwidget->screenGeometry();


};

#endif // MAINTITLEWINDOW_H
