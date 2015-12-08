#include "Header.h"
#include <time.h>
#include <iostream>
int main() {
	srand(time(NULL));
	int gameToSim;
	int maxBattles;
	cout << "How many games should be simulated?: "; cin >> gameToSim; cout << endl;
	cout << "What is the maximum number of battles per game?: "; cin >> maxBattles; cout << endl;

	int gameSimulated = 0;
	int discontinued = 0;
	int completed = 0;
	WarGame game(maxBattles);
	for (int i = 0; i < gameToSim; i++) {
		gameSimulated++;
		game.play() ? completed++ : discontinued++;
	}
	cout << "Number of games simulated: " << gameSimulated << endl;
	cout << "Number of discontinued games: " << discontinued << endl;
	cout << "Number of completed games: " << completed << endl << endl;

	cout << "In the completed games: " << endl;
	cout << "Total number of battles: " << game.totalBattlesWaged << endl;
	(completed != 0) ? cout << "Average number of battles: " << game.totalBattlesWaged / completed << endl :
		cout << "Average number of battles: " << game.totalBattlesWaged << endl;
	cout << "Program Completed" << endl;
}