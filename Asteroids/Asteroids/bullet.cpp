#include "bullet.h"


/**********************************************************
* Function: BULLET
* Description: non-default constructor
**********************************************************/
Bullet :: Bullet()
{
	setAlive(true);
	bulletLife = BULLET_LIFE;
}


/**********************************************************
* Function: FIRE
* Description: says to the bullet, "You go here now!"
**********************************************************/
void Bullet :: fire(Point point, float angle, Velocity shipV)
{
	setPoint(point);
	float dx = BULLET_SPEED * (cos(PI / 180.0 * angle));
	float dy = BULLET_SPEED * (sin(PI / 180.0 * angle));
	velocity.setDx(shipV.getDx() + dx);
	velocity.setDy(shipV.getDy() + dy);
}