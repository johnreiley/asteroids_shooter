#include "flyingObject.h"

#include <iostream>
#include <string>
using namespace std;


/************************************
 * FLYING OBJECT :: FlyingObject
 * does nothing
 * **********************************/
FlyingObject :: FlyingObject()
{

}

/************************************
 * FLYING OBJECT :: ~FlyingObject
 * resets point and velocity to
 * initial values just in case
 * **********************************/
FlyingObject :: ~FlyingObject()
{
    point = Point(0, 0);
    velocity = Velocity(0, 0);
}

/************************************
 * FLYING OBJECT :: Kill
 * sets alive to false
 * **********************************/
void FlyingObject :: kill()
{
     setAlive(false);
}

/************************************
 * ADVANCE: applies velocity to the 
 * point of the flying object (moves
 * the object).
 * **********************************/
void FlyingObject :: advance(Point topLeft, Point bottomRight)
{

    point.addX(velocity.getDx());
    point.addY(velocity.getDy());

	if (point.getX() > topLeft.getY())
		point.setX(topLeft.getX());
	else if (point.getX() <= topLeft.getX())
		point.setX(topLeft.getY());

	if (point.getY() > topLeft.getY())
		point.setY(topLeft.getX());
	else if (point.getY() <= topLeft.getX())
		point.setY(topLeft.getY());
}


/************************************
* SET ROTATION: sets rotation angle
* to keep it between 0 and 360
* **********************************/
void FlyingObject :: setRotation(int rotation) 
{
    if (rotation > 360)
        this->rotation = 0;
    else if (rotation < 0)
        this->rotation = 360;
    else
        this->rotation = rotation;
}


/************************************
* GET MAGNITUDE: calculates the mag-
* nitude and returns it
* **********************************/
float FlyingObject :: getMagnitude()
{
   return sqrtf((velocity.getDx() * velocity.getDx()) + 
                (velocity.getDy() * velocity.getDy()));
}


/************************************
* GET MAGNITUDE: visualizes the 
* magnitude of the flying object
* **********************************/
void FlyingObject :: drawMagnitude()
{
   Point ePoint = point;
   ePoint.setX(point.getX() + (velocity.getDx()));
   ePoint.setY(point.getY() + (velocity.getDy()));

   drawLine(point, ePoint, 1.0, 0.0, 0.0);
}