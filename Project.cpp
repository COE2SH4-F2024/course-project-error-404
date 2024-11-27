#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"         //kar
#include "GameMechs.h"    //Kar
 
using namespace std;

#define DELAY_CONST 100000

Player *myplayer ;          //Pointer towards Player class (Dir[enum],Getlpayerpos[objpos],updateplayerdir,Moveplayer) //kar
GameMechs *myGM;            //Pointer towards GameMechs Class (input ,exitFlag ,loseFlag ,score ,boardSizeX ,boardSizeY ,food )  //kar

objPosArrayList *playerPosList; //Pointer towards objArrayList class !!!


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
    playerPosList = new objPosArrayList(); //kar


 
}

void GetInput(void)
{
    //char input = myGM->getInput();  -- will change into next line 
    
    myGM->collectAsyncInput();

    // if(MacUILib_hasChar())
    // {
    //     //myGM->setInput(myGM->getInput());
    //     myGM->setInput(input);
    // }
    //removed exit flag 
    //myplayer->movePlayer();
    // else 
    // ;
     
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


    //objPos playerPos = myplayer->getPlayerPos();
    objPosArrayList* playerPos = myplayer->getPlayerPos();
    int playersize = playerPos->getSize();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    for(int j = 0; j < boardY; j++)
    {
        for (int i = 0; i < boardX; i++)
        {
            // here is the trigger fo rth edo something to determine wethere to continour with the if else flag 

            if (j == 0 || i == 0 || i == boardX - 1 || j == boardY - 1 )
            {
                MacUILib_printf("#"); //Static Contents 
            }
            // else if (i == playerPos.pos->x && j == playerPos.pos->y) 
            // {
            //     MacUILib_printf("%c", playerPos.getSymbol()); //Dynamic Contents this was wrong before.
            // } 
            // else if (i == playerPos->getHeadElement().pos->x && j == playerPos->getHeadElement().pos->y) 
            // {
            //     //MacUILib_printf("%c", playerPosgetSymbol()); //Dynamic Contents this was wrong before.
            //     //MacUILib_printf(const playerPos->getHeadElement().getSymbol());                            //YOUSEDD
            //     MacUILib_printf("@");
            // }// told to cmment out by chen 

            
            
            else
            {
                bool exist = false;
                for(int k = 0; k < playersize; k++ )
                {
                    objPos thisseg = playerPos->getElement(k);
                    if(i == thisseg.getObjPos().pos->x && j == thisseg.getObjPos().pos->y)
                    {
                        MacUILib_printf("@");
                        exist = true;
                    }
                }
                if(!exist)
                {
                    MacUILib_printf(" ");
                }


                //         //It 3 : check if the current segment is x,Y postion matches the (i,j) coordinates 
                //         // If yes print the symbol 
                //         /// wathc out we need ot skip if else block belwo if we hav eprinted something in the for loop; we need to use the boolean flag continue
                //     //}
                // }
            
            
            }


        }
        MacUILib_printf("\n"); //moves to next row, after writing on the prev row.
    }
    MacUILib_printf("\n");

    //MacUILib_printf("Player Position[x,y] = [%d, %d], %c",  playerPos->getHeadElement().pos->x, playerPos->getHeadElement().pos->y );// NOT WORKING CHECK                 )
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
    delete playerPosList;

    MacUILib_uninit();
}