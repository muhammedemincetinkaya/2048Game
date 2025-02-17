#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Line.h"

/*
    The grid class represents the game board using the Line class.
    It also manages movement of the grid and merging of the tiles.
*/

class Grid {
public:
    std::vector<std::vector<int>> grid; // 2D Vector representing the grid.

    /*
        Constructor that initializes a n x n grid and starts the game with one tile.
    */
    Grid(int n);

    //Methods for extracting rows and columns
    Line extractRow(int i);
    Line extractRowReverse(int i);
    Line extractColumn(int i);
    Line extractColumnReverse(int i);

    // Methods for moving the tiles
    void updateLeft();
    void updateRight();
    void updateUp();
    void updateDown();

    /*
        Adds a new tile with number 2 at a random position in the grid
    */
    void addRandom();
    /*
        Prints the grid to the console
    */
    void printGrid();
    /*
        Runs the game.
    */
    void runGame();
};

#endif // GRID_H
