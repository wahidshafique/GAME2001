#include <iostream>
#include <cstdlib>    
#include <ctime>
#include <string>
#include "BitArray.h"
using namespace std;

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

void markBlob(BitArray &grid, BitArray &visited, unsigned int rows, unsigned int cols, unsigned int row, unsigned int col) {
	unsigned int gridIndexer = col + (row * cols);

	if (!visited[gridIndexer] && grid[gridIndexer]) {
		visited.SetBit(gridIndexer);

		if (row > 0 && grid[gridIndexer - cols]) {
			markBlob(grid, visited, rows, cols, row - 1, col);
		}
		if (row + 1 < rows && grid[gridIndexer + cols]) {
			markBlob(grid, visited, rows, cols, row + 1, col);
		}
		if (col > 0 && grid[gridIndexer - 1]) {
			markBlob(grid, visited, rows, cols, row, col - 1);
		}
		if (col + 1 < cols && grid[gridIndexer + 1]) {
			markBlob(grid, visited, rows, cols, row, col + 1);
		}
	}
}

int blobCount(BitArray &grid, BitArray &visited, unsigned int rows, unsigned int cols) {
	int counter = 0;
	visited.ClearAllBits();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[j + (i * cols)] && !visited[j + (i * cols)]) {
				counter++;
				markBlob(grid, visited, rows, cols, i, j);
			}
		}
	}
	return counter;
}

int main() {
	int rows;
	int cols;
	int percent;
	string welcome = "Blob Counter By: Wahid Shafique";

	cout << welcome << endl;
	cout << string(welcome.length(), '*') << endl;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of cols: ";
	cin >> cols;
	cout << "Enter blob percentage: ";
	cin >> percent;

	if ((rows * cols) != 0) {
		BitArray grid = genGrid(rows, cols, percent);
		BitArray visited = genGrid(rows, cols, 0);
		cout << gridView(grid, rows, cols) << endl;
		cout << blobCount(grid, visited, rows, cols) << endl;
	}
}