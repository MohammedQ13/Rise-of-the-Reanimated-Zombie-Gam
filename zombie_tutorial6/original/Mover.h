#pragma once
class Mover
{
public:
    int xPos;
    int yPos;

    // Defining the size of the movement grid that enemies and the player can
    // move on
    const static int MAX_X = 25;
    const static int MIN_X = 1;
    const static int MAX_Y = 25;
    const static int MIN_Y = 1;

    Mover();
    Mover(int xStart, int yStart);

    int absVal(int num);
    int minAbsDist(int dist1, int dist2);

    // Function walk takes the DESTINATION x position and y position
    // and adjusts the xPos and yPos member variables to approach that
    // position. maxDist is the maximum number of steps / positions the 
    // character can move in a given turn.
    // Returns the number of steps needed to reach the destination.
    int walk(int xDist, int yDist, int maxDist);

    //checkRange simply checks if a mover is within a certain distance from
    // another point.  The xPos and yPos values are NOT modified.
    bool checkRange(int xPos, int yPos, int range);
};

