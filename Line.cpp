#include"Line.h"
/*
	Initializes a vector of size n, with all values set to 0.
	@param n Size of the line.
*/
Line::Line(int n) : line(n, 0) {};

/*
	Updates the line according to rules of the 2048 game.
	Merge equal numbers that are next to each other, by replacing the
	number on the left with the double of the value, and replace the
	number on the left with 0.
	Shift all number to the left,places zero to the empty spaces.
*/

	void Line::update()
	{
		int n = line.size();
		int var = -1;			// Last number that was seen
		int j = -1;				// The index of the last non-zero number

		// Merge the adjecent values that are the same.
		for (int i = 0; i < n; i++)
		{
			if (line[i] == 0)
			{
				continue;
			}
			if (var == -1 || var != line[i])
			{
				var = line[i];
				j = i;
			}
			else
			{
				line[j] *= 2;	// Double the value
				line[i] = 0;	// Set the number on the left to 0.
				var = -1;		// Reset the tracker.
			}
		}
		// Shift all non-zero values to the left.
		int position = 0;
		for (int i = 0; i < n; i++)
		{
			if (line[i] != 0)
			{
				line[position] = line[i];
				if (position != i)
				{
					line[i] = 0;	// Empty the position.
				}
				position++;
			}
		}
	}

