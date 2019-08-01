#include "QTitleBarDemo.h"
#include "testwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTitleBarDemo w;
    w.show();

    return a.exec();
}
