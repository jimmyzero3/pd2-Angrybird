#ifndef HAPPYBIRD_H
#define HAPPYBIRD_H
#include <bird.h>

class HappyBird : public Bird
{
public:
    HappyBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void skill();

};

#endif // HAPPYBIRD_H
