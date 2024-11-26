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
    char input = myGM->getInput();
    
    if(MacUILib_hasChar())
    {
        //myGM->setInput(myGM->getInput());
        myGM->setInput(input);
    }
    
    if(input == '`')
    {
        myGM->setExitTrue();
    }   
    //myplayer->movePlayer();
    else ;
     
    //or is it get set input cuz we be checking for has input 
}

void RunLogic(void)
{
    // char input = myGM->getInput();  //what does it mean choose the correct action 

    myplayer->updatePlayerDir();
    myplayer->movePlayer();
    
    // just added these two lines here.


    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    int width; 
    int length;

    width = myGM->getBoardSizeX();
    length = myGM->getBoardSizeY();


    objPos playerPos = myplayer->getPlayerPos();

    for(int j = 0; j < length; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if (j == 0 || i == 0 || i == width - 1 || j == length - 1 )
            {
                MacUILib_printf("#"); //Static Contents 
            }
            else if (i == playerPos.pos->x && j == playerPos.pos->y) 
            {
                MacUILib_printf("%c", playerPos.getSymbol()); //Dynamic Contents this was wrong before.
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
    //MacUILib_printf("Current input is %" ) 
    



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
