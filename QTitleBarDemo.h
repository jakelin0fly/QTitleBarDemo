#ifndef QTITLEBARDEMO_H
#define QTITLEBARDEMO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMenu>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public:
signals:
    void signalMinButtonClicked();    //点击最小化信号
    void signalRestoreButtonClicked();    //点击还原信号
    void signalMaxButtonClicked();    //点击最大化信号
    void signalCloseButtonClicked();    //点击关闭信号


private:
    QLabel *titleIconLabel;  //图标
    QLabel *titleText;  //标题栏 文本

    QMenu *menu;    //标题栏菜单
    QAction *userAction;    //用户信息
    QAction *settingAction; //设置
    QAction *aboutAction;   //关于

    QPushButton *minPushButton; //最小化
    QPushButton *restorePushButton; //还原
    QPushButton *maxPushButton;     //最大化
    QPushButton *closePushButton;   //关闭

    QPoint restorePoint;    //最大化前窗口位置
    QSize restoreSize;  //最大化前窗口大小

    QPoint mouseMoveStartPoint;  //鼠标点击移动起始位置

};

#endif // QTITLEBARDEMO_H
