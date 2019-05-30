#include "rocks.h"


/**********************************************************
 * Function: Rock
 * Description: default constructor
 **********************************************************/
Rock :: Rock()
{
   setAlive(true);
   point.setX(0);
   point.setY(0);
   setVelocity(Velocity(0, 0));
   setRotation(0);
}


/**********************************************************
 * Function: LargeRock
 * Description: default constructor
 **********************************************************/
LargeRock :: LargeRock()
{
   setAlive(true);
   point.setX(0);
   point.setY(0);
   setVelocity(Velocity(0, 0));
   setRotation(0);
}


/**********************************************************
* Function: MediumRock
* Description: default constructor
**********************************************************/
MediumRock :: MediumRock()
{
   setAlive(true);
   point.setX(0);
   point.setY(0);
   setVelocity(Velocity(0, 0));
   setRotation(0);
}


/**********************************************************
* Function: SmallRock
* Description: default constructor
**********************************************************/
SmallRock :: SmallRock()
{
   setAlive(true);
   point.setX(0);
   point.setY(0);
   setVelocity(Velocity(0, 0));
   setRotation(0);
}


/**********************************************************
 * Function: LargeRock
 * Description: initializes the location and velocity of
 * the rock
 **********************************************************/
LargeRock :: LargeRock(Point topLeft, Point bottomRight)
{
   setAlive(true);

   int select = random(1, 5);

   if (select == 1)
   {
      point.setX(topLeft.getX());
      point.setY(random(topLeft.getX(), topLeft.getY()));
   }
   else if (select == 2)
   {
      point.setX(random(topLeft.getX(), topLeft.getY()));
      point.setY(topLeft.getY());
   }
   else if (select == 3)
   {
      point.setX(topLeft.getY());
      point.setY(random(topLeft.getX(), topLeft.getY()));
   }
   else if (select == 4)
   {
      point.setX(random(topLeft.getX(), topLeft.getY()));
      point.setY(topLeft.getX());
   }

   int angle = random(0, 361);
   float dx = BIG_ROCK_SPEED * (-cos(PI / 180.0 * angle));
   float dy = BIG_ROCK_SPEED * (sin(PI / 180.0 * angle));
   setVelocity(Velocity(dx, dy));

   setRotation(0);
}


/**********************************************************
* Function: MediumRock
* Description: initializes the location and velocity of
 * the rock
**********************************************************/
MediumRock :: MediumRock(float iDx, float iDy, Point iPoint)
{
   setAlive(true);

   point.setX(iPoint.getX());
   point.setY(iPoint.getY());

   setVelocity(Velocity(iDx, iDy));

   setRotation(0);
}


/**********************************************************
* Function: SmallRock
* Description: initializes the location and velocity of
 * the rock
**********************************************************/
SmallRock :: SmallRock(float iDx, float iDy, Point iPoint)
{
   setAlive(true);

   point.setX(iPoint.getX());
   point.setY(iPoint.getY());

   setVelocity(Velocity(iDx, iDy));

   setRotation(0);
}


/**********************************************************
* Function: LargeRock :: draw
* Description: draws Dwane "the Rock"
**********************************************************/
void LargeRock :: draw()
{
   drawLargeAsteroid(point, getRotation());
   setRotation(getRotation() + BIG_ROCK_SPIN);
}


/**********************************************************
* Function: MediumRock :: draw
* Description: also draws the rock
**********************************************************/
void MediumRock :: draw()
{
   drawMediumAsteroid(point, getRotation());
   setRotation(getRotation() + MEDIUM_ROCK_SPIN);
}


/**********************************************************
 * Function: SmallRock :: draw
 * Description: draws the rock too!
 **********************************************************/
void SmallRock :: draw()
{
   drawSmallAsteroid(point, getRotation());
   setRotation(getRotation() + SMALL_ROCK_SPIN);
}