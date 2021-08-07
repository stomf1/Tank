#include "tankrefresh.h"
#include "tank.h"

TankRefresh::TankRefresh()
{

}
void TankRefresh::run()
{
    while(1)
    {
        switch(w->m_dir)
        {
            case move_up:
                w->mytank.d=dir_up;
                w->mytank.p.setY(w->mytank.p.y()-3);
                if(w->mytank.p.y()<w->TankSize*13)
                {
                    w->mytank.p.setY(w->TankSize*13);
                }
            break;
            case move_down:
                w->mytank.d=dir_down;
                w->mytank.p.setY(w->mytank.p.y()+3);
                if(w->mytank.p.y()>w->height()-w->TankSize*13)
                {
                    w->mytank.p.setY(w->height()-w->TankSize*13);
                }
            break;
            case move_left:
                w->mytank.d=dir_left;
                w->mytank.p.setX(w->mytank.p.x()-3);
                if(w->mytank.p.x()<w->TankSize*13)
                {
                   w->mytank.p.setX(w->TankSize*13);
                }
            break;
            case move_right:
                w->mytank.d=dir_right;
                w->mytank.p.setX(w->mytank.p.x()+3);
                if(w->mytank.p.x()>w->width()-w->TankSize*13)
                {
                    w->mytank.p.setX(w->width()-w->TankSize*13);
                }
            break;
            default:
            break;
        }
        w->update();
        msleep(10);
    }
}
