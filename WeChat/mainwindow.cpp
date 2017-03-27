#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <widget.h>
#include <QByteArray>
#include <QHostAddress>
#include <QIODevice>
#include <QMessageBox>
#include <QThread>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <signal/jsonsignal.h>
#include <QDialog>
#include <QLabel>
#include <dialog/selfuserinfo.h>
#include <QIcon>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <db/dbutil.h>



MainWindow::MainWindow(User &u,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->b_chatNow->setIcon(QPixmap(":/images/img/chatNow02.png"));
    //初始化ListView 打开就显示chatnow页面
    ui->stackedWidget->setCurrentIndex(0);
    //
    this->user = &u;
    //初始化2个listview
    //initListView();


    socket = new QTcpSocket();
    socket->connectToHost(QHostAddress("192.168.0.110"),9999,QTcpSocket::ReadWrite);
    connect(socket,&QTcpSocket::connected,this,&MainWindow::connected);
    connect(ui->listWidget_chatnow,&ListWidget_chatNow::oneUserbeClicked,this,&MainWindow::oneUserbeClicked);
    connect(ui->listWidget_friends,&ListWidget_friends::oneUserbeClicked,this,&MainWindow::oneUserbeClicked);


}

MainWindow::~MainWindow()
{
    delete ui;
    if (socket != NULL) {
        delete socket;
        socket = NULL;
    }
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
    this->destroy();

}

void MainWindow::connected()
{

    QJsonObject json;

    //json.insert("name",QJsonValue(user.getName()));
    //json.insert("pwd",QJsonValue(user.getPwd()));
    QByteArray b = JsonSignal::getUserInfo(json);
    socket->write(b.data());

    QByteArray buf2 = socket->readAll();
    qDebug()<<buf2;

}

void MainWindow::on_headportrait_clicked()
{
    SelfUserInfo info(this);
    info.show();
    info.exec();
}


void MainWindow::initbuttons()
{
 ui->b_chatNow->setIcon(QPixmap(":/images/img/chatNow01.png"));
 ui->b_friendList->setIcon(QPixmap(":/images/img/friend01.png"));
}

void MainWindow::on_b_chatNow_clicked()
{
    initbuttons();
    ui->b_chatNow->setIcon(QIcon(":/images/img/chatNow02.png"));
    ui->stackedWidget->setCurrentWidget(ui->chat_now);
}


void MainWindow::on_b_friendList_clicked()
{
    initbuttons();
    ui->b_friendList->setIcon(QPixmap(":/images/img/friend02.png"));
    ui->stackedWidget->setCurrentWidget(ui->friends);

}

void MainWindow::oneUserbeClicked(User &user)
{
    qDebug()<<"主界面获取user"<<user.getNickName();
    ui->titlelabel->setText(user.getNickName());

}

//消息发送按钮
void MainWindow::on_sendMessageButton_clicked()
{
    ui->msgContentEditArea->setText("");
}
