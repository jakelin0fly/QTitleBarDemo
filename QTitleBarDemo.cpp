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
 * @brief 初始化(new)标题栏控件元素
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

/**
 * @brief 初始化标题栏信号槽
 */
void QTitleBarDemo::initConnections(){
    connect(minPushButton, SIGNAL(clicked()), parent(), SLOT(minButtonClicked()));
    connect(restorePushButton, SIGNAL(clicked()), parent(), SLOT(restoreButtonClicked()));
    connect(maxPushButton, SIGNAL(clicked()), parent(), SLOT(maxButtonClicked()));
    connect(closePushButton, SIGNAL(clicked()), parent(), SLOT(closeButtonClicked()));
}

void QTitleBarDemo::paintEvent(QPaintEvent *even){
    setStyleSheet("color:red;");
    titleText->setText("text");
    titleIconLabel->setText("icon");
    minPushButton->setText("min");
    restorePushButton->setText("restore");
    maxPushButton->setText("max");
    closePushButton->setText("clsoe");
}


void QTitleBarDemo::mousePressEvent(QMouseEvent *event){
    mouseIsPress = true;
    mouseMoveStartPoint = event->globalPos();

    return QWidget::mousePressEvent(event);
}

void QTitleBarDemo::mouseMoveEvent(QMouseEvent *event){
    //若鼠标左键处于点击状态 移动父窗体
    if(mouseIsPress){
         QPoint movePoint = event->globalPos() - mouseMoveStartPoint;
         QPoint widgetPos = this->parentWidget()->pos();
         mouseMoveStartPoint = event->globalPos();
         this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }
}

void QTitleBarDemo::mouseReleaseEvent(QMouseEvent *event){
    mouseIsPress = false;

    return QWidget::mouseReleaseEvent(event);
}

/**
 * @brief 设置标题栏图标 图标大小
 * @param pix
 * @param size
 */
void QTitleBarDemo::setTitleBarIcon(QPixmap &pix, QSize size){
    titleIconLabel->setPixmap(pix.scaled(size));
}

/**
 * @brief 设置标题文本
 * @param text
 */
void QTitleBarDemo::setTitleBarText(QString text){
    titleText->setText(text);
}

void QTitleBarDemo::setTitleBarWidth(int width){
    this->setFixedWidth(width);
}

void QTitleBarDemo::setTitleBarHeight(int height){
    this->setFixedHeight(height);
}

void QTitleBarDemo::setTitleBarStyleSheet(QString path){
    QFile file(path);
    file.open(QFile::ReadOnly);
    //打开失败 发出信号
    if(file.isOpen()){
        emit signalStyleSheetLoadFail();
        return;
    }
    QString styleSheet = this->styleSheet();
    styleSheet += QString(file.readAll());
    this->setStyleSheet(styleSheet);
}


/************************  slots  **********************************/
void QTitleBarDemo::minButtonClicked(){
    emit signalMinButtonClicked();
}

void QTitleBarDemo::restoreButtonClicked(){
    isMaxed = false;
    emit signalRestoreButtonClicked();
}

void QTitleBarDemo::maxButtonClicked(){
    isMaxed = true;
    emit signalMaxButtonClicked();
}

void QTitleBarDemo::closeButtonClicked(){
    emit signalCloseButtonClicked();
}
