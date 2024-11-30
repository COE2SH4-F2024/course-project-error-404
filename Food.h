#ifndef FOOD_H
#define FOOD_H

#include <time.h>
#include <cstdlib>

#include "objPos.h"
#include "time.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    public:
        Food();
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        objPos getFoodPos() const;



    private:
        objPos foodPos;



};

#endif