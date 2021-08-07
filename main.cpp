#include "tankwidget.h"
#include "tankrefresh.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TankWidget w;
    w.show();
    TankRefresh t;
    t.w= &w;
    t.setObjectName("WindUpdate");
    t.start();
    return a.exec();
}
