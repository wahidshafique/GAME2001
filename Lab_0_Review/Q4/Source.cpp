//Pig Latin converter
#include <iostream>
#include <string>

using namespace std;

string pigLatin(string word) {
	const string vowels = "aeiou";
	string output = word;
	for (int i = 0; i < vowels.length(); i++) {
		if (word.at(0) == vowels[i]) {
			output += "way";
			return output;
		}
	}
	output = word.substr(1, word.length());
	output += word.at(0);
	output += "ay";

	return output;
}

int main() {
	string word;
	bool active = true;
	do {
		cout << "Enter in a word to convert to pig latin, x to end: ";
		cin >> word;
		if (word == "x") {
			active = false;
		} else {
			cout << "We get: " << pigLatin(word) << endl;
		}
	} while (active);

	return 0;
}