#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"         //kar
#include "GameMechs.h"    //Kar
 
using namespace std;

#define DELAY_CONST 100000

Player *myplayer ;          //Pointer towards Player class (Dir[enum],Getlpayerpos[objpos],updateplayerdir,Moveplayer) //kar

GameMechs *myGM;            //Pointer towards GameMechs Class (input ,exitFlag ,loseFlag ,score ,boardSizeX ,boardSizeY ,food )  //kar



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

   
    //myplayer = new Player(nullptr);      //kar
     myGM = new GameMechs();
     myplayer = new Player(myGM);      //kar

 
}

void GetInput(void)
{
    
    if(MacUILib_hasChar())
    {
        myGM->setInput(myGM->getInput());
    }
    char input = myGM->getInput();  //what does it mean choose the correct action 

 
    //or is it get set input cuz we be checking for has input 
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    int width = 20; // for now should change after iteration 1B
    int length = 10; //for now

    objPos playerPos = myplayer->getPlayerPos();

    for(int j = 0; j < length; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if (j == 0 || i == 0 || i == width - 1 || j == length - 1 )
            {
                MacUILib_printf("#"); //Static Contents 
            }
            // else if (i == player.getplayerpos()->x && j == player.getplayerpos()->y) //problem is here cuz to create a player and to do that we need to finish gamemechs (iteration 1B)
            // {
            //     MacUILib_printf("@"); //Dynamic Contents !!!SYNTAX ERROR, WRONG CALLS!!!
            // }
            else if (i == playerPos.pos->x && j == playerPos.pos->y) //problem is here cuz to create a player and to do that we need to finish gamemechs (iteration 1B)
            {
                MacUILib_printf("@"); //Dynamic Contents
            }
            else
            {
                MacUILib_printf(" "); //Static Contents
            }
        }
        MacUILib_printf("\n"); //moves to next row, after writing on the prev row.
    }
    MacUILib_printf("\n");

    MacUILib_printf("Player Position[x,y] = [%d, %d], %c",  playerPos.pos->x,playerPos.pos->y,playerPos.getSymbol() );// NOT WORKING CHECK                 )
    //myplayer->getPlayerPos(); 



}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myplayer;
    delete myGM;

    MacUILib_uninit();
}
