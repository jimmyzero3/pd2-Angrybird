#include "badbird.h"

BadBird::BadBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : Bird( x, y,  radius, timer, pixmap, world, scene)
{

    rad=radius;
}

void BadBird::skill()
{
    g_pixmap.setPixmap(QPixmap(":/bad.png").scaled(height()/4.0,height()/4.0));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(rad*5,rad*5);


    b2CircleShape bodyshape;
    bodyshape.m_radius = rad*5;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY/50;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);
}
