#ifndef OBSTACLE_H
#define OBSTACLE_H

#define OBS_DENSITY 1.0f
#define OBS_FRICTION 1.0f
#define OBS_RESTITUTION 0.5f

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDrag>
#include <QMouseEvent>
class obstacle : public GameItem
{
public:
    obstacle(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // OBSTACLE_H
