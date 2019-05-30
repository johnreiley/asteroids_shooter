#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"
#include "uiDraw.h"


class Bullet : public FlyingObject
{
private:
   int bulletLife;

public:
	Bullet();
   ~Bullet() { };

   void draw() { drawDot(point); };
   void fire(Point point, float angle, Velocity shipV);
   int getBulletLife() { return bulletLife; }
   void setBulletLife(int bulletLife) { this->bulletLife = bulletLife; }

};



#endif /* bullet_h */
