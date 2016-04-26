#include "GameBoard.h"
#include <string>
#include <vector>
#include <iostream>

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
    //ctor

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


}

GameBoard::~GameBoard()
{
    //dtor
}




void GameBoard::printShipGrid(){
    std::cout << "        Ship Grid" << std::endl;
    std::cout << "  |A|B|C|D|E|F|G|H|I|J|" << std::endl;
    for (int y = 0; y < 10; y++){
        if (y < 9)
            std::cout << " " << y + 1;
        else
            std::cout << y + 1;
        for (int x = 0; x < 10; x++){
            std::cout << "|";
            if (shipBoardArray[y][x] -> emptyNode == true && shipBoardArray[y][x] -> hit == false){
                std::cout << " ";
            }
            else if (shipBoardArray[y][x] -> emptyNode == true && shipBoardArray[y][x] -> hit == true){
                std::cout << "0";
            }
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}

void GameBoard::printAttackGrid(){ //This is almost identical to the printShipGrid function
    std::cout << "       Attack Grid" << std::endl;
    std::cout << "  |A|B|C|D|E|F|G|H|I|J|" << std::endl;
    for (int y = 0; y < 10; y++){
        if (y < 9)
            std::cout << " " << y + 1;
        else
            std::cout << y + 1;
        for (int x = 0; x < 10; x++){
            std::cout << "|";
            if (attackBoardArray[y][x] -> emptyNode == true && attackBoardArray[y][x] -> hit == false){
                std::cout << " ";
            }
            else if (attackBoardArray[y][x] -> emptyNode == true && attackBoardArray[y][x] -> hit == true){
                std::cout << "0";
            }
        }
        std::cout << "|" << std::endl;
    }
}

void GameBoard::startup(){
    std::cout << "Menu that wants 1 to start the game" << std::endl;
    int selection;
    std::cin >> selection;
    std::cin.ignore();
    if (selection == 1){
        placeShips();
    }
}

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
}
