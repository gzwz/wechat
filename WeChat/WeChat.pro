#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T13:26:48
#
#-------------------------------------------------

QT       += core gui
QT += network
CONFIG += c++11
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeChat
TEMPLATE = app



FORMS    += widget.ui \
    mainwindow.ui \
    ui/iteminfo.ui \
    ui/rightmsgbox.ui \
    ui/chatbubbleown.ui

RESOURCES += \
    images.qrc

RC_FILE= app.rc

HEADERS += \
    mainwindow.h \
    user/user.h \
    userentity.h \
    widget.h \
    dialog/selfuserinfo.h \
    net/networker.h \
    signal/jsonsignal.h \
    lefttoolbar.h \
    maintitlewindow.h \
    titlewindow.h \
    ui/iteminfo.h \
    listwidget_chatnow.h \
    db/dbutil.h \
    user/userdao.h \
    listwidget_friends.h \
    listwidget_chatmsgcontent.h \
    ui/rightmsgbox.h \
    ui/chatbubbleown.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    user/user.cpp \
    widget.cpp \
    dialog/selfuserinfo.cpp \
    net/networker.cpp \
    signal/jsonsignal.cpp \
    lefttoolbar.cpp \
    maintitlewindow.cpp \
    titlewindow.cpp \
    ui/iteminfo.cpp \
    listwidget_chatnow.cpp \
    db/dbutil.cpp \
    user/userdao.cpp \
    listwidget_friends.cpp \
    listwidget_chatmsgcontent.cpp \
    ui/rightmsgbox.cpp \
    ui/chatbubbleown.cpp

