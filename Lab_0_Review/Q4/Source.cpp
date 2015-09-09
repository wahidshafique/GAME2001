//Pig Latin converter
#include <iostream>
#include <string>

using namespace std;

string pigLatin(string word) {
	const string vowels = "aeiou";
	int split = 1;
	string output = word;
	for (int i = 0; i < vowels.length(); i++) {
		if (word.at(0) == vowels[i]) {
			output += "way";
			return output;
		} else if (word.at(0) == 'q') {
			split = 2;
			break;
		}
	}
	output = word.substr(split, word.length());
	output += word.substr(0, split);
	output += "ay";
	return output;
}

int main() {
	string word;
	bool active = true;
	do {
		cout << "Enter in a word to convert to pig latin, x to end: ";
		cin >> word;
		if (word == "x") active = false;
			else cout << "We get: " << pigLatin(word) << endl;
	} while (active);
	return 0;
}