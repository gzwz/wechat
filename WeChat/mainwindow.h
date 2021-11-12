#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTcpSocket>
#include <QListWidget>
#include <ui/iteminfo.h>
#include <QList>
#include <user/user.h>
#include <user/userdao.h>
#include <listwidget_chatnow.h>
#include <net/socketmanager.h>
#include <user/friendship.h>
#include <QUdpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void initSocket();

    void initbuttons();

    void on_b_chatNow_clicked();

    void on_headportrait_clicked();

    void readPendingDatagrams();

    void on_closeButton_clicked();

    void on_b_friendList_clicked();

    void oneUserbeClicked(User &user);

    void on_sendMessageButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<friendShip> * fris;
    QList<QWidget *> chatNowList;

    QUdpSocket *udpSocket;
 //   ItemInfo *item;
 //   QList <User*> uList;

    User *user;
 //   UserDao userDao;

};

#endif // MAINWINDOW_H
