## Remake of the game Rummikub, just to get my C++ skills going again.

Requirements:
- After the user has dragged and dropped a tile, the game should verify whether the intended move is legal. If not, revert back to the old situation.
- If the user their round finishes, and didn't have any tiles on the board before, check if the total sum of the tiles is at least 30. If not, revert back to the old situation.
- Got to keep 2 boards in memory: 1 before the player their round started, and 1 for the current board. If the current board is not valid at the end of the round, everything should revert to the original board. Another solution would be to save all the player their moves in the current round, and undo all the moves if the board is invalid.


Board -> Tiles

Tile.MoveTo(x,y)
