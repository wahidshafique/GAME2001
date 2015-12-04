#pragma once
#include <vector>
#include "Queue.h"
using namespace std;
const int DECKSIZE = 52;

class RankDeck {
	bool anyCardsLeft;
	//container for the cards is vector for shuffling/deal purposes and flexibility
	vector <int> deck;

protected:
	int cardPos = 0;

public:


	RankDeck();
	void shuffle();
	int dealNextCard();
	bool cardsLeft();
};

class WarGame {
	Queue <int> *player1;//each player starts with a hand of 26 cards
	Queue <int> *player2;
	Queue <int> *prizePile;
	int maxNumGames;
	int battlesWaged;
	bool gameOver;

	RankDeck warDeck;

public:
	WarGame(int);
	bool play();
	void battle();
	//void battle(Queue <int> *x, Queue<int> *y, Queue<int> *prz);
	~WarGame() {
		delete player1, player2, prizePile, warDeck;
	}
	//int battlesWaged();
};
