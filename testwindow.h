#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>

#include "QTitleBarDemo.h"

namespace Ui {
class TestWindow;
}

class TestWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = nullptr);
    ~TestWindow();

private:
    Ui::TestWindow *ui;

    QTitleBarDemo *myTitleBar;
};

#endif // TESTWINDOW_H
