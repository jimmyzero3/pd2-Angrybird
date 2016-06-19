#ifndef BGBIRD_H
#define BGBIRD_H

#include "bird.h"
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDrag>
#include <QMouseEvent>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f


class BGbird :  public GameItem
{
public:
    BGbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BGBIRD_H
