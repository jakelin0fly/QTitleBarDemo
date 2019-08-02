#ifndef QTITLEBARDEMO_H
#define QTITLEBARDEMO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QString>
#include <QHBoxLayout>
#include <QPixmap>
#include <QSize>
#include <QFile>
#include <QMouseEvent>


class QTitleBarDemo : public QWidget
{
    Q_OBJECT

public:
    QTitleBarDemo(QWidget *parent = 0);
    ~QTitleBarDemo();

    //设置图标 以及大小
    void setTitleBarIcon(QPixmap &pix, QSize size = QSize(25, 25));
    //设置标题文本
    void setTitleBarText(QString text);
    //设置标题栏高度 宽度
    void setTitleBarHeight(int height);
    void setTitleBarWidth(int width);

    //设置样式
    void setTitleBarStyleSheet(QString path);

//重写鼠标响应事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
signals:
    void signalMinButtonClicked();    //点击最小化信号
    void signalRestoreButtonClicked();    //点击还原信号
    void signalMaxButtonClicked();    //点击最大化信号
    void signalCloseButtonClicked();    //点击关闭信号

    void signalStyleSheetLoadFail();    //样式表加载失败信号

private:
    void paintEvent(QPaintEvent *);     //重写painEvent

    void initMenu();    //初始化菜单
    void initElements();    //初始化控件元素
    void initConnections(); //初始化信号槽

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

    bool mouseIsPress = false;
    QPoint mouseMoveStartPoint;  //鼠标点击移动起始位置

};

#endif // QTITLEBARDEMO_H
