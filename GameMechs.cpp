#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag =  false;
    loseFlag = false;
    score = 0;

    boardSizeX = 20;
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag =  false;
    loseFlag = false;
    score = 0;
    
    boardSizeX = boardSizeX;
    boardSizeY = boardSizeY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
   
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
void GameMechs::collectAsyncInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
     if(input == '`')
    {   
        //myGM->setExitTrue();
        exitFlag = true;
    }   
}

char GameMechs::getInput() const
{
    return input; 
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++; // might have to change later
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;  //IF KARTHIK IS NOT wrong
}

