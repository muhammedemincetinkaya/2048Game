#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Line.h"

class Grid {
public:
    std::vector<std::vector<int>> grid;

    Grid(int n);
    Line extractRow(int i);
    Line extractRowReverse(int i);
    Line extractColumn(int i);
    Line extractColumnReverse(int i);

    void updateLeft();
    void updateRight();
    void updateUp();
    void updateDown();
    void addRandom();
    void printGrid();
    void runGame();
};

#endif // GRID_H
