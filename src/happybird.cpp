#include "happybird.h"

HappyBird::HappyBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird( x, y,  radius, timer, pixmap, world, scene)
{

}

void HappyBird::skill()
{
    g_pixmap.setPixmap(QPixmap(":/angry.png").scaled(height()/7.0,height()/7.0));



}
