#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// copy constructor 
objPos::objPos(const objPos& oldObjPos)
{
    symbol = oldObjPos.symbol;
    pos = new Pos;
    pos->x = oldObjPos.pos->x;
    pos->y = oldObjPos.pos->y;
}

//copy assignment operator
objPos& objPos::operator = (const objPos& oldObjPos)
{
    if(this == &oldObjPos) return *this;         //doesn't allow duplicates or self-assignments
    delete pos;

    pos = new Pos;
    pos->x = oldObjPos.pos->x;
    pos->y = oldObjPos.pos->y;
    symbol = oldObjPos.symbol;
}

//destructor 
objPos::~objPos()
{
    delete pos;
}

void objPos::setsymbol(char sym)
{
    symbol = sym;
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol()
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
