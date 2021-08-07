#ifndef TANK_H
#define TANK_H
#include <QPoint>

typedef enum
{
    dir_up,
    dir_down,
    dir_left,
    dir_right
}direction;


class Tank
{
public:
    QPoint p;

    direction d;
    Tank();
    ~Tank();
};

#endif // TANK_H
