#include "Header.h"
#include <iostream>
#include <time.h>

//RANK DECK

RankDeck::RankDeck() {
	//there are 13 ranks, and 4 suits, suits are arbitrary for this version of war
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			static int index = 0;
			deck.push_back(j);
			index++;
		}
	}
};

void RankDeck::shuffle() {
	srand(time(NULL));
	for (int i = 0; i < DECKSIZE; i++) {
		int r = rand() % DECKSIZE;
		int temp = deck[i];
		deck[i] = deck[r];
		deck[r] = temp;
	}
}

void RankDeck::dealNextCard(Queue<int> *p1, Queue<int> *p2) {
	while (!deck.empty()) {
		p1->push(deck.back());
		deck.pop_back();
		p2->push(deck.back());
		deck.pop_back();

		cout << p1->back() << endl;
		cout << p2->back() << endl;
	}
}
//WARGAME

WarGame::WarGame(int max) : maxNumGames(max) {
	//cout << maxNumGames;
}

bool WarGame::play() {
	Queue <int> player1(DECKSIZE / 2);
	Queue <int> player2(DECKSIZE / 2);
	Queue <int> prizePile(DECKSIZE);

	RankDeck deck;
	deck.shuffle();
	deck.dealNextCard(&player1, &player2);
	
	battle(&player1, &player2, &prizePile);
	//cout << player2.back();
	
	return true;
}

void WarGame::battle(Queue <int> *p1, Queue<int> *p2, Queue<int> *prz) {
	if ((p1->front()) > (p2->front())) {
		p1->push(p2->front());
		p1->push(p1->front());
	}
	
	cout << p1->front() <<endl;
	p1->pop();
	cout << p1->front();

}