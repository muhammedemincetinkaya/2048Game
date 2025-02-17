#ifndef LINE_H
#define LINE_H
#include<vector>

/*
	 The line class represents a single row or column in the game.
	 It has methods to update the numbers in the rows/colums according to the rules.
*/

class Line
{
public:
	std::vector<int> line;	//Stores the numbers in the rows/columns
	/*
		Constructor initializes a Line with n empty spaces.
		@param n Size of the line.
	*/
	Line(int n);
	void update();
};
#endif // !LİNE_H
