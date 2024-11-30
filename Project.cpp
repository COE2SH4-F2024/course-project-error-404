#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"       
#include "GameMechs.h"    

#include "Food.h" 
#include <time.h> 
 
using namespace std;

#define DELAY_CONST 100000

Player *myplayer ;          //Pointer towards Player class (Dir[enum],Getlpayerpos[objpos],updateplayerdir,Moveplayer) //kar
GameMechs *myGM;            //Pointer towards GameMechs Class (input ,exitFlag ,loseFlag ,score ,boardSizeX ,boardSizeY ,food )  //kar
Food *myFoodItem;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    Initialize();

    while(myGM->getExitFlagStatus() == false)  //program updated to retrive get flag from game mechs - kar
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    srand(time(NULL));

    myGM = new GameMechs();                             //Creating a new reference to gamemechanis 
    myFoodItem = new Food();                            //Creating a new reference to Food
    myplayer = new Player(myGM, myFoodItem);            //Creating a new reference to Player 

    myFoodItem->generateFood(myplayer->getPlayerPos());

 
}

void GetInput(void)
{  
    myGM->collectAsyncInput();
}

void RunLogic(void)
{
    myplayer->updatePlayerDir();
    myplayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPosArrayList* playerPos = myplayer->getPlayerPos();
    int playersize = playerPos->getSize();          //Gets snake size
    int boardX = myGM->getBoardSizeX();             //Default board width
    int boardY = myGM->getBoardSizeY();              //Default board length 

    objPos foodPos = myFoodItem->getFoodPos();

    for(int j = 0; j < boardY; j++)
    {
        for (int i = 0; i < boardX; i++)
        {
            if (j == 0 || i == 0 || i == boardX - 1 || j == boardY - 1 )
            {   
                MacUILib_printf("*");                                   //Static Contents 
            
            }
            else if(i == foodPos.pos->x && j == foodPos.pos->y)
            {
                MacUILib_printf("%c", foodPos.getSymbol());             //Dynamic food content 
            }
            else
            {
                bool exist = false;                                     //exist detrmines snake's presence in x,y coordinate 
                for(int k = 0; k < playersize; k++ )                    //an itteration to print the whole body of snake thru all x,y coordinates
                {
                    objPos thisseg = playerPos->getElement(k);
                    if(i == thisseg.getObjPos().pos->x && j == thisseg.getObjPos().pos->y) 
                    {
                        if (k == 0)
                        {
                            MacUILib_printf("%c",thisseg.getSymbol());          //Printing head-symbol of snake                  
                        }
                        else
                        {
                            MacUILib_printf("o");                               //Printing body of the snake 
                        }
                        exist = true;
                        break;
                    }
                }
                if(!exist)
                {
                    MacUILib_printf(" ");               //Printing Empty shell of the box
                }        
            }
        }
        MacUILib_printf("\n");              //moves to next row, after writing on the prev row.
    }
    MacUILib_printf("\n");
    MacUILib_printf("Use 'W' 'A' 's' 'D' to move\n");
    MacUILib_printf("Snake Length: %d\n",myplayer->getPlayerPos()->getSize());
    MacUILib_printf("Score: %d\n",myGM->getScore());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myplayer;               //Freeing up variables on Heap memory 
    delete myGM;
    delete myFoodItem;

    MacUILib_uninit();
}