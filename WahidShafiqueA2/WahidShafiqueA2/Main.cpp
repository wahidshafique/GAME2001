#include "Header.h"
#include <iostream>
int main() {
	int gameToSim;
	int maxBattles;
	cout << "How many games should be simulated?: "; cin >> gameToSim; cout << endl;
	cout << "What is the maximum number of battles per game?: "; cin >> maxBattles; cout << endl;

	cout << "Number of games simulated: ";
	cout << "Number of discontinued games: ";
	cout << "Number of completed games: ";

	WarGame game(6);
	game.play();


}