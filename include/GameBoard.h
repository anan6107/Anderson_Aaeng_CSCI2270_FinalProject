#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>
#include <vector>


struct Ship{
    std::string name;
    int xLoc;
    int yLoc;
    Ship *next;
    Ship *prev;
};

struct GameNode{
    bool emptyNode;
    bool hit;
    Ship *shipPiece;

};


class GameBoard
{
    public:
        GameBoard();
        virtual ~GameBoard();
        void printShipGrid();
        void printAttackGrid();
    protected:
    private:
        GameNode* shipBoardArray[10][10];
        GameNode* attackBoardArray[10][10];
};

#endif // GAMEBOARD_H
