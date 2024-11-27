#include "Player.h"



Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    
    playerPosList = new objPosArrayList();
    
    myDir = STOP;

    objPos headPos(thisGMRef->getBoardSizeX()/2,thisGMRef->getBoardSizeY()/2,'@');

    // more actions to be included
    // playerPos.pos->x = 10;//mainGameMechsRef->getBoardSizeX()/2;                      // Kar
    // playerPos.pos->y = 5;//mainGameMechsRef->getBoardSizeY()/2;                       
    // playerPos.symbol = '@';    
    //Cause of death IT:3                                               // Kar

    playerPosList->insertHead(headPos);


}


Player::~Player()
{
    // delete any heap members here
    // only when new is inttii -- kar 
    delete playerPosList;
}

//objPos Player::getPlayerPos() const
objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list

    //return the reference to the player objPos array List
    return playerPosList;

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    // int input = 70; what is this 

    char input  = mainGameMechsRef->getInput() ;

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

    objPos NewHeadpos;
    //NewHeadpos.setObjPos() = playerPosList->getHeadElement();
    NewHeadpos.pos->x = playerPosList->getHeadElement().pos->x;
    NewHeadpos.pos->y = playerPosList->getHeadElement().pos->y;


    //
   
    switch (myDir)
    { 
        // calculate the new head using the temp objpos 
        case UP:
            NewHeadpos.pos->y - 1;
            if (NewHeadpos.pos->y <=0)
                {
                    NewHeadpos.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
                }
            //playerPosList->insertHead(NewHeadpos);
            playerPosList->removeTail();
            break;

        case DOWN:
            //playerPos.pos->y++;
            NewHeadpos.pos->y + 1;
            if (NewHeadpos.pos->y >= mainGameMechsRef->getBoardSizeY() - 1)
                {
                    NewHeadpos.pos->y = 1;
                }
            //playerPosList->insertHead(NewHeadpos);
            playerPosList->removeTail();
            break;

        case LEFT:
            NewHeadpos.pos->x - 1;;
            if (NewHeadpos.pos->x <=0)
                {
                    NewHeadpos.pos->x = mainGameMechsRef->getBoardSizeX() - 1;
                }
            //playerPosList->insertHead(NewHeadpos);
            playerPosList->removeTail();
            break;

        case RIGHT:
            NewHeadpos.pos->x + 1;;
            if (NewHeadpos.pos->x >= mainGameMechsRef->getBoardSizeX() - 1) // it had <= board x - 1 which is why D wasnt working.
                {
                    NewHeadpos.pos->x = 1;
                }
            //playerPosList->insertHead(NewHeadpos);
            playerPosList->removeTail();
            break;
    
        default:
            break;
    }    

    playerPosList->insertHead(NewHeadpos);

}

// More methods to be added