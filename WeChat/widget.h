#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <mainwindow.h>
#include <net/networker.h>
#include <user/user.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals:

private slots:

    void on_closeButton_clicked();

    void on_loginButton_clicked();

    void startLogin(const QByteArray &buf);

    void on_errBackButton_clicked();

private:
    Ui::Widget *ui;
    MainWindow *mw;
    bool flag = false;
    User *user;
    NetWorker *net;

};

#endif // WIDGET_H
