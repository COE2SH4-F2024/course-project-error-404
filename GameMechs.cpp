#include "GameMechs.h"

GameMechs::GameMechs()
{
    //Rahimeen
}

GameMechs::GameMechs(int boardX, int boardY)
{
    
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
    

char GameMechs::getInput() const
{
    
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

}

void GameMechs::clearInput()
{

}

// More methods should be added here