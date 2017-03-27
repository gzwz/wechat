#include "widget.h"
#include <QApplication>
#include <QPixmap>
#include <QIcon>
#include <QBitmap>
#include <mainwindow.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //w.setMask(QBitmap(400, 400));
    w.setWindowOpacity(1);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);

    w.show();



    return a.exec();
}
