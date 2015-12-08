#pragma once
#include <vector>
#include "Queue.h"
using namespace std;
const int DECKSIZE = 52;

class RankDeck {
	bool anyCardsLeft = true;
	vector <int> deck;
public:
	RankDeck();
	void shuffle();
	void dealNextCard(Queue<int> *x, Queue<int> *y);
	bool cardsLeft() { return anyCardsLeft; }
};

class WarGame {
	int maxBattles;

	Queue <int> player1 = Queue<int>(DECKSIZE);
	Queue <int> player2 = Queue<int>(DECKSIZE);
	Queue <int> prizePile = Queue<int>(DECKSIZE);
public:
	int battlesWaged = 0;
	int totalBattlesWaged = 0;
	WarGame(int);
	bool play();
	bool battle();
	~WarGame() {
	}
};
