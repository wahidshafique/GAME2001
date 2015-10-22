#include <iostream>
#include <cstdlib>    
#include <ctime>
#include <string>
#include "BitArray.h"
using namespace std;
/*(4 points) Create a function called genGrid with the following signature:
BitArray genGrid(unsigned int rows, unsigned int cols, unsigned int percentage)
that generates a grid, where each pixel belongs to a blob based on a random
number generated in the range 1 to 100: if the random number is less than the
percentage, the pixel belongs to some blob (that is you set the corresponding
bit to 1); otherwise the pixel does not belong to the blob (that is you set the
corresponding bit to 0).
*/
BitArray genGrid(unsigned int rows, unsigned int cols, unsigned int percentage) {
	unsigned int gridLen = rows * cols;
	BitArray grid(gridLen);
	srand((unsigned int)time(NULL));
	unsigned int randNum;
	grid.ClearAllBits();
	for (unsigned int i = 0; i < gridLen; i++) {
		randNum = rand() % 100 + 1;
		(randNum < percentage) ? grid.SetBit(i) : grid.ClearBit(i);
	}
	return grid;
}

/*(4 Points) Create a function gridView with the following signature:
string gridView(BitArray &grid, unsigned int rows, unsigned int cols)
that produces a string representation of the grid in a form similar to that shown
on the image above.
*/
string gridView(BitArray &grid, unsigned int rows, unsigned int cols) {
	string gridString;

	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int k = 0; k < cols; k++) {
			static unsigned int index = 0;
			(grid[index] == 1) ? gridString.append("X") : gridString.append("-");
			index++;
		}
		gridString.append("\n");
	}
	return gridString;
}

/*(10 Points) The marking of pixels belonging to blobs must be done using a
recursive function with the following signature:
void markBlob(BitArray &grid, BitArray &visited, unsinged int rows,
unsigned int cols,unsigned int row, unsigned int col)
where row, col is the particular pixel that is being visited at this time.
*/
void markBlob(BitArray &grid, BitArray &visited, unsigned int rows, unsigned int cols, unsigned int row, unsigned int col) {
	unsigned int  gridLen = rows * cols;
	unsigned int  gridIndexer = row + (col * cols);
	visited.SetAllBits();
	if ((row - 1) >= 0) {
		if (grid[(row - 1) + (col * cols)]) {
			if (!visited[(row - 1) + (col * cols)]) {
				markBlob(grid, visited, rows, cols, row - 1, col);
			}
		}
	}

	if ((row + 1) < rows) {
		if (grid[((row + 1) + (col * cols))]) {
			if (!visited[(row + 1) + (col * cols)]) {
				markBlob(grid, visited, rows, cols, row + 1, col);
			}
		}
	}
	if ((col - 1) >= 0) {
		if (grid[(row)+((col - 1) * cols)]) {
			if (!visited[row + ((col - 1) * cols)]) {
				markBlob(grid, visited, rows, cols, row, col - 1);
			}
		}
	}
	if ((col + 1) < cols) {
		if (grid[(row)+((col + 1) * cols)]) {
			if (!visited[(row)+((col + 1) * cols)]) {
				markBlob(grid, visited, rows, cols, row, col + 1);
			}
		}
	}
}
/*
go through the array starting from 1:1 down to the max column and row

if '1'
then check if all 4 sides of it has another X
(n:n) -> (n:n+1), (n:n-1), (n+1:n), (n-1:n)

return
*/


/*(8 Points) In order to count the blobs, you will create a function with the
following signature:
2
GAME2001 Fall 2015
int blobCount(BitArray &grid, BitArray visited,
unsigned int rows, unsigned int cols)
where grid is the representation of the image, and visited keeps track of the
fact if your counting function has ever visited a particular element of the grid.
Note if you mark a pixel as visited, you want to check the neighbor pixels and
amrk them as well if they belong to the same blob.
*/
int blobCount(BitArray &grid, BitArray visited, unsigned int rows, unsigned int cols) {
	unsigned int gridLen = rows * cols;
	int counter = 0;
	visited.ClearAllBits();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i + (j * cols)] && !visited[i + (j * cols)]) {
				counter++;
				markBlob(grid, visited, rows, cols, i, j);
			}
		}
	}
	return counter;
}

int main() {
	//int rows; 
	//int cols; 
	//int percent; 
	//bool run = 1;
	//while (run) {
	//	cout << "Enter number of rows" << endl;
	//	cin >> rows; 
	//	cout << "Enter number of cols" << endl;
	//	cin >> cols;
	//	cout << "Enter blob percentage" << endl;
	//	cin >> percent;

	//	BitArray grid = genGrid(rows, cols, percent);
	//	cout << gridView(grid, rows, cols) << endl;
	//	cout << blobCount(grid, grid, rows, cols) << endl;

	//	cout << "Continue? Enter 1 for YES / 0 for NO : ";
	//	cin >> run;
	//}
	BitArray grid = genGrid(7, 4, 40);
	cout << gridView(grid, 7, 4) << endl;
	cout << blobCount(grid, grid, 7, 4) << endl;
}