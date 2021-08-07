#ifndef TANKWIDGET_H
#define TANKWIDGET_H

#include <QMainWindow>
#include <QTouchEvent>
#include "tank.h"

class TankWidget : public QMainWindow
{
    Q_OBJECT

public:
    unsigned int TankSize;
    Tank mytank;
    int TankIdChoose = 0;

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
