#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>
#include <vector>
#include <cstdlib>

<<<<<<< HEAD
/*
=======
/*RIP STRUCT
>>>>>>> origin/master
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
	}
};
*/


struct GameNode{
    bool emptyNode;
    bool hit;
    std::string shipName;

struct GameNode{
    bool emptyNode;
    bool hit;
    //Ship *shipPiece;
    GameNode *next;

};


class GameBoard
{
    public:
        GameBoard();
        virtual ~GameBoard();
        void makeShipBoard();
        void makeAttackBoard();
        void printShipGrid();
        void printAttackGrid();
        void MakeShipBoard();
        void MakeAttackBoard();
        void startup();
        int pAttack(int column, int row);
        int compAttack(int column, int row);
        void compTurn();
        void playerTurn();
        void playGame();
    protected:
    private:
        GameNode* shipBoardArray[10][10];
        GameNode* attackBoardArray[10][10];
        GameNode* playerShips[5];
        GameNode* compShips[5];
<<<<<<< HEAD
        bool compFound = false;
        bool compVert = false;
        bool knownOrientation = false;
        int firstX;
        int firstY;
        int compX;
        int compY;
=======
>>>>>>> origin/master
};

#endif // GAMEBOARD_H
