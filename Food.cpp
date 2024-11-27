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

void Food::generateFood(objPos blockOff) //food generation, block off is player position
{
    int width = 20;
    int length = 10;

    int myBitVx[width] = {0};
    int myBitVy[length] = {0};
    int a, b, c;

    //generating x coordinate

    do 
    {
        foodPos.pos->x = rand() % width; // gives a random number from 0 to width -1.

    } while (foodPos.pos->x == blockOff.pos->x || foodPos.pos->x == 0 || foodPos.pos->x == width -1);

    do
    {
        foodPos.pos->y = rand() % length; // gives a random number from 0 to length -1

    } while (foodPos.pos->y == blockOff.pos->y || foodPos.pos->y == 0 || foodPos.pos->y == length -1);


    //asci numbers 0-127
    // usefull ones start from 33 - 126, cant use 35 (#) and 64 (@)
    // c = (rand() % 94) + 33 --> (0 --> 93) + 33 = [33 --> 126]

    do
    {
        foodPos.symbol = (rand() % 94) +33;
    } while(foodPos.symbol == 35 || foodPos.symbol == 64);
    
}

objPos Food::getFoodPos() const
{
    return foodPos;
}
