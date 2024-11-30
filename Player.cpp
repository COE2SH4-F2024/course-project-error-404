#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFoodRef;
    playerPosList = new objPosArrayList();
    
    myDir = STOP;
}

Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{  
    char input  = mainGameMechsRef->getInput() ;

        switch(input)
        {                      
            case 'w':                                //Moving UP
            case 'W':
                if(myDir != DOWN)                 
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
    objPos NewHeadpos;

    NewHeadpos.pos->x = playerPosList->getHeadElement().pos->x;                         //References towards objPos using NewHeadpos to utilize x,y cooridnates
    NewHeadpos.pos->y = playerPosList->getHeadElement().pos->y;

    objPos food = mainFoodRef->getFoodPos();
 
    switch (myDir)
    { 
        // calculate the new head using the temp objpos 
        case UP:
            NewHeadpos.pos->y --;                                                             //Reducing y coordinates to move the snake 
            NewHeadpos.setsymbol('^');                                                        //setting the head symbol 
            if (NewHeadpos.pos->y == food.pos->y && NewHeadpos.pos->x == food.pos->x)         //Food has been consumed!
            {
                if (NewHeadpos.pos->y <=0)
                {
                    NewHeadpos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
                }
                playerPosList->insertHead(NewHeadpos);                                        //Insertion of head
                mainGameMechsRef->incrementScore();                                            //Increase score 
                mainFoodRef->generateFood(playerPosList);                                       //New food generation as the previous one was finished
            }
            else
            {
                if (NewHeadpos.pos->y <=0)
                {
                    NewHeadpos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
                }
                playerPosList->insertHead(NewHeadpos);                              //Regular wrap around logic navigating throught edges
                playerPosList->removeTail();
            }
            break;

        case DOWN:
            NewHeadpos.pos->y ++;                                            //Increasing y coordinates to move the snake 
            NewHeadpos.setsymbol('v');
            if (NewHeadpos.pos->y == food.pos->y && NewHeadpos.pos->x == food.pos->x)
            {
                if (NewHeadpos.pos->y > mainGameMechsRef->getBoardSizeY() - 2)
                {
                    NewHeadpos.pos->y = 1;
                }
                playerPosList->insertHead(NewHeadpos);
                mainGameMechsRef->incrementScore();
                mainFoodRef->generateFood(playerPosList);
            }
            else
            {
                if (NewHeadpos.pos->y > mainGameMechsRef->getBoardSizeY() - 2)
                {
                    NewHeadpos.pos->y = 1;
                }
                playerPosList->insertHead(NewHeadpos);
                playerPosList->removeTail();
            }
            break;

        case LEFT:
            NewHeadpos.pos->x --;                           //Reducing x coordinates to move the snake 
            NewHeadpos.setsymbol('<');
            if (NewHeadpos.pos->y == food.pos->y && NewHeadpos.pos->x == food.pos->x)
            {
                if (NewHeadpos.pos->x <=0)
                {
                    NewHeadpos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
                }
                playerPosList->insertHead(NewHeadpos);
                mainGameMechsRef->incrementScore();
                mainFoodRef->generateFood(playerPosList);
            }
            else
            {
                if (NewHeadpos.pos->x <=0)
                {
                    NewHeadpos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
                }
                playerPosList->insertHead(NewHeadpos);
                playerPosList->removeTail();
            }
            break;

        case RIGHT:
            NewHeadpos.pos->x ++;                       //Increasing x coordinates to move the snake 
            NewHeadpos.setsymbol('>');
            if (NewHeadpos.pos->y == food.pos->y && NewHeadpos.pos->x == food.pos->x)
            {
                if (NewHeadpos.pos->x > mainGameMechsRef->getBoardSizeX() - 2) // it had <= board x - 1 which is why D wasnt working.
                {
                    NewHeadpos.pos->x = 1;
                }
                playerPosList->insertHead(NewHeadpos);
                mainGameMechsRef->incrementScore();
                mainFoodRef->generateFood(playerPosList);
            }
            else
            {
                if (NewHeadpos.pos->x > mainGameMechsRef->getBoardSizeX() - 2) // it had <= board x - 1 which is why D wasnt working.
                {
                    NewHeadpos.pos->x = 1;
                }
                playerPosList->insertHead(NewHeadpos);
                playerPosList->removeTail();
            }
            break;
    
        default:
            break;
    }    
    
    

    for (int i = 1; i < playerPosList->getSize() && mainGameMechsRef->getScore() > 3 ; i++)                                             //Self-eat Death case
    {
        if(NewHeadpos.pos->x == playerPosList->getElement(i).getObjPos().pos->x  && NewHeadpos.pos->y == playerPosList->getElement(i).getObjPos().pos->y )  //If body position and tail position matches anywhere 
        {
            mainGameMechsRef->setLoseFlag();
            //mainGameMechsRef->setExitTrue();
        }
    }
}

