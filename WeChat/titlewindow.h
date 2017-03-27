#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QWidget>
#include <QDesktopWidget>
#include <QRect>
#include <QApplication>
#include <QDebug>
#include <QString>


class TitleWindow : public QWidget
{
    Q_OBJECT
public:
    ~TitleWindow();
    explicit TitleWindow(QWidget *parent = 0);

signals:

public slots:

protected:

    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private:
      QPoint startPos;
      QPoint clickPos;
      bool leftBtnClk = false;

     QDesktopWidget *dwsktopwidget = QApplication::desktop();
     QRect deskrect = dwsktopwidget->availableGeometry();
     QRect screenrect = dwsktopwidget->screenGeometry();


};

#endif // TITLEWINDOW_H
