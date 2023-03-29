#include "Mover.h"
#include <assert.h>

Mover::Mover()
{
	xPos = MIN_X;
	yPos = MIN_Y;
}

Mover::Mover(int xStart, int yStart)
{
	xPos = xStart;
	yPos = yStart;
}


// SIMPLE MATH CODE: designed to make the math easier.  I am just defining a absolute value
// function and a function that gets the absolute value min of two numbers.
int Mover::absVal(int num)
{
	return (num >= 0) ? num : -num;
}
int Mover::minAbsDist(int dist1, int dist2)
{
	return (absVal(dist1) > absVal(dist2)) ? dist2 : dist1;
}

// Function walk takes the DESTINATION x position and y position
// and adjusts the xPos and yPos member variables to approach that
// position. maxDist is the maximum number of steps / positions the 
// character can move in a given turn.
// Returns the number of steps needed to reach the destination.
int Mover::walk(int xDest, int yDest, int maxDist)
{
	// Make sure the destination position is "safe"
	if (xDest > MAX_X)
	{
		xDest = MAX_X;
	}
	if (xDest < MIN_X)
	{
		xDest = MIN_X;
	}
	if (yDest > MAX_Y)
	{
		yDest = MAX_Y;
	}
	if (yDest < MIN_Y)
	{
		yDest = MIN_Y;
	}

	int remDist = maxDist;
	int halfDist = maxDist / 2;
	// Move half the steps in the x direction (or however many x steps are left)
	int maxX = (xPos - xDest >= 0) ? -halfDist : halfDist;
	int xDist = minAbsDist(maxX, xPos - xDest);
	remDist -= absVal(xDist);

	int maxY = (yPos - yDest >= 0) ? -remDist : remDist;
	int yDist = minAbsDist(maxY, yPos - yDest);

	// Once more, take off the x value if not used by y
	remDist -= absVal(yDist);
	maxX = (xPos - xDest >= 0) ? -remDist : remDist;
	xDist = minAbsDist(maxX + xDist, xPos - xDest);

	xPos += xDist;
	yPos += yDist;

	// Some basic tests to make sure we don't have a math error
	assert(xPos <= MAX_X);
	assert(yPos <= MAX_Y);
	assert(xPos >= MIN_X);
	assert(yPos >= MIN_Y);
	assert(absVal(xDist) + absVal(yDist) <= maxDist);

	int distLeft = absVal(xDest - xPos) + absVal(yDest - yPos);
	return distLeft;
}

//checkRange simply checks if a mover is within a certain distance from
// another point.  The xPos and yPos values are NOT modified.
bool Mover::checkRange(int xPos, int yPos, int range)
{
	int maxDist = absVal(xPos - this->xPos) + absVal(yPos - this->yPos);
	return maxDist <= range;
}