#include "tankwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TankWidget w;
    w.show();
    return a.exec();
}
