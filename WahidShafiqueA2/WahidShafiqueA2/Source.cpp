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
	shuffle(); //TEST SHUFFLE 
	for (int c = 0; c < DECKSIZE; c++) {
		cout << deck[c] << endl;  // Just print number
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

void RankDeck::dealNextCard() {

}

//WARGAME

WarGame::WarGame(int max):maxNumGames(max) {
	//cout << maxNumGames;
}

void WarGame::battle() {

}