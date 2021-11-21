#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T21:28:54
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = service
TEMPLATE = app
QT += sql


SOURCES += main.cpp\
        mainwidget.cpp \
    socket/mytcpserver.cpp \
    socket/mytcpsocket.cpp \
    socket/myudpserver.cpp \
    user/userdao.cpp \
    db/dbutil.cpp \
    user/user.cpp \
    user/friendship.cpp



HEADERS  += mainwidget.h \
    socket/mytcpserver.h \
    socket/mytcpsocket.h \
    socket/myudpserver.h \
    user/userdao.h \
    db/dbutil.h \
    user/user.h \
    user/friendship.h


FORMS    += mainwidget.ui


