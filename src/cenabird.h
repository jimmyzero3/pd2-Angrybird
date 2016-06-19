#ifndef CENABIRD_H
#define CENABIRD_H

#include <bird.h>
#include <QSound>
#include <QSoundEffect>
#include <QLabel>


class CenaBird : public Bird
{
    Q_OBJECT
public:
    ~CenaBird();
    CenaBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void skill();
    float rad;



 public slots:
    void shoot();

   private:

    QSound *Cena =new QSound("image/Cena.wav");
    QLabel *UCSM = new QLabel;
};

#endif // CENABIRD_H
