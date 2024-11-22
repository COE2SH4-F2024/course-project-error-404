#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos();
        objPos(int xPos, int yPos, char sym);
        objPos(const objPos &d);                // USER-DEFINED copy opertaor 
        objPos& operator=(const objPos &d);     // USER-DEFINED copy ASSIGNMENT opertaor 

        
        // Respect the rule of six / minimum four

        objPos(const objPos& oldObjPos);
        objPos& operator = (const objPos& oldObjPos);
        ~objPos();

        // [TODO] Implement the missing special member functions to meet the minimum four rule
        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif