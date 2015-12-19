#include <iostream>
#include <string>
using namespace std;

bool isPalRecur(string pal) {
	if (pal.length() == 0) {
		return true;
	}
	if (!(pal[0] == pal[pal.length() - 1])) {
		return false;
	}
	pal.erase(pal.end() - 1);
	pal.erase(pal.begin());
	return isPalRecur(pal);
}

bool isPalIter(string pal) {
	int i = 0; 
	int j = pal.length() - 1;
	while (pal[i] != pal[j]) {
		for (; i < pal.length() - 1; i++) {
			for (; j > 0; j--) {
				if (pal[i] != pal[j]) return false;
			}
		}
	}
	return true;
}

int main() {
	string text;
	cin >> text;

	cout << "\nrecursively\n" << endl;

	isPalRecur(text) ? cout << "is a palindrome" << endl : cout << "is not a palindrome" << endl;

	cout << "\niteratively\n" << endl;

	isPalIter(text) ? cout << "is a palindrome" << endl : cout << "is not a palindrome" << endl;
}