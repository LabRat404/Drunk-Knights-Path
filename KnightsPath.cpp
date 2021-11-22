#include <iostream>
#include "KnightsPath.h"
using namespace std;
//1155144676 Yeung Tang 1155144676@link.cuhk.edu.hk  

KnightsPath::KnightsPath(int r, int c) {
	currentR = r; //initializing the Row
	currentC = c; //initializing the Column
	for(int x=0; x<N; x++) //initializing the board
		for (int y = 0; y < N; y++) 
			board[x][y] = -1;
	steps = 0;
	board[r][c] = steps; //set start point 
	previousR = previousC = -1;
}

void KnightsPath::print()const{
	
	for (int x = 0; x <= N; x++) { //2 for loop to print every elements inside the board
		for (int y = 0; y <= N; y++) {
			(x == 0 && y == 0) ? (cout << " ") : (x == 0 && y != 0) ? (cout << "  " << char(y - 1 + 'A')) : (x != 0 && y == 0) ? (cout << x - 1) : (board[x - 1][y - 1] == -1) ? (cout << "  .") : (board[x - 1][y - 1] == 0) ? (cout << "  k") : (board[x - 1][y - 1] == steps) ? (cout << "  K") : (board[x - 1][y - 1] > 9) ? (cout << " " << board[x - 1][y - 1]) : (cout << "  " << board[x - 1][y - 1]);

		}
		cout << "\n";
	}
	cout << "Steps: " << steps << "\n";
}

int KnightsPath::getSteps()const{
	return steps; //returns the value of step
}

bool KnightsPath::isValid(int r, int c)const{ //check if the input r and c is valid by checking proper position, unvisited square 2h1v 1v2h and not a back diraction
	bool istrue  = false;
	((r < N&& r >= 0) && (c < N&& c >= 0) && board[r][c]==-1 && (pow((currentR - r), 2) + pow((currentC - c), 2)) == 5) && (((pow((previousR - r), 2) + pow((previousC - c), 2)) > 4) || previousR == -1) ? (istrue = true) : (istrue = false);
	return istrue;
}

bool KnightsPath::hasMoreMoves() const{
	//2 for loops for looping is there a valid location for another input r and c
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			if (isValid(x, y) == true)
				return true;
	return false;
}

bool KnightsPath::move(int r, int c) {
	//updates the new board grid informations
	if (isValid(r, c)) {
		steps++;
		previousR = currentR;
		previousC = currentC;
		currentR = r;
		currentC = c;
		board[currentR][currentC] = steps;
		return true;
	}
	return false;
}
