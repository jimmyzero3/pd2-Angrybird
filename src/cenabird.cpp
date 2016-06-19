#include "cenabird.h"
#include <QSound>
#include <QSoundEffect>
#include <iostream>
#include <QLabel>

CenaBird::CenaBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : Bird( x, y,  radius, timer, pixmap, world, scene)
{
        UCSM->setGeometry(325,100,320,320);
        UCSM->setStyleSheet("background-color: rgba(0,0,0,0%)");
        UCSM->setPixmap(QPixmap(":/UCSM.png"));
        scene->addWidget(UCSM);
        UCSM->hide();

        rad=radius;
}

void CenaBird::skill()
{
    g_body->SetLinearVelocity(b2Vec2( 0, 0 ));
    g_body->SetTransform(b2Vec2( 5, 5 ), 0 );
    g_body->SetGravityScale(0);

    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(rad*5,rad*5);

    b2CircleShape bodyshape;
    bodyshape.m_radius = rad*5;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    QTimer::singleShot(2500,this,SLOT(shoot()));
    QTimer::singleShot(3500,this,SLOT(showpic()));

    std::cout<<"Cena!!!"<<std::endl;


    Cena->play();


}

void CenaBird::shoot()
{

    g_pixmap.setPixmap(QPixmap(":/cena.png"));
    setLinearVelocity(b2Vec2(30,0));
}

void CenaBird::showpic()
{

    UCSM->show();
}

CenaBird::~CenaBird()
{

    UCSM->hide();

    Cena->stop();
}
