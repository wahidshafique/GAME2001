#include "Header.h"
#include <iostream>
#include <time.h>

RankDeck::RankDeck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			static int index = 0;
			deck.push_back(j);
			index++;
		}
	}
};

void RankDeck::shuffle() {
	//srand(time(NULL));
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

WarGame::WarGame(int max) : maxBattles(max) {
	battlesWaged = 0;
	totalBattlesWaged = 0;
}

bool WarGame::play() {
	Queue <int> player1(26);
	Queue <int> player2(26);
	Queue <int> prizePile(52);
	RankDeck deck;
	deck.shuffle();
	deck.dealNextCard(&player1, &player2);
	return battle(player1, player2, prizePile, maxBattles);
}
bool WarGame::battle(Queue <int> &player1, Queue <int> &player2, Queue <int> &prizePile, int batts) {
	if (!player1.isEmpty() && !player2.isEmpty()) {
		totalBattlesWaged++;
		int p1CardTop = player1.front();
		prizePile.push(p1CardTop);
		int p2CardTop = player2.front();
		prizePile.push(p2CardTop);

		if (p1CardTop > p2CardTop) {
			player1.pop();
			player2.pop();
			while (!prizePile.isEmpty()) {
				player1.push(prizePile.front());
				prizePile.pop();
			}
			batts--;
			if (batts == 0)
				return false;
			else return battle(player1, player2, prizePile, batts);

		} else if (p1CardTop < p2CardTop) {

			player1.pop();
			player2.pop();
			while (!prizePile.isEmpty()) {
				player2.push(prizePile.front());
				prizePile.pop();
			}
			batts--;
			if (batts == 0)
				return false;
			else return battle(player1, player2, prizePile, batts);
		} else {
			player1.pop();
			player2.pop();
			for (int i = 0; i < 3; i++) {
				if (!player1.isEmpty() && !player2.isEmpty()) {
					prizePile.push(p1CardTop);
					prizePile.push(p2CardTop);
					player1.pop();
					player2.pop();
				} else return true;
			}
			if (batts == 0)
				return false;
			else return battle(player1, player2, prizePile, batts);
		}
	} else {
		totalBattlesWaged += battlesWaged;
		battlesWaged = 0;
		return true;
	}
}
