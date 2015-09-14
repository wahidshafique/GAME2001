#include <iostream>
using namespace std;

template <class T>

T mid(T val1, T val2, T val3) {
	if (val2 <= val1 && val1 <= val3)
		return val1;
	if (val1 <= val2 && val2 <= val3)
		return val2;
	if (val1 <= val3 && val3 <= val2)
		return val3;
}

int main() {
	cout << mid(1, 2, 3) << endl;
	cout << mid(900, 1400, 33) << endl;
	cout << mid(1.6, 200.8, 13.9) << endl;
}