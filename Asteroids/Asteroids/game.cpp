/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits> 
#include <algorithm>
#include <cmath>
using namespace std;


/**********************************************************
 * Function: Game()
 * Description: non-default constr. that sets score, game-
 * level, gameOver, creates rocks, and sets ship to alive.
 **********************************************************/
Game :: Game(Point topLeft, Point bottomRight)
{
   this->topLeft = topLeft;
   this->bottomRight = bottomRight;

   score = 0;
   gameLevel = 1;
   gameOver = false;

   for (int i = 1; i <= LVL1_ROCK_NUM; i++)
   {
      rocks.push_back(createRock(LARGE_ROCK, 0.0, 0.0, topLeft));
   }

   ship.setAlive(true);

}


/**********************************************************
* Function: SET GAME LEVEL
* Description: incriments the level and determines how
* many rocks to spawn
**********************************************************/
void Game :: setGameLevel()
{
   gameLevel++;

   switch (gameLevel)
   {
   case 1:
      break;
   
   case 2:
      setUpNewLevel(LVL2_ROCK_NUM);
      break;
   
   case 3:
      setUpNewLevel(LVL3_ROCK_NUM);
      break;
   
   case 4:
      setUpNewLevel(LVL4_ROCK_NUM);
      break;
   
   case 5:
      setUpNewLevel(LVL5_ROCK_NUM);
      break;
   
   case 6:
   {
      cleanUpZombies();
      ship.kill();
      gameOver = true;

      break;
   }

   default:
      //cout << "default gameLevel\n";

      for (int i = 1; i <= LVL1_ROCK_NUM; i++)
      {
         rocks.push_back(createRock(LARGE_ROCK, 0.0, 0.0, topLeft));
      }

   }
}


/**********************************************************
* Function: SET UP NEW LEVEL
* Description: creates a specified number of rocks and 
* sets ship point and velocity to default.
**********************************************************/
void Game::setUpNewLevel(int rockNum)
{
   for (int i = 1; i <= rockNum; i++)
   {
      rocks.push_back(createRock(LARGE_ROCK, 0.0, 0.0, topLeft));
   }
   ship.setPoint(center);
   ship.setVelocity(center.getX(), center.getY());
}


/**********************************************************
 * Function: DRAW
 * Description: draws rocks, ship and bullets
 **********************************************************/
void Game :: draw(const Interface & ui)
{

   for (int i = 0; i < rocks.size(); i++)
   {
      if (rocks[i] != NULL && rocks[i]->isAlive())  // 
      {
         rocks[i]->draw();
         //rocks[i]->drawMagnitude();
      }
   }

   if (ship.isAlive())
   {
      ship.draw();
      //ship.drawMagnitude();
   }

   for (int i = 0; i < bullets.size(); i++)
   {
	   if (bullets[i].isAlive())
	   {
		   //bullets[i].draw();
         bullets[i].drawMagnitude();
	   }
   }

   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);

   drawNumber(scoreLocation, score);

   Point levelLocation;
   levelLocation.setX(topLeft.getX() + 180);
   levelLocation.setY(topLeft.getY() - 14);

   if (!gameOver)
   {
      drawText(levelLocation, "Level");

      levelLocation.setX(topLeft.getX() + 215);
      levelLocation.setY(topLeft.getY() - 5);
      drawNumber(levelLocation, gameLevel);
   }
}

/**********************************************************
 * Function: HANDLE INPUT
 * Description: handles game actions according to key input
 **********************************************************/
void Game :: handleInput(const Interface & ui)
{
   if (ui.isSpace() && ship.isAlive() && bullets.size() < MAX_BULLET_NUM)
   {
	   //cerr << "SPACEBAAAR!\n";

	   Bullet newBullet1;
      Bullet newBullet2;

      //Bullet newBullet3;
      //Bullet newBullet4;
      //Bullet newBullet5;
      //Bullet newBullet6;

	   newBullet1.fire(ship.getPoint(), ship.getRotation() + 10, ship.getVelocity());
      newBullet2.fire(ship.getPoint(), ship.getRotation() - 10, ship.getVelocity());

      //newBullet3.fire(ship.getPoint(), ship.getRotation() + 150, ship.getVelocity());
      //newBullet4.fire(ship.getPoint(), ship.getRotation() - 150, ship.getVelocity());
      //newBullet5.fire(ship.getPoint(), ship.getRotation() + 40, ship.getVelocity());
      //newBullet6.fire(ship.getPoint(), ship.getRotation() - 40, ship.getVelocity());


	   bullets.push_back(newBullet1);
      bullets.push_back(newBullet2);

      //bullets.push_back(newBullet3);
      //bullets.push_back(newBullet4);
      //bullets.push_back(newBullet5);
      //bullets.push_back(newBullet6);
   }

   if (ui.isLeft() && ship.isAlive())
   {
      ship.applyLeftRotation();
   }
   if (ui.isRight() && ship.isAlive())
   {
      ship.applyRightRotation();
   }
   if (ui.isUp() && ship.isAlive())
   {
      ship.applyThrust();
   }
}


/**********************************************************
 * Function: ADVANCE ROCKS
 * Description: animates the rocks
 **********************************************************/
void Game :: advanceRocks()
{
   //cerr << "advanceRocks();\n";
   for (int i = 0; i < rocks.size(); i++)
   {
      if (rocks[i] != NULL && rocks[i]->isAlive())
      {
         //cerr << "Rock # " << i << " != NULL\n";

         rocks[i]->advance(topLeft, bottomRight);
      }
   }

   //cerr << "ROCKS.SIZE() = " << rocks.size() << endl;

}


