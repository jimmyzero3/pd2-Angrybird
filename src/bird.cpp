#include "bird.h"
#include <iostream>

Bird::Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;

    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(100);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
   // std::cout<<"mouse press"<<std::endl;
    g_body->SetLinearVelocity(velocity);
}

void Bird::skill()
{
    g_pixmap.setPixmap(QPixmap(":/troll.png").scaled(height()/7.0,height()/6.0));
    g_body->SetGravityScale(0.0f);
    QTimer *timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(slowdown()));
    timer->start(100);

}

void Bird::slowdown()
{
    setLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x-1,g_body->GetLinearVelocity().y+0.01));
}

