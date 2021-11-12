#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QHostAddress>
#include <QDebug>
#include <QStringList>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setWindowTitle("微聊");
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    ui->errwidget->hide();
    QSystemTrayIcon *s = new QSystemTrayIcon(this);
    s->setIcon(QIcon(":/images/img/2.ico"));
    s->show();
    s->setToolTip("微聊");
    //托盘图标激活
    connect(s,QSystemTrayIcon::activated,this,activated);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_closeButton_clicked()
{

    this->close();
    this->destroy();
}

void Widget::on_loginButton_clicked()
{
    mw = new MainWindow();
    mw->setWindowTitle("微聊");
    mw->show();
    this->close();

}

void Widget::on_errBackButton_clicked()
{
    ui->contentwidget->show();
    ui->errwidget->hide();
}


void Widget::activated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        setWindowState(Qt::WindowActive);
        activateWindow();

        break;
    default:
        break;
    }
}
