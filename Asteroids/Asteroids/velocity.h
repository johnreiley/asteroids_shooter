#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>

using namespace std;

class Velocity
{
   private:
      float dX;
      float dY;

   public:
      Velocity();
      Velocity(int dX, int dY);
      Velocity(float dX, float dY);
      ~Velocity() { };

      float getDx() { return dX; }
      float getDy() { return dY; }
      void setDx(float dX) { this->dX = dX; }
      void setDy(float dY) { this->dY = dY; }
      
};

#endif /* velocity_h */
