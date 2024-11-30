#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

#include "Food.h"

class Player
{  
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef);
        ~Player();

        objPosArrayList* getPlayerPos() const;
        void updatePlayerDir();
        void movePlayer();

    private:
    
        objPosArrayList* playerPosList;               //Reference towards Player class
        enum Dir myDir;
        GameMechs* mainGameMechsRef;                 //Refernce towards gamemechs
        Food* mainFoodRef;                            //reference to the food
};

#endif