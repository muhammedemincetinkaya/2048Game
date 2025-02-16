#include"Grid.h"
#include<iostream>
#include"cstdlib"

Grid::Grid(int n) : grid(n,std::vector<int>(n,0))
{
	grid[0][0] = 2;
}


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
	void Grid::printGrid()
	{
		for (const auto& row : grid)
		{
			for (int cell : row)
			{
				std::cout << cell << "\t";
			}
			std::cout << "\n";
		}
	}
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
