#ifndef flyingObject_h
#define flyingObject_h

#include "velocity.h"
#include "point.h"
#include "uiDraw.h"

#include <cmath>
#define PI 3.14159265359

#include <iostream>
using namespace std;

class FlyingObject
{
    protected:
        Point point;
        Velocity velocity;
        bool alive;
        int rotation;
        //float magnitude;
    public:
        FlyingObject();
        ~FlyingObject();
        Point getPoint() { return point; }
        Velocity getVelocity() { return velocity; }
        bool isAlive() { return alive; }
        int getRotation() { return rotation; }
        void setRotation(int rotation);
        void setAlive(bool alive) { this->alive = alive; }
        void setPoint(Point point) { this->point = point; }
        void setVelocity(Velocity velocity) { this->velocity = velocity; }
        void setVelocity(float dX, float dY) { velocity.setDx(dX); velocity.setDy(dY); }
        void advance(Point topLeft, Point bottomRight);
        void kill();

        float getMagnitude();

        void drawMagnitude();
};


#endif /* flyingObject_h */
