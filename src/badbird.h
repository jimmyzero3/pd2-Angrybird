#ifndef BADBIRD_H
#define BADBIRD_H

#include <bird.h>

class BadBird : public Bird
{
public:
    BadBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void skill();
    float rad;
};

#endif // BADBIRD_H
