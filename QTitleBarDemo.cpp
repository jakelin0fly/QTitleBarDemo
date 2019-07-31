#include "QTitleBarDemo.h"

QTitleBarDemo::QTitleBarDemo(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::Window |     //默认
                   Qt::FramelessWindowHint |    //去边框（原有的标题栏）
                   Qt::WindowMinimizeButtonHint);   //点击任务栏图标可最小化

    initElements();
}

QTitleBarDemo::~QTitleBarDemo()
{

}

/**
 * @brief 创建菜单项
 */
void QTitleBarDemo::initMenu(){
    menu = new QMenu;
    userAction = new QAction;
    settingAction = new QAction;
    aboutAction = new QAction;

    menu->addAction(userAction);
    menu->addAction(settingAction);
    menu->addAction(aboutAction);
}

/**
 * @brief 初始化标题栏控件元素
 */
void QTitleBarDemo::initElements(){
    //图标
    titleIconLabel = new QLabel;
    //文本
    titleText = new QLabel;

    //最小化
    minPushButton = new QPushButton;
    restorePushButton = new QPushButton;
    maxPushButton = new QPushButton;
    closePushButton = new QPushButton;

    //提示信息
    minPushButton->setToolTip(QString("最小化"));
    restorePushButton->setToolTip(QString("还原"));
    maxPushButton->setToolTip(QString("最大化"));
    closePushButton->setToolTip(QString("关闭"));

    initMenu();     //菜单

    //水平布局
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(titleIconLabel);
    layout->addWidget(titleText);

    layout->addWidget(menu);

    layout->addWidget(minPushButton);
    layout->addWidget(restorePushButton);
    layout->addWidget(maxPushButton);
    layout->addWidget(closePushButton);

    titleText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);   //水平方向延伸、垂直方向固定
}
