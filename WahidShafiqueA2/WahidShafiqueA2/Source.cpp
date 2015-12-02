#include "Header.h"
#include <iostream>
#include <time.h>
#include <fstream> //diagnostic 

//RANK DECK
RankDeck::RankDeck() {//here we are simply populating the dealer deck
	//there are 13 ranks, and 4 suits, suits are arbitrary for this version of war
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			static int index = 0;
			deck.push_back(j);
			index++;
		}
	}
};

void RankDeck::shuffle() {//shuffle the dealer deck
	srand(time(NULL));
	for (int i = 0; i < DECKSIZE; i++) {
		int r = rand() % DECKSIZE;
		int temp = deck[i];
		deck[i] = deck[r];
		deck[r] = temp;
	}
}

void RankDeck::dealNextCard(Queue<int> *p1, Queue<int> *p2) {//from the dealer deck, evenly divvy out the cards
	ofstream myfile;
	myfile.open("playerHandContents.txt");
	while (!deck.empty()) {
		//push all the cards to the back of the players respective hand
		p1->push(deck.back());
		deck.pop_back();
		p2->push(deck.back());
		deck.pop_back();


		myfile << "the contents of the p1 hand is" << endl;
		myfile << p1->back() << endl;
		myfile << "the contents of the p2 hand is" << endl;
		myfile << p2->back() << endl;
	}
	myfile.close();
}

//WARGAME
WarGame::WarGame(int max) : maxNumGames(max) {
	//cout << maxNumGames;
}

bool WarGame::play() {
	Queue <int> player1(DECKSIZE / 2);//each player starts with a hand of 26 cards
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
	static int turns = 0;
	turns += 1;
	//POP IS POP FRONT HERE
	//Get player1’s card from player1’s hand and put in prize pile
	int p1CardTop = p1->front();
	prz->push(p1CardTop);
	//Get player2’s card from player2’s hand and put in prize pile
	int p2CardTop = p2->front();
	prz->push(p2CardTop);

	if (p1CardTop > p2CardTop) {
		/*Whoever has the higher of the two cards wins the battle prize(the two cards) and places those
		cards at the bottom of their hands.*/
		cout << "p1 won on turn" << turns << endl;
		//now put the prize pile in the back of p1's hand
		while (!prz->isEmpty()) {
			p1->push(prz->front());
			prz->pop();
		}
		p1->pop();
		p2->pop();
		/*p1->push(p2->front());//push p2's played card to the bottom of your deck
		p2->pop();//remove that card from p2 front NOTE: pop is Pop_Front()

		p1->push(p1->front());//place own(p1) played card to the bottom
		p1->pop();//remove that card from p1 front*/
		this->battle(p1, p2, prz);
	} else if (p1CardTop < p2CardTop) {
		cout << "p2 won on turn" << turns << endl;
		while (!prz->isEmpty()) {
			p2->push(prz->front());
			prz->pop();
		}
		p1->pop();
		p2->pop();
		/*
		p2->push(p1->front());
		p1->pop();

		p2->push(p2->front());
		p2->pop();*/
		this->battle(p1, p2, prz);
	} else {
		//WAR
		cout << "TIE" << endl;

		for (int i = 0; i < 3; i++) {//in addition to keeping the 2 dealt cards, each p places 3 more from their hands -> 2 + 6
			prz->push(p1CardTop);
			prz->push(p2CardTop);
			p1->pop();//removing the recently pushed cards
			p2->pop();
		}
		p1->pop();//removing the dealt cards from both players hands
		p2->pop();
		this->battle(p1, p2, prz);//have another battle for a possible of 10 cards dealt to winner

		/*for (int i = 0; i < 3; ++i) { //push 3 cards from each players hand to prize pile
			prz->push(p1->front());
			p1->pop();

			prz->push(p2->front());
			p2->pop();
		}*/
	}

}
