#include "ship.h"


/**********************************************************
 * Function: SHIP()
 * Description: default constructor
 **********************************************************/
Ship :: Ship()
{
   point.setX(0);
   point.setY(0);
   Velocity(0, 0);
   setThrust(true);
   setRotation(90);
}

/**********************************************************
 * Function: DRAW
 * Description: draws the ship
 **********************************************************/
void Ship :: draw()
{
   drawShip(point, getRotation() - 90, false);
}

/**********************************************************
 * Function: APPLY THRUST
 * Description: makes the ship go vrooom! by using triangles
 **********************************************************/
void Ship :: applyThrust()
{
   if (isAlive() && canThrust())
   {
      //cerr << "ANGLE: " << getRotation() << endl;

      float dx = THRUST_AMOUNT * (cos(PI / 180.0 * rotation));
      float dy = THRUST_AMOUNT * (sin(PI / 180.0 * rotation));
//      velocity.setDx(dx);
//      velocity.setDy(dy);
      
      
      velocity.setDx(velocity.getDx() + dx);
      velocity.setDy(velocity.getDy() + dy);
   
//      if (getMagnitude() > MAX_THRUST)
//      {
//         velocity.setDx(velocity.getDx() - dx);
//         velocity.setDy(velocity.getDy() - dy);
//      }
 
      
   }
}

/**********************************************************
 * Function: APPLY LEFT ROTATION
 * Description: turns the ship left
 **********************************************************/
void Ship :: applyLeftRotation()
{
   setRotation(getRotation() + ROTATE_AMOUNT);

   //cerr << "ANGLE: " << rotation << endl;
}

/**********************************************************
 * Function: APPLY RIGHT ROTATION
 * Description: turns the ship right
 **********************************************************/
void Ship :: applyRightRotation()
{
   setRotation(getRotation() - ROTATE_AMOUNT);

   //cerr << "ANGLE: " << rotation << endl;
}