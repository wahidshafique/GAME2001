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

public:
	int battlesWaged = 0;
	int totalBattlesWaged = 0;
	WarGame(int);
	bool play();
	bool battle(Queue <int> &player1, Queue <int> &player, Queue <int> &prizePile, int batts);
	~WarGame() {
	}
};
