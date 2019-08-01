#include "testwindow.h"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window |     //默认
//                   Qt::FramelessWindowHint |    //去边框（原有的标题栏）
                   Qt::WindowMinimizeButtonHint);   //点击任务栏图标可最小化

    myTitleBar = new QTitleBarDemo(this);
    myTitleBar->move(0, 0);
}

TestWindow::~TestWindow()
{
    delete ui;
}
