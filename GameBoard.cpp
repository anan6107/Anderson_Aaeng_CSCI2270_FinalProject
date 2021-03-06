#include "GameBoard.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

GameBoard::GameBoard()
{
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            shipBoardArray[y][x] = new GameNode;
            shipBoardArray[y][x] -> emptyNode = true;
            shipBoardArray[y][x] -> hit = false;

            attackBoardArray[y][x] = new GameNode;
            attackBoardArray[y][x] -> emptyNode = true;
            attackBoardArray[y][x] -> hit = false;
        }
    }

    for (int i = 0; i < 5; i++){
        playerShips[i] = NULL;
        compShips[i] = NULL;
    }
    //ctor

    /*
    playerShips[0] = new Ship("Aircraft Carrier", 5);
    playerShips[1] = new Ship("Submarine", 3);
    playerShips[2] = new Ship("Cruiser", 3);
    playerShips[3] = new Ship("Battleship", 4);
    playerShips[4] = new Ship("Patrol Boat", 2);

    compShips[0] = new Ship("Aircraft Carrier", 5);
    compShips[1] = new Ship("Submarine", 3);
    compShips[2] = new Ship("Cruiser", 3);
    compShips[3] = new Ship("Battleship", 4);
    compShips[4] = new Ship("Patrol Boat", 2);
    */


}

GameBoard::~GameBoard()
{
    //dtor
}






