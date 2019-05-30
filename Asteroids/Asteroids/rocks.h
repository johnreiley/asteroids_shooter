#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#define BIG_ROCK_SPEED 1.0

#include "flyingObject.h"
#include "uiDraw.h"


// TODO: Add a getRadius(); function to each rock type

/******************************************
 * ROCKS class : parent
 * ***************************************/
class Rock : public FlyingObject
{
private:

public:
   Rock();
   ~Rock() { };

   virtual void draw() { };
   virtual int hit() { return 0; };
   virtual int getRadius() = 0;
};

/******************************************
 * SMALL ROCK class : child
 * ***************************************/
class SmallRock : public Rock
{
private:

public:
   SmallRock();
   SmallRock(float iDx, float iDy, Point iPoint);
   ~SmallRock() { };

   virtual void draw();
   virtual int hit() { return 3; };
   virtual int getRadius() { return SMALL_ROCK_SIZE; };
};

/******************************************
 * MEDIUM ROCK class : child
 * ***************************************/
class MediumRock : public Rock
{
private:

public:
   MediumRock();
   MediumRock(float iDx, float iDy, Point iPoint);
   ~MediumRock() { };

   virtual void draw();
   virtual int hit() { return 2; };
   virtual int getRadius() { return MEDIUM_ROCK_SIZE; };
};

/******************************************
 * LARGE ROCK class : child
 * ***************************************/
class LargeRock : public Rock
{
private:

public:
   LargeRock();
   LargeRock(Point topLeft, Point bottomRight);
   ~LargeRock() { };

   virtual void draw();
   virtual int hit() { return 1; };
   virtual int getRadius() { return BIG_ROCK_SIZE; };
};


#endif /* rocks_h */
