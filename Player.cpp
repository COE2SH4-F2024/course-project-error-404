#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;                      // Kar
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;                       
    playerPos.symbol = '@';                                                   // Kar
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

        switch(input)
        {                      
            case 'w':                                //Moving UP
            case 'W':
                if(myDir != DOWN)                 //Why is it we dont use strring marks 
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
        //Imm not sure if we need input = 0 anymore , but do check 
        input = 0;
    }
    
}

void Player::movePlayer()
{
    //updatePlayerDir(); do not need this.

    switch (myDir)
    {
        case UP:
            playerPos.pos->y--;
            if (playerPos.pos->y <=0)
                {
                    playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
                }
            break;

        case DOWN:
            playerPos.pos->y++;
            if (playerPos.pos->y >= mainGameMechsRef->getBoardSizeY() - 1)
                {
                    playerPos.pos->y = 1;
                }
            break;

        case LEFT:
            playerPos.pos->x--;
            if (playerPos.pos->x <=0)
                {
                    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 1;
                }
            break;

        case RIGHT:
            playerPos.pos->x++;
            if (playerPos.pos->x >= mainGameMechsRef->getBoardSizeX() - 1) // it had <= board x - 1 which is why D wasnt working.
                {
                    playerPos.pos->x = 1;
                }
            break;
    
        default:
            break;
    }    

}

// More methods to be added