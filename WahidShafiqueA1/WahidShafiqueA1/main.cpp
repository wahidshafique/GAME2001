#include <iostream>
#include <cstdlib>    
#include <ctime>
#include "BitArray.h"
using namespace std;

BitArray genGrid(unsigned int rows, unsigned int cols, unsigned int percentage) {
	BitArray grid(rows * cols);
	srand(time(NULL));
	int randNum;
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < cols; k++) {
			randNum = rand() % 100 + 1;
			static int index = 0;
			(randNum < percentage) ? grid.SetBit(index) : grid.SetBit(!index);

			cout << grid[index];
			index++;
		}
		cout << endl;
	}
	cout << grid[4 % cols];//test index
	return grid;
}


string gridView(BitArray &grid, unsigned int rows, unsigned int cols) {
	return 0;
}

int blobCount(BitArray &grid, BitArray visited, unsigned int rows, unsigned int cols) {
	return 0;
}

void markBlob(BitArray &grid, BitArray &visited, unsigned int rows, unsigned int cols) {


	/*
	go through the array starting from 1:1 down to the max column and row

	if 'X'
		then check if all 4 sides of it has another X
		(n:n) -> (n:n+1), (n:n-1), (n+1:n), (n-1:n)

		return
		*/
}

int main() {
	BitArray grid = genGrid(5, 6, 30);
}