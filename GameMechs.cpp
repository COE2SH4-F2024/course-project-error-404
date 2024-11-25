#include "GameMechs.h"
#include "MacUILib.h"



GameMechs::GameMechs()
{
    input = 0;
    exitFlag =  false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;
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
    //~remember to add , currently not needed 
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() 
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    // Set two instances of exit    1.Snake eating itself   2.Player pressed Esc

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

// More methods should be added here