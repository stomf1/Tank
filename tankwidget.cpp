#include "tankwidget.h"
#include <QKeyEvent>
#include <QPainter>

TankWidget::TankWidget(QWidget *parent)
    : QMainWindow(parent)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    TankSize = 1;
    setMinimumSize(400,710);
    mytank.p.setX(200);
    mytank.p.setY(200);
    mytank.d=dir_right;
}

TankWidget::~TankWidget()
{

}
void TankWidget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    DrawTank(paint);
}
void TankWidget::DrawTank(QPainter &p)
{
    QPoint poinsition = mytank.p;
    p.setBrush(Qt::red);
    if(mytank.d == dir_right)
    {
        p.drawRect(QRect(QPoint(poinsition.x()-TankSize*13,poinsition.y()-TankSize*9),QSize(TankSize*26,TankSize*4)));
        p.drawRect(QRect(QPoint(poinsition.x()-TankSize*13,poinsition.y()+TankSize*5),QSize(TankSize*26,TankSize*4)));
        p.drawEllipse(poinsition,8,5);
        p.drawLine(poinsition,QPoint(poinsition.x()+20,poinsition.y()));
    }
    else if(mytank.d == dir_left)
    {
        p.drawRect(QRect(QPoint(poinsition.x()-TankSize*13,poinsition.y()-TankSize*9),QSize(TankSize*26,TankSize*4)));
        p.drawRect(QRect(QPoint(poinsition.x()-TankSize*13,poinsition.y()+TankSize*5),QSize(TankSize*26,TankSize*4)));
        p.drawEllipse(poinsition,8,5);
        p.drawLine(poinsition,QPoint(poinsition.x()-20,poinsition.y()));
    }
    else if(mytank.d == dir_up)
    {
        p.drawRect(QRect(QPoint(poinsition.x()-TankSize*9,poinsition.y()-TankSize*13),QSize(TankSize*4,TankSize*26)));
        p.drawRect(QRect(QPoint(poinsition.x()+TankSize*5,poinsition.y()-TankSize*13),QSize(TankSize*4,TankSize*26)));
        p.drawEllipse(poinsition,5,8);
        p.drawLine(poinsition,QPoint(poinsition.x(),poinsition.y()-20));
    }
    else if(mytank.d == dir_down)
    {
        p.drawRect(QRect(QPoint(poinsition.x()-TankSize*9,poinsition.y()-TankSize*13),QSize(TankSize*4,TankSize*26)));
        p.drawRect(QRect(QPoint(poinsition.x()+TankSize*5,poinsition.y()-TankSize*13),QSize(TankSize*4,TankSize*26)));
        p.drawEllipse(poinsition,5,8);
        p.drawLine(poinsition,QPoint(poinsition.x(),poinsition.y()+20));
    }
}
void TankWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Right:
            mytank.d = dir_right;
            mytank.p.setX(mytank.p.x()+5);
            if(mytank.p.x()+13 > width())
                mytank.p.setX(width()-13);
            break;
        case Qt::Key_Left:
            mytank.d = dir_left;
            mytank.p.setX(mytank.p.x()-5);
            if(mytank.p.x() < 13)
                mytank.p.setX(13);
            break;
        case Qt::Key_Down:
            mytank.d = dir_down;
            mytank.p.setY(mytank.p.y()+5);
            if(mytank.p.y()+13 > height())
                mytank.p.setY(height()-13);
             break;
        case Qt::Key_Up:
            mytank.d = dir_up;
            mytank.p.setY(mytank.p.y()-5);
            if(mytank.p.y() < 13)
                mytank.p.setY(13);
             break;
    }
    update();
}

bool TankWidget::event(QEvent *event)
{

    switch( event->type() )
    {
    case QEvent::TouchBegin:
        {
            QRect tankrect;
            if(mytank.d == dir_left || mytank.d == dir_right)
                tankrect = QRect(QPoint(mytank.p.x()-TankSize*13,mytank.p.y()-TankSize*9),QSize(TankSize*26,TankSize*18));
            else if(mytank.d == dir_down || mytank.d == dir_up)
                tankrect = QRect(QPoint(mytank.p.x()-TankSize*9,mytank.p.y()-TankSize*13),QSize(TankSize*18,TankSize*26));
            QTouchEvent* touch = static_cast<QTouchEvent*>(event);
            QList<QTouchEvent::TouchPoint> touch_list = touch->points();
            if(tankrect.contains(touch_list.at(0).position().x(),touch_list.at(0).position().y()))
                TankIdChoose = 1;
            event->accept();
            return true;

        }

    case QEvent::TouchUpdate:
        {
            QTouchEvent* touch = static_cast<QTouchEvent*>(event);

            if(touch->touchPointStates() & Qt::TouchPointPressed){
                //判断是否有触摸点处于TouchPointPressed或TouchPointMoved或TouchPointStationary或TouchPointReleased
            }
            QList<QTouchEvent::TouchPoint> touch_list = touch->points();
            if(TankIdChoose == 1)
            {
                touch_list.at(0).position().x();
                touch_list.at(0).position().y();
                mytank.p.setX(touch_list.at(0).position().x());
                mytank.p.setY(touch_list.at(0).position().y());
            }
            event->accept();
            return true;
        }
    case QEvent::TouchEnd:
        {
             TankIdChoose = 0;
        }
    }
    update();

    return QWidget::event(event);
}
