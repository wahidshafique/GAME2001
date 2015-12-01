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
	static int games = 0;
	cout << games;
	if (!p1->isEmpty() || !p2->isEmpty()) {
		games += 1;
		if ((p1->front()) > (p2->front())) {
			p1->push(p2->front());//push p2's played card to the bottom of your deck
			p2->pop();//remove that card from p2 front NOTE: pop is Pop_Front()

			p1->push(p1->front());//place own(p1) played card to the bottom
			p1->pop();//remove that card from p1 front

			battle(p1, p2, prz);

		} else if ((p1->front()) < (p2->front())) {
			p2->push(p1->front());
			p1->pop();

			p2->push(p2->front());
			p2->pop();
			battle(p1, p2, prz);
		} else {
			//WAR
		}

	}
}