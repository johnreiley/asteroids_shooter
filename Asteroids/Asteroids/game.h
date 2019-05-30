/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ship.h"
#include "bullet.h"
#include "rocks.h"
#include <string>
#include <iostream>
#include <list>
#include <vector>

#define LVL1_ROCK_NUM 5
#define LVL2_ROCK_NUM 6
#define LVL3_ROCK_NUM 7
#define LVL4_ROCK_NUM 8
#define LVL5_ROCK_NUM 10
//#define CLOSE_ENOUGH 16

// ROCK TYPE DEFINES
#define LARGE_ROCK  1
#define MEDIUM_ROCK 2
#define SMALL_ROCK  3

#define MAX_BULLET_NUM 10

class Game
{
private:
   Point topLeft;
   Point bottomRight;
   Point center;

   int score;
   int gameLevel;
   bool gameOver;

   Ship ship;

   vector <Rock*> rocks;
   vector <Bullet> bullets;

   bool gameStart;

public:
   Game(Point topLeft, Point bottomRight);
   ~Game() { };

   Rock* createRock(int type, float dX, float dY, Point p);
   void spawnRocks(int select, Velocity v, Point p);
   void draw(const Interface & ui);

   void setGameLevel();
   void setUpNewLevel(int rockNum);
   void advance();
   void advanceBullets();
   void advanceShip();
   void advanceRocks();

   void handleCollisions();
   void handleInput(const Interface & ui);
   void cleanUpZombies();

};


#endif /* GAME_H */
