#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QThread>
#include <socket/mytcpserver.h>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();


signals:
private slots:
    void on_startService_clicked();
    void on_stopService_clicked();
    void socketSay(const QByteArray &buf);

private:
    Ui::MainWidget *ui;
    MyTcpServer *myServer;
    myUdpServer

};

#endif // MAINWIDGET_H
