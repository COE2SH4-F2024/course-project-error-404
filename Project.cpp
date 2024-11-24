#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000



bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    int width = 20; // for now should change after iteration 1B
    int length = 10; //for now

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
            //     MacUILib_printf("@"); //Dynamic Contents
            // }
            else
            {
                MacUILib_printf(" "); //Static Contents
            }
        }
        MacUILib_printf("\n"); //moves to next row, after writing on the prev row.
    }
    MacUILib_printf("\n");

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
