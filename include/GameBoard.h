#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>
#include <vector>


struct Ship{
    std::string name;
    int xLoc;
    int yLoc;
    int length;
    Ship *next;
    Ship *prev;
    Ship(){};
	Ship(std::string name, int length)
	{
		name = name;
		length = length;
		next = NULL;
		prev = NULL;
	}
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
        void startup();
        void placeShips();
//        void placeShip(std::string shipName, std::string orientation, std::string column, int row);
    protected:
    private:
        GameNode* shipBoardArray[10][10];
        GameNode* attackBoardArray[10][10];
        Ship* playerShips[5];
        Ship* compShips[5];
};

#endif // GAMEBOARD_H