void GameBoard::printShipGrid(){
    std::cout << "       Ship Grid" << std::endl;
    std::cout << " |0|1|2|3|4|5|6|7|8|9|" << std::endl;
    for (int y = 0; y < 10; y++){
        std::cout << y;
        for (int x = 0; x < 10; x++){
            std::cout << "|";
            if (shipBoardArray[y][x] -> emptyNode == true && shipBoardArray[y][x] -> hit == false){
                std::cout << " ";
            }
            else if (shipBoardArray[y][x] -> emptyNode == false && shipBoardArray[y][x] -> hit == true){
                std::cout << "@";
            }
            else if (shipBoardArray[y][x] -> emptyNode == false && shipBoardArray[y][x] -> hit == false){
                std::cout << "o";
            }
            else if (shipBoardArray[y][x] -> emptyNode == true && shipBoardArray[y][x] -> hit == true){
                std::cout << "X";
            }
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}

void GameBoard::printAttackGrid(){
    std::cout << "      Attack Grid" << std::endl;
    std::cout << " |0|1|2|3|4|5|6|7|8|9|" << std::endl;
    for (int y = 0; y < 10; y++){
            std::cout << y;
        for (int x = 0; x < 10; x++){
            std::cout << "|";
            if (attackBoardArray[y][x] -> hit == false){
                std::cout << " ";
            }
            else if (attackBoardArray[y][x] -> emptyNode == true && attackBoardArray[y][x] -> hit == true){
                std::cout << "X";
            }
            else if (attackBoardArray[y][x] -> emptyNode == false && attackBoardArray[y][x] -> hit == true){
                std::cout << "@";
            }
        }
        std::cout << "|" << std::endl;
    }
}

int GameBoard::pAttack(int column, int row){
    if (column < 0 || column > 9 || row < 0 || row > 9){
        return 1;
    }
    if (attackBoardArray[column][row] -> hit == true){
        return 1;
    }
    else{
        attackBoardArray[column][row] -> hit = true;
        return 0;
    }
}


int GameBoard::compAttack(int column, int row){
    if (column < 0 || column > 9 || row < 0 || row > 9){
        return 1;
    }
    if (shipBoardArray[column][row] -> hit == true){
        return 1;
    }
    else{
        shipBoardArray[column][row] -> hit = true;
        return 0;
    }
}


void GameBoard::compTurn(){
    srand(time(0));
    int test = 1;
    int randX;
    int randY;
    int direction;
    while (test != 0){
        randX = std::rand() % 10;
        randY = std::rand() % 10;
        test = compAttack(randX, randY);
    }

    /*if (compFound == false){
            randX = std::rand() % 10;
            randY = std::rand() % 10;
            test = compAttack(randX, randY);
        }
        compFound = true;
        firstX = randX;
        firstY = randY;
        //need to set the bool to true
    }
    else{
        if (!knownOrientation){
            while (test != 0){
                direction = std::rand() % 4 + 1;
                if (direction == 1){

                }
            }
        }
    }*/
}


void GameBoard::startup(){
    std::cout << "Welcome to Battleship!" << std::endl << std::endl;
    //getline(std::cin, filler);
    makeAttackBoard();
    makeShipBoard();
}

void GameBoard::playerTurn(){
    int test = 1;
    int x;
    int y;
    while (test != 0){
        std::cout << "Enter targeted column:" << std::endl;
        std::cin >> y;
        std::cout << "Enter targeted row:" << std::endl;
        std::cin >> x;
        test = pAttack(x, y);
        if (test != 0){
            std::cout << "Please enter valid coordinates" << std::endl;
        }
    }
}

void GameBoard::playGame(){
    bool inPlay = true;
    while (inPlay){
        int playerNodes = 17;
        int compNodes = 17;

        printAttackGrid();
        printShipGrid();

        playerTurn();
        compTurn();

        for (int x = 0; x < 5; x++){
            GameNode *tmp = playerShips[x];

            while (tmp != NULL){
                if (tmp -> hit == true){
                    playerNodes--;
                }
                tmp = tmp -> next;
            }
            tmp = compShips[x];

            while (tmp != NULL){
                if (tmp -> hit == true){
                    compNodes--;
                }
                tmp = tmp -> next;
            }
        }
        if (playerNodes == 0 || compNodes == 0){
            inPlay = false;
        }
    }
    std::cout << "Game Over!" << std::endl;
}

/* //rip in peace placeShips function.  You never worked though you will be missed
void GameBoard::placeShips(){
    std::string shipName;
    std::string orientation;
    std::string column;
    int row;

    int shipsPlaced = 0;
    std::vector<std::string> namesUsed;

    bool newShip;
    bool realShip;

    while (shipsPlaced < 5){
        newShip = true;

        std::cout << "Enter ship name (Aircraft Carrier, Submarine, Destroyer, Battleship, Cruiser):" << std::endl;
        getline(std::cin, shipName);
        std::cout << "Enter ship orientation (Left, Right, Up, Down):" << std::endl;
        getline(std::cin, orientation);
        std::cout << "Enter column (A-J):" << std::endl;
        getline(std::cin, column);
        std::cout << "Enter row (1-10):" << std::endl;
        std::cin >> row;
        std::cin.ignore();

    }
}*/


void GameBoard::makeShipBoard()
{
    int sadness;
    srand(time(0));
    sadness=rand()%3+1;


    if (sadness==1)
    {
		//Aircraft Carrier(5)
		for (int y=2;y<7;y++)
		{
			shipBoardArray[1][y]->emptyNode=false;
		}
			playerShips[0]=shipBoardArray[1][2];
				shipBoardArray[1][2]->next=shipBoardArray[1][3];
				shipBoardArray[1][3]->next=shipBoardArray[1][4];
				shipBoardArray[1][4]->next=shipBoardArray[1][5];
				shipBoardArray[1][6]->next=shipBoardArray[1][6];
		//Battleship(4)
		for (int x=2;x<5;x++)
		{
			shipBoardArray[x][8]->emptyNode=false;
		}
			playerShips[1]=shipBoardArray[2][8];
				shipBoardArray[2][8]->next=shipBoardArray[3][8];
				shipBoardArray[3][8]->next=shipBoardArray[4][8];
				shipBoardArray[4][8]->next=shipBoardArray[5][8];
		//Submarine(3)
		for (int y=4;y<7;y++)
		{
			shipBoardArray[3][y]->emptyNode=false;
		}
			playerShips[2]=shipBoardArray[3][4];
				shipBoardArray[3][4]->next=shipBoardArray[3][5];
				shipBoardArray[3][5]->next=shipBoardArray[3][6];
		//Cruiser(3)
		for (int x=4;x<7;x++)
		{
			shipBoardArray[1][x]->emptyNode=false;
		}
			playerShips[3]=shipBoardArray[1][4];
				shipBoardArray[1][4]->next=shipBoardArray[1][5];
				shipBoardArray[1][5]->next=shipBoardArray[1][6];
		//Patrol Boat(2)
		for (int y=3;y<5;y++)
		{
			shipBoardArray[8][y]->emptyNode=false;
		}
			playerShips[4]=shipBoardArray[8][3];
				shipBoardArray[8][3]->next=shipBoardArray[8][4];
	}
	else if (sadness==2)
	{
		//Aircraft Carrier(5)
		for (int x=2;x<7;x++)
		{
			shipBoardArray[x][7]->emptyNode=false;
		}
			playerShips[0]=shipBoardArray[2][7];
				shipBoardArray[2][7]->next=shipBoardArray[3][7];
				shipBoardArray[3][7]->next=shipBoardArray[4][7];
				shipBoardArray[4][7]->next=shipBoardArray[5][7];
				shipBoardArray[5][7]->next=shipBoardArray[6][7];
		//Battleship(4)
		for (int y=3;y<7;y++)
		{
			shipBoardArray[8][y]->emptyNode=false;
		}
			playerShips[1]=shipBoardArray[8][3];
				shipBoardArray[8][3]->next=shipBoardArray[8][4];
				shipBoardArray[8][4]->next=shipBoardArray[8][5];
				shipBoardArray[8][5]->next=shipBoardArray[8][6];
		//Submarine(3)
		for (int y=1;y<4;y++)
		{
			shipBoardArray[2][y]->emptyNode=false;
		}
			playerShips[2]=shipBoardArray[2][1];
				shipBoardArray[2][1]->next=shipBoardArray[2][2];
				shipBoardArray[2][2]->next=shipBoardArray[2][3];
		//Cruiser(3)
		for (int y=1;y<4;y++)
		{
			shipBoardArray[6][y]->emptyNode=false;
		}
			playerShips[3]=shipBoardArray[6][1];
				shipBoardArray[6][1]->next=shipBoardArray[6][2];
				shipBoardArray[6][3]->next=shipBoardArray[6][4];
		//Patrol Boat(2)
		for (int y=8;y<10;y++)
		{
			shipBoardArray[8][y]->emptyNode=false;
		}
			playerShips[4]=shipBoardArray[8][8];
				shipBoardArray[8][8]->next=shipBoardArray[8][9];
	}
	else if (sadness==3)
	{
		//Aircraft Carrier(5)
		for(int x=0;x<5;x++)
		{
			shipBoardArray[x][9]->emptyNode=false;
		}
		playerShips[0]=shipBoardArray[0][9];
			shipBoardArray[0][9]->next=shipBoardArray[1][9];
			shipBoardArray[1][9]->next=shipBoardArray[2][9];
			shipBoardArray[2][9]->next=shipBoardArray[3][9];
			shipBoardArray[3][9]->next=shipBoardArray[4][9];
		//Battleship(4)
		for (int y=1;y<5;y++)
		{
			shipBoardArray[2][y]->emptyNode=false;
		}
			playerShips[1]=shipBoardArray[2][1];
				shipBoardArray[2][1]->next=shipBoardArray[2][2];
				shipBoardArray[2][2]->next=shipBoardArray[2][3];
				shipBoardArray[2][3]->next=shipBoardArray[2][4];
		//Submarine(3)
		for (int y=0;y<3;y++)
		{
			shipBoardArray[8][y]->emptyNode=false;
		}
			playerShips[2]=shipBoardArray[8][0];
				shipBoardArray[8][0]->next=shipBoardArray[8][1];
				shipBoardArray[8][1]->next=shipBoardArray[8][2];
		//Cruiser(3)
		for (int x=4;x<7;x++)
		{
			shipBoardArray[x][1]->emptyNode=false;
		}
			playerShips[3]=shipBoardArray[4][1];
				shipBoardArray[4][1]->next=shipBoardArray[5][1];
				shipBoardArray[5][1]->next=shipBoardArray[6][1];
		//Patrol Boat(2)
		for (int x=5;x<7;x++)
		{
			shipBoardArray[x][7]->emptyNode=false;
		}
			playerShips[4]=shipBoardArray[5][7];
				shipBoardArray[5][7]->next=shipBoardArray[6][7];
	}
}


void GameBoard::makeAttackBoard()
{
    int sadness;
    srand(time(0));
    sadness=rand()%3+1;

	if (sadness==1)
    {
		//Aircraft Carrier(5)
		for (int y=2;y<7;y++)
		{
			attackBoardArray[1][y]->emptyNode=false;
		}
			compShips[0]=attackBoardArray[1][2];
				attackBoardArray[1][2]->next=attackBoardArray[1][3];
				attackBoardArray[1][3]->next=attackBoardArray[1][4];
				attackBoardArray[1][4]->next=attackBoardArray[1][5];
				attackBoardArray[1][6]->next=attackBoardArray[1][6];
		//Battleship(4)
		for (int x=2;x<5;x++)
		{
			attackBoardArray[x][8]->emptyNode=false;
		}
			compShips[1]=attackBoardArray[2][8];
				attackBoardArray[2][8]->next=attackBoardArray[3][8];
				attackBoardArray[3][8]->next=attackBoardArray[4][8];
				attackBoardArray[4][8]->next=attackBoardArray[5][8];
		//Submarine(3)
		for (int y=4;y<7;y++)
		{
			attackBoardArray[3][y]->emptyNode=false;
		}
			compShips[2]=attackBoardArray[3][4];
				attackBoardArray[3][4]->next=attackBoardArray[3][5];
				attackBoardArray[3][5]->next=attackBoardArray[3][6];
		//Cruiser(3)
		for (int x=4;x<7;x++)
		{
			attackBoardArray[1][x]->emptyNode=false;
		}
			compShips[3]=attackBoardArray[1][4];
				attackBoardArray[1][4]->next=attackBoardArray[1][5];
				attackBoardArray[1][5]->next=attackBoardArray[1][6];
		//Patrol Boat(2)
		for (int y=3;y<5;y++)
		{
			attackBoardArray[8][y]->emptyNode=false;
		}
			compShips[4]=attackBoardArray[8][3];
				attackBoardArray[8][3]->next=attackBoardArray[8][4];
	}
	else if (sadness==2)
	{
		//Aircraft Carrier(5)
		for (int x=2;x<7;x++)
		{
			attackBoardArray[x][7]->emptyNode=false;
		}
			compShips[0]=attackBoardArray[2][7];
				attackBoardArray[2][7]->next=attackBoardArray[3][7];
				attackBoardArray[3][7]->next=attackBoardArray[4][7];
				attackBoardArray[4][7]->next=attackBoardArray[5][7];
				attackBoardArray[5][7]->next=attackBoardArray[6][7];
		//Battleship(4)
		for (int y=3;y<7;y++)
		{
			attackBoardArray[8][y]->emptyNode=false;
		}
			compShips[1]=attackBoardArray[8][3];
				attackBoardArray[8][3]->next=attackBoardArray[8][4];
				attackBoardArray[8][4]->next=attackBoardArray[8][5];
				attackBoardArray[8][5]->next=attackBoardArray[8][6];
		//Submarine(3)
		for (int y=1;y<4;y++)
		{
			attackBoardArray[2][y]->emptyNode=false;
		}
			compShips[2]=attackBoardArray[2][1];
				attackBoardArray[2][1]->next=attackBoardArray[2][2];
				attackBoardArray[2][2]->next=attackBoardArray[2][3];
		//Cruiser(3)
		for (int y=1;y<4;y++)
		{
			attackBoardArray[6][y]->emptyNode=false;
		}
			compShips[3]=attackBoardArray[6][1];
				attackBoardArray[6][1]->next=attackBoardArray[6][2];
				attackBoardArray[6][3]->next=attackBoardArray[6][4];
		//Patrol Boat(2)
		for (int y=8;y<10;y++)
		{
			attackBoardArray[8][y]->emptyNode=false;
		}
			compShips[4]=attackBoardArray[8][8];
				attackBoardArray[8][8]->next=attackBoardArray[8][9];
	}
	else if (sadness==3)
	{
		//Aircraft Carrier(5)
		for(int x=0;x<5;x++)
		{
			attackBoardArray[x][9]->emptyNode=false;
		}
			compShips[0]=attackBoardArray[0][9];
				attackBoardArray[0][9]->next=attackBoardArray[1][9];
				attackBoardArray[1][9]->next=attackBoardArray[2][9];
				attackBoardArray[2][9]->next=attackBoardArray[3][9];
				attackBoardArray[3][9]->next=attackBoardArray[4][9];
		//Battleship(4)
		for (int y=1;y<5;y++)
		{
			attackBoardArray[2][y]->emptyNode=false;
		}
			compShips[1]=attackBoardArray[2][1];
				attackBoardArray[2][1]->next=attackBoardArray[2][2];
				attackBoardArray[2][2]->next=attackBoardArray[2][3];
				attackBoardArray[2][3]->next=attackBoardArray[2][4];
		//Submarine(3)
		for (int y=0;y<3;y++)
		{
			attackBoardArray[8][y]->emptyNode=false;
		}
			compShips[2]=attackBoardArray[8][0];
				attackBoardArray[8][0]->next=attackBoardArray[8][1];
				attackBoardArray[8][1]->next=attackBoardArray[8][2];
		//Cruiser(3)
		for (int x=4;x<7;x++)
		{
			attackBoardArray[x][1]->emptyNode=false;
		}
			compShips[3]=attackBoardArray[4][1];
				attackBoardArray[4][1]->next=attackBoardArray[5][1];
				attackBoardArray[5][1]->next=attackBoardArray[6][1];
		//Patrol Boat(2)
		for (int x=5;x<7;x++)
		{
			attackBoardArray[x][7]->emptyNode=false;
		}
			compShips[4]=attackBoardArray[5][7];
				attackBoardArray[5][7]->next=attackBoardArray[6][7];
	}
}