/**********************************************************
* Function: ADVANCE SHIP
* Description: animates the ship
**********************************************************/
void Game::advanceShip()
{
   if (ship.isAlive() && ship.canThrust())
   {
      ship.advance(topLeft, bottomRight);

      //cout << ship.getMagnitude() << endl;
   }
}


/**********************************************************
* Function: ADVANCE BULLETS
* Description: animates the bullets
**********************************************************/
void Game::advanceBullets()
{
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance(topLeft, bottomRight);

         bullets[i].setBulletLife(bullets[i].getBulletLife() - 1);
      }

      if (bullets[i].getBulletLife() == 0)
      {
         bullets[i].kill();
      }
   }
}


/**********************************************************
 * Function: ADVANCE
 * Description: calls the advance funtions for rocks, ship
 * and bullets respectively and controls end game output
 **********************************************************/
void Game::advance()
{
   advanceRocks();
   advanceShip();
   advanceBullets();

   handleCollisions();
   cleanUpZombies();

   //cout << "gameLevel: " << gameLevel << endl;

   if (rocks.size() == 0 && ship.isAlive() && gameLevel != 6)
   {
      setGameLevel();
   }
   else if (gameOver && rocks.size() == 0)
   {
      Point textLocation(-20, 0);
      drawText(textLocation, "YOU WIN!");
   }
   else if (gameOver && rocks.size() != 0 && !ship.isAlive())
   {
      Point textLocation(-35, 0);
      drawText(textLocation, "GAME OVER");
   }


}


/**********************************************************
* Function: handleCollisions
* Description: determines when there are collisions and 
* responds accordingly
**********************************************************/

void Game::handleCollisions()
{

   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         for (int j = 0; j < rocks.size(); j++)
         {
            if (rocks[j] != NULL && rocks[j]->isAlive()) //  
            {
               if (fabs(bullets[i].getPoint().getX() - rocks[j]->getPoint().getX()) <= rocks[j]->getRadius() + 3
                  && fabs(bullets[i].getPoint().getY() - rocks[j]->getPoint().getY()) <= rocks[j]->getRadius() + 3)
               {
                  bullets[i].kill();

                  int value = rocks[j]->hit();
                  Velocity v = rocks[j]->getVelocity();
                  Point p = rocks[j]->getPoint();
                  score += value;

                  rocks[j]->kill();
                  rocks[j] = NULL;

                  if (value < 3)
                     spawnRocks(value, v, p);
               }
            }
         }
      }
   }
//   /*
   for (int j = 0; j < rocks.size(); j++)
   {
      if (rocks[j] != NULL && fabs(ship.getPoint().getX() - rocks[j]->getPoint().getX()) <= rocks[j]->getRadius() + 2
         && fabs(ship.getPoint().getY() - rocks[j]->getPoint().getY()) <= rocks[j]->getRadius() + 2)
      {
         ship.kill();
         gameOver = true;
      }
   }
//   */
}


/**********************************************************
* Function: spawnRocks
* Description: determines what rock just got hit and spawns
* new rocks as a result
**********************************************************/
void Game::spawnRocks(int select, Velocity v, Point p)
{

   if (select == LARGE_ROCK)
   {
      rocks.push_back(createRock(MEDIUM_ROCK, v.getDx(), v.getDy() + 1, p));
      rocks.push_back(createRock(MEDIUM_ROCK, v.getDx(), v.getDy() - 1, p));
      rocks.push_back(createRock(SMALL_ROCK, v.getDx() + 2, v.getDy(), p));
   }

   else if (select == MEDIUM_ROCK)
   {
      rocks.push_back(createRock(SMALL_ROCK, v.getDx() - 3, v.getDy(), p));
      rocks.push_back(createRock(SMALL_ROCK, v.getDx() + 3, v.getDy(), p));
   }
   else
      return;
}


/**********************************************************
* Function: CREATE ROCK
* Description: calls the constructors for rock types 
* according to the passed value.
**********************************************************/
Rock* Game::createRock(int type, float dX, float dY, Point p)
{
   Rock * newRock = NULL;

   switch (type)
   {

   case LARGE_ROCK:
      newRock = new LargeRock(topLeft, bottomRight);
      break;

   case MEDIUM_ROCK:
      newRock = new MediumRock(dX, dY, p);
      //newRock = new MediumRock();
      break;

   case SMALL_ROCK:
      newRock = new SmallRock(dX, dY, p);
      //newRock = new SmallRock();
      break;

   default:
      newRock = new LargeRock(topLeft, bottomRight);

   }
   //cerr << "new Rock;\n";

   return newRock;

}


/**********************************************************
* Function: CLEANUP ZOMBIES
* Description: deletes any dead bullets and rocks
**********************************************************/
void Game::cleanUpZombies()
{

	vector<Bullet>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet bullet = *bulletIt;

		if (!bullet.isAlive())
		{
			bulletIt = bullets.erase(bulletIt);
		}
		else
		{
			bulletIt++; // advance
		}
	}

	vector<Rock*>::iterator rockIt = rocks.begin();
	while (rockIt != rocks.end())
	{
		Rock* pRock = *rockIt;

      //cout << "before is rock alive?\n";
		if (pRock == NULL)
		{
         //cout << "inside is rock alive?\n";
			delete pRock;

			rockIt = rocks.erase(rockIt);
		}
		else
		{
			rockIt++; // advance
		}
	}
}


