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