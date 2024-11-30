#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef);
        ~Player();

        //objPos getPlayerPos() const; // Upgrade this in iteration 3.       This will die too
        objPosArrayList* getPlayerPos() const;
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here

    private:
        //objPos playerPos; // Upgrade this in iteration 3.   This dude will die

        objPosArrayList* playerPosList; //Pointer towards Player class !!! THE UPGRADE BITCHES

        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

        //reference to the food
        Food* mainFoodRef;

        
};

#endif