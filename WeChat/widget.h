#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <mainwindow.h>
#include <net/networker.h>
#include <user/user.h>
#include <net/socketmanager.h>
#include <user/friendship.h>
#include <QList>
#include <QSystemTrayIcon>

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

    void on_errBackButton_clicked();

    void activated(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::Widget *ui;
    MainWindow *mw;
    bool flag = false;
};

#endif // WIDGET_H
