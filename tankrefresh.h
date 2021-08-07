#ifndef TANKREFRESH_H
#define TANKREFRESH_H

#include <QThread>
#include "tankwidget.h"

class TankRefresh : public QThread
{
public:
    TankWidget *w;
    TankRefresh();
protected:
    void run();
};

#endif // TANKREFRESH_H
