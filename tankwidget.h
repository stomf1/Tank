#ifndef TANKWIDGET_H
#define TANKWIDGET_H

#include <QMainWindow>
#include <QTouchEvent>
#include "tank.h"


typedef enum
{
    move_null,
    move_up,
    move_down,
    move_left,
    move_right
}move_direction;

class TankWidget : public QMainWindow
{
    Q_OBJECT

public:
    unsigned int TankSize;
    Tank mytank;
    int TankIdChoose = 0;
    move_direction m_dir = move_null;
    QPoint tou_lastposition;

    TankWidget(QWidget *parent = 0);
    ~TankWidget();
    void paintEvent(QPaintEvent *);
    void DrawTank(QPainter &p);



protected:
    void keyPressEvent(QKeyEvent *event);


private:
    bool event(QEvent *event);
};

#endif // TANKWIDGET_H
