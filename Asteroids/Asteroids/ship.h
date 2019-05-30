#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 10
#define THRUST_AMOUNT 0.3 // orgininal is 0.5
#define MAX_THRUST 5

#define ANGLE_MAX 360
#define ANGLE_MIN 0

#include "flyingObject.h"
#include "uiDraw.h"


class Ship : public FlyingObject
{
private:
   bool thrust;

public:
   Ship();
   ~Ship() { };

   void draw();

   bool canThrust() { return thrust; };
   void setThrust(bool thrust) { this->thrust = thrust; }
   void applyThrust();
   void applyLeftRotation();
   void applyRightRotation();

};


#endif /* ship_h */
