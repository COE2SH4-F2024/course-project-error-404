#ifndef OBJPOS_H
#define OBJPOS_H

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

        objPos(const objPos& oldObjPos);                        //Copy Constructor
        objPos& operator = (const objPos& oldObjPos);           //Coppy assignment
        ~objPos();                                              //deallocation 
        
        void setsymbol(char sym);
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym); 

        objPos getObjPos() const;
        char getSymbol();
        char getSymbolIfPosEqual(const objPos* refPos) const;
        bool isPosEqual(const objPos* refPos) const;
};

#endif