#pragma once
#include <vector>
#include "Queue.h"
using namespace std;
const int DECKSIZE = 52;

class RankDeck {
	bool anyCardsLeft = true;
	//container for the cards is vector for shuffling/deal purposes and flexibility 
	vector <int> deck;

public:
	RankDeck();
	void shuffle();
	void dealNextCard(Queue<int> *x, Queue<int> *y);
	bool cardsLeft() { return anyCardsLeft; }
};

class WarGame {
	int maxNumGames;
	int battlesWaged;

public:
	WarGame(int);
	bool play();
	void battle(Queue <int> *x, Queue<int> *y, Queue<int> *prz);
	~WarGame() {

	}
	//int battlesWaged();
};
