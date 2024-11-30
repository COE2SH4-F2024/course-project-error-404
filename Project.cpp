#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"         //kar
#include "GameMechs.h"    //Kar

#include "Food.h" //rahi
#include <time.h> //rahi
 
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
   
    //myplayer = new Player(nullptr);      //kar
    myGM = new GameMechs();
        

    myFoodItem = new Food();
    myplayer = new Player(myGM, myFoodItem);


    myFoodItem->generateFood(myplayer->getPlayerPos());// give it the body as well?? just get player
    

 
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

    objPos foodPos = myFoodItem->getFoodPos();

    for(int j = 0; j < boardY; j++)
    {
        for (int i = 0; i < boardX; i++)
        {
            // here is the trigger fo rth edo something to determine wethere to continour with the if else flag 

            if (j == 0 || i == 0 || i == boardX - 1 || j == boardY - 1 )
            {
                MacUILib_printf("#"); //Static Contents 
            
            }
            else if(i == foodPos.pos->x && j == foodPos.pos->y)
            {
                MacUILib_printf("%c", foodPos.getSymbol());
            }
            else
            {
                bool exist = false;
                for(int k = 0; k < playersize; k++ )
                {
                    objPos thisseg = playerPos->getElement(k);
                    if(i == thisseg.getObjPos().pos->x && j == thisseg.getObjPos().pos->y)
                    {
                        if (k == 0)
                        {
                            MacUILib_printf("@");
                        }
                        else
                        {
                            MacUILib_printf("@");
                        }
                        exist = true;
                        break;
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
    MacUILib_printf("Length: %d\n",myplayer->getPlayerPos()->getSize());
    MacUILib_printf("Score: %d\n",myGM->getScore());

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
    delete myFoodItem;

    MacUILib_uninit();
}