#include "velocity.h"

#include <iostream>

using namespace std;

/**********************************************************
 * Function: Velocity
 * Description: default constructor
 **********************************************************/
Velocity :: Velocity()
{
    setDx(0);
    setDy(0);
}

/**********************************************************
 * Function: Velocity(int)
 * Description: non-default int constructor
 **********************************************************/
Velocity :: Velocity(int dX, int dY)
{
    setDx(dX);
    setDy(dY);
}

/**********************************************************
 * Function: Velocity(float)
 * Description: non-default float constructor
 **********************************************************/
Velocity :: Velocity(float dX, float dY)
{
    setDx(dX);
    setDy(dY);
}