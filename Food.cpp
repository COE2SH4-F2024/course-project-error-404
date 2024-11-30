#include "Food.h"

Food::Food() // default
{
    foodPos.symbol = '\0';
    foodPos.pos->x = -1;
    foodPos.pos->y = -1; 
}

Food::~Food() //destructor
{
    //do we need it?
}

void Food::generateFood(objPosArrayList* blockOff)       //food generation, block off is player position
{
    int width = 20;
    int length = 10;                                    // gonna have to change in future.DO WE NEED THIS?? 

    int myBitVx[width] = {0};
    int myBitVy[length] = {0}; 
    int a, b, c;

    bool validPos = false;

    while(!validPos)
    {
        foodPos.pos->x = (rand() % (width - 2)) + 1;     // gives a random number from 1 to width -2.
        foodPos.pos->y = (rand() % (length - 2)) + 1;    // gives a random number from 1 to length -2
        validPos = true;                                 // assume new food position is valid initially

        for (int i = 0; i < blockOff->getSize(); i++)
        {
            if (foodPos.pos->x == blockOff->getElement(i).pos->x && foodPos.pos->y == blockOff->getElement(i).pos->y)
            {
                validPos = false; //The food coordinates are invalid
                break; //no need to check further
            }
        }
    }
    //asci numbers 0-127
    // usefull ones start from 33 - 126, cant use 35 (#) and 64 (@)
    // c = (rand() % 94) + 33 --> (0 --> 93) + 33 = [33 --> 126]\
    do
    {
        foodPos.symbol = (rand() % 94) +33;
    } while(foodPos.symbol == 35 || foodPos.symbol == 64);
}

objPos Food::getFoodPos() const
{
    return foodPos;
}
