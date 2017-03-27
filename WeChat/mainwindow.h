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


namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(User &user,QWidget *parent = 0);
    ~MainWindow();

    void initListView();

private slots:
    void on_closeButton_clicked();
    void connected();

    void on_headportrait_clicked();

    void on_b_chatNow_clicked();

    void initbuttons();

    void on_b_friendList_clicked();

    void oneUserbeClicked(User &user);

    void on_sendMessageButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket = NULL;

    QList<QWidget *> chatNowList;
 //   ItemInfo *item;
 //   QList <User*> uList;

    User *user;
    UserDao userDao;

};

#endif // MAINWINDOW_H
