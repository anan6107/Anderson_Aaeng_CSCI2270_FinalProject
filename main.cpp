#include <iostream>
#include <string>
#include <vector>
#include "GameBoard.h"

using namespace std;

int main()
{
    GameBoard g;
    g.printAttackGrid();
    g.printShipGrid();
    string s = "abcdefghijklmnopqrstuvwxyz";
    string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int x = 0; x < 26; x++){
        int sum = s[x];
        cout << sum - 96<< endl;
        sum = s2[x];
        cout << sum - 64 << endl;
    }
    return 0;
}
