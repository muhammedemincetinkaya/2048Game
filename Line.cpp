#include"Line.h"
Line::Line(int n) : line(n, 0) {};

	void Line::update()
	{
		int n = line.size();
		int var = -1;
		int j = -1;

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
				line[j] *= 2;
				line[i] = 0;
				var = -1;
			}
		}
		int position = 0;
		for (int i = 0; i < n; i++)
		{
			if (line[i] != 0)
			{
				line[position] = line[i];
				if (position != i)
				{
					line[i] = 0;
				}
				position++;
			}
		}
	}

