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
        std::cout << "|";
        std::cout << std::endl;
    }
}
