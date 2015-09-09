#include <iostream>

using namespace std;

void refSwap(int &a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}

int main() {
	int a = 100;
	int b = 9;
	cout << "a = " << a << ", b = " << b << endl
		<< "swapped by reference: " << endl;
	refSwap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}