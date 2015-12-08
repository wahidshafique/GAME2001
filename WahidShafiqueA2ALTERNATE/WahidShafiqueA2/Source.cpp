#include "Header.h"
#include <iostream>
#include <time.h>

//RANK DECK
RankDeck::RankDeck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			static int index = 0;
			deck.push_back(j);
			index++;
		}
	}
	cardPos = 0;
};

bool RankDeck::cardsLeft() {
	return (cardPos != DECKSIZE);
}

void RankDeck::shuffle() {
	srand(time(NULL));
	for (int i = 0; i < DECKSIZE; i++) {
		int r = rand() % DECKSIZE;
		int temp = deck[i];
		deck[i] = deck[r];
		deck[r] = temp;
	}
}

int RankDeck::dealNextCard() {
	while (!deck.empty()) {
		cardPos += 1;
		return (deck[cardPos - 1]);
	}
}

//WARGAME
WarGame::WarGame(int max) : maxNumGames(max) {
}

bool WarGame::play() {
	Queue<int> *player1 = new Queue <int>(DECKSIZE);//each player starts with a hand of 26 cards
	Queue <int> *player2 = new Queue <int>(DECKSIZE);
	Queue <int> *prizePile = new Queue <int>(DECKSIZE);


	warDeck.shuffle();
	while (warDeck.cardsLeft())
	{
		player1->push(warDeck.dealNextCard());
		if (warDeck.cardsLeft()) {
			player2->push(warDeck.dealNextCard());
		}
	}

	while (!gameOver) {
		try {
			battle();
		} catch (...) { gameOver = true;}
	}
	return gameOver;
}

void WarGame::battle() {
	int Cardp1 = player1->front();
	prizePile->push(Cardp1);
	player1->pop();
	int Cardp2 = player2->front();
	prizePile->push(Cardp2);
	player2->pop();

	if (Cardp1 > Cardp2) {
		while (!prizePile->isEmpty()) {
			player1->push(prizePile->front());
			prizePile->pop();
		}
	} else if (Cardp1 < Cardp2) {
		while (!prizePile->isEmpty()) {
			player2->push(prizePile->front());
			prizePile->pop();
		}
	} else {
		for (int i = 0; i < 3; ++i)
		{
			prizePile->push(Cardp1);
			player1->pop();
			prizePile->push(Cardp2);
			player2->pop();
		}
		battle();
	}
}