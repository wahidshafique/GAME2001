#include <time.h>
#include <iostream>
using namespace std;

const int n = 500;
float TestData[n][n][n];

double diffclock(clock_t clock1, clock_t clock2) {
	double diffticks = clock1 - clock2;
	double diffms = (diffticks / 10) / CLOCKS_PER_SEC;
	return diffms;
}

void column_ordered() {

	for (int k = 0; k < n; k++)
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				TestData[i][j][k] = 0;
}

void row_ordered() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				TestData[i][j][k] = 0;
}

int main(){
	clock_t begin = clock();
	row_ordered();
	clock_t end = clock();
	cout << "Time elapsed (row): " << diffclock(end, begin) << " ms" << endl;
	
	begin = clock();
	column_ordered();
	end = clock();
	cout << "Time elapsed (row): " << diffclock(end, begin) << " ms" << endl;

	return 0;
}
