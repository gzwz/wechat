#ifndef ITEMINFO_H
#define ITEMINFO_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>

namespace Ui {
class ItemInfo;
}

class ItemInfo : public QWidget
{
    Q_OBJECT

public:
    //explicit ItemInfo();
    explicit ItemInfo(QString id,QString headPicUrl,QString niceName,QString signName,QWidget *parent = 0);
    ~ItemInfo();

    QString getNiceName() const;
    void setNiceName(const QString &value);

    QString getId() const;
    void setId(const QString &value);

    QString getHeadPicUrl() const;
    void setHeadPicUrl(const QString &value);

    QString getSignName() const;
    void setSignName(const QString &value);

signals:
    void beClickedMe(QString id);
public slots:

private:
    Ui::ItemInfo *ui;

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private:
    QString id;
    QString headPicUrl;
    QString niceName;
    QString signName;


};

#endif // ITEMINFO_H
