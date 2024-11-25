#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX();                      // Kar
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY();                       
    playerPos.symbol = '@';                     // Kar
}


Player::~Player()
{
    // delete any heap members here
    // only when new is inttii -- kar 
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    // int input = 70; what is this 

    char input  = mainGameMechsRef->getInput();
    
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case 27:  // escape key exits
                mainGameMechsRef->setExitTrue();  //EXIT FLAG IS NOT BEING hhit
                break;

            case 'w':                                //Moving UP
            case 'W':
                if(myDir != DOWN)                             //Why is it we dont use strring marks 
                    {
                        myDir = UP;
                    }
                    break;                  
            case 'a':                                    //Moving Left
            case 'A':
                if(myDir != RIGHT)
                    {
                        myDir = LEFT;
                    }
                    break;
            case 's':                                    //Moving Down
            case 'S':
                if(myDir != UP)
                    {
                        myDir = DOWN;
                    }
                    break;
            case 'd':                        //Moving right
            case 'D':
                if(myDir != LEFT)
                    {
                        myDir = RIGHT;
                    }
                    break; 

            default:
                break;
        }
        //Imm not sure if we need input = 0 anymore , but do check 
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