#include "obstacle.h"

obstacle::obstacle(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;//
    bodyDef.bullet = true;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);

    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyBox;
    fixturedef.density = OBS_DENSITY;
    fixturedef.friction = OBS_FRICTION;
    fixturedef.restitution = OBS_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);


    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&g_pixmap);

}
