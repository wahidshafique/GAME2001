//Write a function that swaps two integer values using pointers.
#include <iostream>

using namespace std;

void pointSwap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

int main() {
	int a = 100;
	int b = 9;
	cout << "a = " << a << ", b = " << b << endl
		<< "swapped by using pointers: " << endl;
	pointSwap(&a, &b);
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}