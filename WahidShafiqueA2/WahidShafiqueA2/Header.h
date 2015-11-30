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
	void dealNextCard();
	bool cardsLeft() { return anyCardsLeft; }
};

class WarGame {
	int maxNumGames;
public:
	WarGame(int);

	void battle();

	bool play() {
		//The play method, when invoked, must create three queues, two for each
		//player’s hand, and one for the prize pile of cards.
		//RankDeck player1Deck(26);
		//RankDeck player2Deck(26);
		//RankDeck prizePile(1);
		return true;
	}

	int battlesWaged() {

	}
};
