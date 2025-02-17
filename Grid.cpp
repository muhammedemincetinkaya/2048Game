#include"Grid.h"
#include<iostream>
#include"cstdlib"

/*
	* Initializes a n x n grid filled with zeros and placaes a 2 in the top left corner.
	* @param n The size of the grid
*/

Grid::Grid(int n) : grid(n,std::vector<int>(n,0))
{
	grid[0][0] = 2;
}

/*
	* Extracts a row as a Line object
	* @param i Index of the row.
	* @return Line containing the values of the row.
*/


	Line Grid::extractRow(int i)
	{
		int n = grid.size();
		Line l(n);
		for (int k = 0; k < n; k++)
		{
			l.line[k] = grid[i][k];
		}
		return l;
	}

/*
	* Extract a row in reverse order.
	* @param i Index of the row.
	* @return Line containing the values of the row in reverse order.
*/
	Line Grid::extractRowReverse(int i)
	{
		int n = grid.size();
		Line l(n);
		for (int k = 0; k < n; k++)
		{
			l.line[k] = grid[i][n - k - 1];
		}
		return l;
	}

/*
	* Extract a column as a Line object.
	* @param i Index of the row.
	* @return Line containing the values of the column.
*/
	Line Grid::extractColumn(int i)
	{
		int n = grid.size();
		Line l(n);
		for (int k = 0; k < n; k++)
		{
			l.line[k] = grid[k][i];
		}
		return l;
	}

/*
	* Extract a column in reverse order.
	* @param i Index of the row.
	* @return Line containing the values of the column in reverse.
*/
	Line Grid::extractColumnReverse(int i)
	{
		int n = grid.size();
		Line l(n);
		for (int k = 0; k < n; k++)
		{
			l.line[k] = grid[n - k - 1][i];
		}
		return l;
	}

/*
	* Methods to update the grid based on the player's input. 
*/
	void Grid::updateLeft()
	{
		int n = grid.size();
		for (int i = 0; i < n; i++)
		{
			Line l = extractRow(i);
			l.update();
			for (int k = 0; k < n; k++)
			{
				grid[i][k] = l.line[k];
			}
		}
		addRandom();
	}
	void Grid::updateRight()
	{
		int n = grid.size();
		for (int i = 0; i < n; i++)
		{
			Line l = extractRowReverse(i);
			l.update();
			for (int k = 0; k < n; k++)
			{
				grid[i][k] = l.line[n - k - 1];
			}

		}
		addRandom();
	}
	void Grid::updateUp()
	{
		int n = grid.size();
		for (int i = 0; i < n; i++)
		{
			Line l = extractColumn(i);
			l.update();
			for (int k = 0; k < n; k++)
			{
				grid[k][i] = l.line[k];
			}
		}
		addRandom();
	}
	void Grid::updateDown()
	{
		int n = grid.size();
		for (int i = 0; i < n; i++)
		{
			Line l = extractColumnReverse(i);
			l.update();
			for (int k = 0; k < n; k++)
			{
				grid[k][i] = l.line[n - k - 1];
			}
		}
		addRandom();
	}

/*
	* Adds a new 2 at a random empty position in the grid. 
*/
	void Grid::addRandom()
	{
		int n = grid.size();
		int numberOfZero = 0;
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				if (grid[i][k] == 0)
				{
					numberOfZero++;
				}
			}
			if (numberOfZero == 0)
			{
				return;
			}
			int r = rand() % numberOfZero + 1;
			int counter = 0;
			for (int i = 0; i < n; i++)
			{
				for (int k = 0; k < n; k++)
				{
					if (grid[i][k] == 0)
					{
						counter++;
						if (counter == r)
						{
							grid[i][k] = 2;
							return;
						}
					}
				}
			}
		}
	}

/*
	* Prints the grid out to the console. 
*/
	void Grid::printGrid()
	{
		for (const auto& row : grid)
		{
			std::cout << "\n";
			for (int cell : row)
			{
				std::cout  << cell << "\t";
			}
			std::cout << "\n";
		}
	}

/*
	* Runs the game, allowing the player to make moves. 
*/
	void Grid::runGame()
	{
		char move;
		while (true)
		{
			printGrid();
			std::cout << "Enter a move";
			std::cin >> move;
			if (move == 'q')
			{
				break;
			}
			switch (move)
			{
			case'w':
				updateUp(); break;
			case's':
				updateDown(); break;
			case'a':
				updateLeft(); break;
			case'd':
				updateRight(); break;
			default:
				std::cout << "Invalid move, try again";

			}
		}
	}
	int main()
	{
		int gameSize = 4;
		Grid game(gameSize);
		std::cout << "Welcome to the game";
		game.runGame();
		std::cout << "Game Over";
		return 0;
	}
