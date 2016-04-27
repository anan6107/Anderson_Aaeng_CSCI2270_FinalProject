Project Summary:
At runtime, the project randomly selects one of three boards for the player and the opponent.  These boards are pre-programmed and they are selected with the rand() function.  These boards are created by editing the generic 2D arrays that represent the boards with a series of for loops.  When placing the ships, linked lists are generated that represent each ship.  These boards are then displayed to the player.  The player then enters the row and column that they want to target.  If those coordinates are not valid, they are told to enter new coordinates.  The AI then randomly selects coordinates to target.  These coordinates are always unique so it will not attack the same location twice.  At the end of each turn, the linked lists are searched to determine if there are still ships in play.  If there are not, the game ends.

Dependencies:
None

System Requirements:
None

Group Members/Contributors
Aaron Aaeng and Anna Anderson

Known Issues:
Occasionally, the first coordinate entered forces the game into an infinite loop.  However, this is solved by restarted the game.  This only happened twice out of the many times that I attempted to run it and I can't identify the problem at this time.

How to Run:
We tried for quite a long time and asked for help from people who know github far beter than we do, but we simply could not get the other (master) branch to work. We're sorry for any inconvenience this might cause. However, as a result, you will have to run the three files (two for the class and the main.cpp file) from the BattleShip folder in the TrueMaster branch. Open and compile how you usually would using your given terminal. From there, it's simple. Follow the instructions given in the game.
