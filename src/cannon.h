#ifndef CANNON_H
#define CANNON_H

#include <land.h>
#include <obstacle.h>

class cannon : public Land
{
public:
    cannon(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    QGraphicsPixmapItem pix;
};

#endif // CANNON_H
