#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setWindowTitle("微聊");
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    ui->errwidget->hide();
}

Widget::~Widget()
{
    delete ui;
//    if (net != NULL) {
//        delete net;
//        net = NULL;
//    }
//    if (mw != NULL) {
//        delete mw;
//        mw = NULL;
//    }

}


void Widget::on_closeButton_clicked()
{


    this->close();
    //this->destroy();
}

void Widget::on_loginButton_clicked()
{
//    QString username = ui->userName->text();
//    QString pwd = ui->password->text();
//    if (username.isEmpty()) {
//        ui->userName->setPlaceholderText("请输入用户名");
//        return;
//    }
//    if (pwd.isEmpty()) {
//        ui->password->setPlaceholderText("请输入密码");
//        return;
//    }
//    this->setAutoFillBackground(true);
//    QLabel *tx = ui->headIcon;

//    tx->setAutoFillBackground(true);
//    if (flag) {
//        QPixmap pixmap(":/images/img/tx2.jpg");
//        tx->setPixmap(pixmap);
//        flag = false;
//    }else {
//        QPixmap pixmap(":/images/img/tx.jpg");
//        tx->setPixmap(pixmap);
//        flag = true;
//    }

//    net = new NetWorker();
//    QString url = QString("http://127.0.0.1:8080/WeChat/login?");
//    QString data = QString("name=%1&pwd=%2").arg(username).arg(pwd);
//    net->loginPost(url,data.toUtf8());

//    connect(net,NetWorker::httpPostBack,this,&Widget::startLogin);
    user = new User();
    mw = new MainWindow((*user));
    mw->setWindowTitle("微聊");
    mw->show();
    this->close();

}

void Widget::startLogin(const QByteArray &buf){
    user = new User();

    QJsonObject json = QJsonDocument::fromJson(buf).object();
    if (json.value("flag").toBool()) {//说明返回成功
        json = json.value("data").toObject();
        //user->setName(json.value("name").toString());
        //user->setPwd(json.value("pwd").toString());
        mw = new MainWindow((*user));
        mw->show();
        this->close();
    }else {
        ui->password->setText("");
        ui->errmessage->setText("用户名或者密码错误");
        ui->contentwidget->hide();
        ui->errwidget->show();
    }
}

void Widget::on_errBackButton_clicked()
{
    ui->contentwidget->show();
    ui->errwidget->hide();
}
