#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    int input = 70;
    
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case 27:  // escape key exits
                mainGameMechsRef->setExitTrue();
                break;

            case 72: // Up Arrow Key
                // move up
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

            case 75: // Left Arrow Key
                // move left
                if (myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;

            case 80: // Down Arrow Key
                // down
                if (myDir != UP)
                {
                    myDir = DOWN;
                }
                break; 

            case 77: // Right Arrow Key
                // right
                if (myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;
            default:
                break;
        }
        input = 0;
    }
    
}

void Player::movePlayer()
{
    int width = 20; //for now should change after iteration 1B
    int length = 10; //for now
    if (myDir == RIGHT)
    {
        playerPos.pos->x += 1;
        if (playerPos.pos->y > width - 2) 
        {
            playerPos.pos->x = width % playerPos.pos->y; //20 % 19 = 1, so wraps to 1.
        }
    }
    else if (myDir == LEFT)
    {
        playerPos.pos->x -= 1;
        if (playerPos.pos->x < 1)
        {
            playerPos.pos->x = (playerPos.pos->x + width - 2) % width; // (0+20-2) % 20 = 18, so wraps to 18
        }
    }
    else if (myDir == UP)
    {
        playerPos.pos->y -= 1;
        if (playerPos.pos->y < 1)
        {
            playerPos.pos->y = (playerPos.pos->y + length - 2) % length; //(0+10-2) % 10 = 8, so wraps to 8
        }
    }
    else if(myDir == DOWN)
    {
        playerPos.pos->y += 1;
        if (playerPos.pos->y > length - 2)
        {
            playerPos.pos->y = length % playerPos.pos->y; //10 % 9 = 1, so wraps to 1
        }
    }
}

// More methods to be added